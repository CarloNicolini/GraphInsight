'''
/****************************************************************************
**
** Copyright (C) 2012 Carlo Nicolini (nicolini.carlo@gmail.com)
** All rights reserved.
**
** Warning: This program is protected by copyright law and international
** treaties. Unauthorized reproduction and distribution of this program,
** or any portion of it, may result in severe civil and criminal penalties,
** and will be persecuted to the maximum extent possible under the law.
**
****************************************************************************/
'''

from libcpp.vector cimport vector
from libcpp.set cimport set
from libcpp.map cimport map
from libcpp.string cimport string
from libcpp.pair cimport pair
from libcpp cimport bool
from cython.operator cimport dereference as deref, preincrement as preinc, postincrement as postincr

# Import Regular expressions
import sys
import re
import signal, os
import shlex # to lexical parsing of Pajek files

##########################################################################
###Typedefs for handling pairs of pointers (namely Neighbors )###########
##########################################################################
ctypedef Node* NodePtr
ctypedef Edge* EdgePtr
# This trick is needed to avoid compiler crash, substituted EdgePtr with void*
ctypedef pair[void*,Node*]* Neighbor
#ctypedef pair[EdgePtr,NodePtr]* Neighbor

#####################################
####### STD VECTOR TO CYTHON ########
#####################################
cdef extern from "<vector>" namespace "std":
    cdef cppclass vector[T]:
        cppclass iterator:
            T operator*()
            iterator operator++()
            bint operator==(iterator)
            bint operator!=(iterator)
        vector()
        void push_back(T&)
        T& operator[](int)
        T& at(int)
        iterator begin()
        iterator end()


#####################################
##### Edge implementation ##########
#####################################
cdef extern from "Edge.h":
    cdef cppclass Edge:
        Edge() except +
        Edge( double weight) except +
        double weight
        bool mark

cdef class wrapperEdge:
    cdef Edge *thisptr      # hold a C++ instance which we're wrapping

    def __cinit__(self, weight=None):
        if weight is not None:
            if type(weight) is not float and type(weight) is not int:
                raise Exception(":::: Weight of edges must be numeric!")
            self.thisptr = new Edge(weight)

        # Otherwise use the default constructor
        if weight is None:
            self.thisptr = new Edge()

    def __dealloc__(self):
        del self.thisptr

    property weight:
        def __get__(self):
            return self.weight

        def __set__(self,value):
            if type(value) is not float and type(value) is not int:
                raise Exception(":::: Weight of edges must be numeric!")
            else:
                self.weight=value

    property mark:
       def __get__(self):
           return self.mark

       def __set__(self,value):
           if type(value) is not int:
               raise Exception(":::: Mark is a 0/1 and represent if the edge is visited or not")
           else:
               self.mark=value

#####################################
##### Neighbors iterator class ######
#####################################
class NeighborsIterator:
   def __init__(self, obj):
       self.obj=obj
       self.cnt=0

   def __iter__(self):
       return self

   def next(self):
       try:
           result=self.obj.getNeighbor(self.cnt)
           self.cnt+=1
           return result
       except IndexError:
           raise StopIteration

#####################################
##### Node implementation ##########
#####################################
cdef extern from "Node.h":
    cdef cppclass Node:
        Node() except +
        Node(int id, double weight) except +
        double degree
        double weight
        double distance
        int color, id,index,component
        # per qualche oscuro motivo qua non vuole l'asterisco dei puntatori mentre nella Graph sì
        vector[ Neighbor ] neighborsRand

cdef class wrapperNode:
    cdef Node *thisptr      # hold a C++ instance which we're wrapping
    def __cinit__(self, id=None, weight=None):
        if id is not None and weight is not None:
            if type(id) is not int:
                raise Exception( "::: ID of nodes must be integer!")
            if type(weight) is not float:
                raise Exception(":::: Weight of nodes must be float!")
            self.thisptr = new Node(id, weight)

        # Otherwise use the default constructor
        if id is  None and weight is None:
            self.thisptr = new Node()

    def __dealloc__(self):
        del self.thisptr

    def __iter__(self):
        return NeighborsIterator(self)

    def getNeighbor(self,index):
        return deref(deref(self.thisptr.neighborsRand.at(index)).second).id

    def getNeighbors(self):
        neighborsList=[]
        for i in range(0,self.thisptr.neighborsRand.size()):
            neighborsList.append(deref(deref(self.thisptr.neighborsRand.at(i)).second).id)
        return neighborsList

    property degree:
        def __get__(self):
            return (self.thisptr).degree

    property weight:
        def __get__(self):
            return (self.thisptr).weight

    property distance:
        def __get__(self):
            return (self.thisptr).distance

    property color:
        def __get__(self):
            return (self.thisptr).color

    property id:
        def __get__(self):
            return (self.thisptr).id

    property index:
        def __get__(self):
            return (self.thisptr).index

    property component:
        def __get__(self):
            return (self.thisptr).component

    def __repr__(self):
        return "ID=%s Deg=%s Weight=%s" % (self.thisptr.id, self.thisptr.degree, self.thisptr.weight )


#####################################
##### LNode implementation ##########
#####################################
cdef extern from "LNode.h":
    cdef cppclass LNode(Node):
        double px,py,pz
        double dx,dy,dz


cdef class wrapperLNode(wrapperNode):
    property px:
        def __get__(self):
            return (<LNode*>self.thisptr).px
        def __set__(self, value):
            if type(value) is not float and type(value) is not int:
                raise Exception("Error position of nodes must be float!")
            (<LNode*>self.thisptr).px = float(value)

    property py:
        def __get__(self):
            return (<LNode*>self.thisptr).py
        def __set__(self, value):
            if type(value) is not float and type(value) is not int:
                raise Exception("Error position of nodes must be float!")
            (<LNode*>self.thisptr).py = float(value)

    property pz:
        def __get__(self):
            return (<LNode*>self.thisptr).pz
        def __set__(self, value):
            if type(value) is not float and type(value) is not int:
                raise Exception("Error position of nodes must be float!")
            (<LNode*>self.thisptr).pz = float(value)

    property dx:
        def __get__(self):
            return (<LNode*>self.thisptr).dx

    property dy:
        def __get__(self):
            return (<LNode*>self.thisptr).dy

    property dz:
        def __get__(self):
            return (<LNode*>self.thisptr).dz

    def __repr__(self):
        return "ID=%s Deg=%s Weight=%s P=(%s,%s,%s)" % (self.id, self.degree, self.weight,self.px,self.py,self.pz )

# This class is a python wrapper that use a dictionary to store the LNode attributes
# in a python dictionary
class NodeDict(dict):
    def __init__(self,id,nodeAttributes,position=None,degree=None,component=None,neighbors=None):
        self['id']=id
        # Attributes can be of any type, this is the strong point of python
        self['nodeAttributes']=nodeAttributes
        
        if (position is not None ):
            if ( all(isinstance(x,float) for x in position)  ):
                self['pos']=position
            else:
                raise TypeError("position must be a list of 2 or 3 floats")
        else:
             self['pos']=[0.0, 0.0, 0.0]
        
        if ( component is not None and isinstance(component,int) ):
            self['component']=component
        else:
            raise TypeError("Component must be integer")

        if (degree is not None and (isinstance(degree,int) or isinstance(degree,float)) ):
            self['degree']=degree
        else:
            raise TypeError("Degree must be float")

        if (neighbors is not None and type(neighbors) is list and all(isinstance(x,int) for x in neighbors) ):
                self['neighbors']=neighbors
        else:
            raise TypeError("Neighbors must be a list of integers")

    def neighbors(self):
        return self['neighbors']

    def get(self):
        return self

    def iteritems(self):
        return self.iteritems()

    def iterkeys(self):
        return self.iterkeys()

    def attributes(self):
        return self['nodeAttributes']

# This class is a python wrapper that use a dictionary to store the Edge attributes
# in a python dictionary
class EdgeDict(dict):
    def __init__(self,int fromNode,int toNode,edgeAttributes=None):
        self['source']=fromNode
        self['target']=toNode
        if (edgeAttributes is not None ):
            self['edgeAttributes']=edgeAttributes
    def get(self):
        return self

    def iteritems(self):
        return self.iteritems()

    def iterkeys(self):
        return self.iterkeys()

    def attributes(self):
        return self['edgeAttributes']

    
#####################################
##### Graph iterators classes #######
#### Iterator on Graph nodesRand ####
#####################################

class GraphNodesRandIterator:
    def __init__(self, obj):
        self.obj=obj


    def __iter__(self):
        return self

    def next(self):
        try:
            if ( self.cnt>=self.obj.getNodesCount() ):
                raise IndexError
            else:
                result=self.obj.nodes[self.cnt]
                self.cnt+=1
                return result
        except IndexError:
            raise StopIteration


#####################################
##### Graph implementation ##########
#####################################

cdef extern from "GraphLayout.h":
    cdef cppclass GraphLayout:
        vector[Node*] nodesRand
        map[int,Node*] nodes
        int statsNodesCount
        int statsEdgesCount
        int statsComponentsCount
        GraphLayout()
        void loadDimacs(string filename)
        Node* insertNode(int id)
        void removeNode(int id)
        Edge* insertEdge(int fromNode, int toNode, double weight)
        void removeEdge(int fromNode, int toNode)
        int countConnectedComponents() except +
        int getEdgesCount()
        int getNodesCount()
        int getComponentsCount()
        Node* getNode(int nodeId) except +
        
        # Layout things
        int init(int methodType, int nDimensions, bool randomize, bool shake)
        int steps(int nsteps) except *


cdef class wrapperGraphLayout(object):
    cdef GraphLayout *thisptr      # hold a C++ instance which we're wrapping
    nodes=dict()
    edges=dict()
    def __cinit__(self,graphname=None):
        signal.signal(signal.SIGINT, self.abort_loop)
        if graphname is None:
            self.thisptr = new GraphLayout()
        if isinstance(graphname,str):
            if (".dimacs" in graphname.lower() ):
                self.thisptr = new GraphLayout()
                self.thisptr.loadDimacs(graphname)
            if (".net" in graphname.lower() ):
                self.thisptr = new GraphLayout()
                self.loadPajek(graphname)


    def __dealloc__(self):
        del self.thisptr

    def abort_loop(self):
        self.layoutFinished=1
    
    def insertNode(self, int nodeId,nodeAttribute=None,position=None):
        n=self.thisptr.insertNode(nodeId)
        if ( position is not None):
            ln=<LNode*>n;
            ln.px=float(position[0])
            ln.py=float(position[1])
            ln.pz=float(position[2])
        self.nodes[nodeId]=NodeDict(n.id,nodeAttribute,position,n.degree,n.component,[])
    
    def setNodeAttribute(self, int nodeId, nodeAttribute,position):
        if (nodeId in self.nodes.keys() ):
            self.nodes[nodeId]['nodeAttributes']=nodeAttribute
            self.nodes[nodeId]['pos']=position
        else:
            raise KeyError("No node with id %d" % nodeId)
            
    def removeNode(self, int nodeId):
        # remove the node from C++ internal representation
        self.thisptr.removeNode(nodeId)
        if (nodeId not in self.nodes ):
            return
        # Delete the node from self.nodes and from its neighbors 
        for neigh in self.nodes[nodeId]['neighbors']:
            other=self.nodes[neigh]
            other['neighbors'].remove(nodeId)
            other['degree']-=1;
        del self.nodes[nodeId]
    
    
    def insertEdge(self, int fromNode, int toNode, double weight=1.0, edgeAttributes=None):
        self.thisptr.insertEdge(fromNode,toNode,weight)
        
        # If the fromNode is not already in nodes dict then insert it both in dict and in c++ Graph.cpp
        if ( fromNode not in self.nodes.keys() ):
            self.insertNode(fromNode)
            
        # If the toNode is not already in nodes dict then insert it both in dict and in c++ Graph.cpp
        if ( toNode not in self.nodes.keys() ):
            self.insertNode(toNode)
        
        # If the toNode is not in fromNode neighbors append it
        if ( toNode not in self.nodes[fromNode]['neighbors'] ):
            self.nodes[fromNode]['neighbors'].append(toNode)
        
        # If the fromNode is not in toNode neighbors append it
        if ( fromNode not in self.nodes[toNode]['neighbors'] ):
            self.nodes[toNode]['neighbors'].append(fromNode)
        
        # Append the edge to the edge dictionary
        # XXX Important: in the pythonic representation we represent edges as they were directed, fromNode --> toNode while in C++ there exist a neighbor on both sides
        if ( (fromNode,toNode) not in self.edges.keys() ):
            self.edges[ fromNode,toNode ] = EdgeDict(fromNode,toNode,edgeAttributes)
        else:
            print ("::Warning:: the edge " + str(fromNode) + " " + str(toNode) + " already exists, the latest attribute was ignored and edge has not been inserted" )
        
    def removeEdge(self, int fromNode, int toNode):
        # remove the edge from C++ internal representation
        self.thisptr.removeEdge(fromNode,toNode)
        
        for neigh in self.nodes[fromNode]['neighbors']:
            other=self.nodes[neigh]
            other['neighbors'].remove(toNode)
            other['degree']-=1;
        
        for neigh in self.nodes[toNode]['neighbors']:
            other=self.nodes[neigh]
            other['neighbors'].remove(fromNode)
            other['degree']-=1;
        
        # then delete both nodes of the edge
        del self.nodes[fromNode]
        del self.nodes[toNode]
        
        # del edge from edges dictionary
        del self.edges[ str(fromNode)+" " + str(toNode) ]
        del self.edges[ str(toNode)+" " + str(fromNode) ]
        
    def components(self):
        raise RuntimeError("XXX TO IMPLEMENT USING vector< NodesRand > inside Graph.cpp")

    def countConnectedComponents(self):
        return self.thisptr.countConnectedComponents()
    
    def getComponentsCount(self):
        return self.thisptr.statsComponentsCount

    def getEdgesCount(self):
        return self.thisptr.statsEdgesCount

    def getNodesCount(self):
        return self.thisptr.statsNodesCount

    def nodes(self):
        return self.nodes#GraphNodesRandIterator(self)

    def getNode(self, int nodeid):
        n=<LNode*>self.thisptr.getNode(nodeid)
        nid = deref(n).id
         
        #except Exception:
        #    raise IndexError("Can't find node with id=" + str(nodeid))
        return self.nodes[nid]
            
    def syncDataStructures(self):
        """
        This method iterate on the underlying C++ class in Graph.cpp and updates the Python structure with the very same content of nodes.
        Nodes attributes are maintaned when already existing
        """
        iternodesRand = self.thisptr.nodesRand.begin()
        while ( iternodesRand != self.thisptr.nodesRand.end() ):
            n=deref(iternodesRand)
            numOfNeighbors = n.neighborsRand.size()
            # This  method appends to NodeDict a neighbors list as node ids
            neighborsList=[]
            for i in range(0,numOfNeighbors):
                k=deref(deref(n.neighborsRand.at(i)).second).id
                neighborsList.append( k )
            
            """
            This is THE way to update the nodes attributes! by implicity extending the data model of Node.cpp 
            exploiting power of python dictionaries
            """
            nodeAttr=None
            if ( n.id in self.nodes ):
                nodeAttr=self.nodes[n.id]['nodeAttributes']
            
            nn= NodeDict( n.id, nodeAttr, n.degree, n.component, neighborsList )

            self.nodes[n.id] = nn
            preinc(iternodesRand) # increment iterator

    def loadDimacs(self, filename):
        if (not isinstance(filename,str)):
            raise TypeError("Filename must be string")
        try:
            inputfile=open(filename)
        except:
            raise IOError("File doesn't exist")
        
        self.thisptr.loadDimacs(filename)
    
    def loadPajek(self,filename):
        if (not isinstance(filename,str)):
            raise TypeError("Filename must be string")
        try:
            inputfile=open(filename)
        except:
            raise IOError("File doesn't exist")
        
        sectionVertices=False # we are reading the vertices
        sectionEdgesList=False # we encoutered the tag that specifies we have an edgelist as adjacency list 
        sectionArcs=False # we encoutered the tag that specifies we have an arcs list as pair of nodes
        
        allowedTags=["vertices","edges","arcslist","edgeslist","arcs","edges"]
        lineNumber=0
        alreadyFoundVertices=False
        for row in inputfile:
            lineNumber=lineNumber+1
            r=row.strip('\n').lstrip()
            if (len(r)==0):
                 continue

            if ("#" in r or "%" in r):
                continue
            # First search for the *Vertices tag
            if ( r[0] == "*" ):
                #tagId = allowedTags.index(r[0][1:])
                currentTag = shlex.split(r)[0][1:].lower()
                if ( currentTag=="vertices" ):
                    if ( alreadyFoundVertices==True ):
                        raise IOError("Error at line " + str(lineNumber) + ", you can specify \"*Vertices\" tag only once, join all vertices blocks" )
                    sectionVertices=True
                    alreadyFoundVertices=True
                    continue
                elif ( currentTag=="edges" or currentTag=="arcs" ):
                    sectionVertices=False
                    sectionArcs=True
                    continue
                elif ( currentTag=="arcslist" or currentTag=="edgeslist" ):
                    sectionVertices=False
                    sectionEdgesList=True
                    continue
                else:
                    raise IOError("Tag not supported \"" + currentTag +"\" at line " + str(lineNumber) )

            if (sectionVertices):
                nodelist=shlex.split(r)
                if (len(nodelist) <= 1 ):
                    raise IOError("For the vertices you must specify at least vertex ID and a string description, for example 1 \"vertex A\" ") 
                nodeid=int(nodelist[0])
                nodeAttributes=[nodelist[1]] # This is the most important attribute, the string attribute
                
                if ( len(nodelist)>2 ):
                    nodepos = [float(pi) for pi in nodelist[2:5]]
                    
                    # then append all unnecessary attributes following the 3 coordinates
                    for i in nodelist[6:]:
                         nodeAttributes.append(i)
                    self.insertNode(nodeid,nodeAttributes,nodepos)
                else:
                    self.insertNode(nodeid,nodeAttributes,None)
                continue

            if (sectionArcs):
                rr=re.sub("Newline", '', r)
                arc=shlex.split(rr.strip('\n'))
                fromNode=int(arc[0])

                toNode=int(arc[1])
                if ( len(arc)==3 ):
                    weight=float(arc[2])
                    self.insertEdge(fromNode,toNode,weight)
                else:
                    self.insertEdge(fromNode,toNode)
                continue

            if (sectionEdgesList):
                edgesList=shlex.split(r)
                fromNode=int(edgesList[0])
                for i in edgesList[1:]:
                    self.insertEdge(fromNode,int(i))
                continue

        # Copy node position to the new GraphLayout 
        iternodesRand = self.thisptr.nodesRand.begin()
        while ( iternodesRand != self.thisptr.nodesRand.end() ):
            n=<LNode*>deref(iternodesRand)
            n.px = self.nodes[n.id]['pos'][0]
            n.py = self.nodes[n.id]['pos'][1]
            n.pz = self.nodes[n.id]['pos'][2]
            preinc(iternodesRand) # increment iterator
        
        self.thisptr.countConnectedComponents()
        #self.syncDataStructures()

    def init(self, int methodType, int dimensions, bool randomize, bool shakeZ):
        self.thisptr.init(methodType,dimensions,randomize,shakeZ)

    def steps(self, int nsteps):
            return self.thisptr.steps(nsteps)
        
    def computeLayout(self,layoutname, nDimensions, maxSteps):
        
        if (nDimensions !=2 & nDimensions !=3):
            raise RuntimeError("Dimensions of layout must be 2 or 3")
        
        if ( type(maxSteps) is not int ):
            raise RuntimeError("Max steps must be integer")
        
        layout2Code={}
        layout2Code["KamadaKawai"] = 1;
        layout2Code["FruchtermanReingold"] = 2;
        layout2Code["FruchtermanReingoldProportional"] = 3
        layout2Code["LinLogModel"] = 4
        layout2Code["BinaryStress"] = 5
        layout2Code["FruchtermanReingoldMultilevel"] = 6
        layout2Code["FruchtermanReingoldProportionalMultilevel"] = 7
        layout2Code["LinLogModelMultilevel"] = 8
        layout2Code["BinaryStressMultilevel"] = 9
        layout2Code["HighDimensionalEmbedder"] = 10
        layout2Code["CircularLayout"] = 11
        layout2Code["Random"] = 12
        layout2Code["ACE"] = 13
        layout2Code["StressMajorization"] = 14
        
        if ( layoutname not in layout2Code.keys() ):
            message = "This layout method is not contempled, please specify one of the following\n\t"
            for m in layout2Code.keys():
                 message = message + m +"\n\t"
            
            raise RuntimeError(message)
            
        
        self.thisptr.init(layout2Code[layoutname],nDimensions,1,1)
        layoutFinished=0;
        print ("%s") % ("Computing layout...")
        nsteps=0
        try:
            while ( (layoutFinished==0) & nsteps<maxSteps ):
                layoutFinished = self.steps(1)
                nsteps=nsteps+1
        except (KeyboardInterrupt, SystemExit):
                print "Received keyboard interrupt, quitting threads. Tot steps= " + str(nsteps) 
        
        print "Layout done, total steps= %s" % (nsteps) 


