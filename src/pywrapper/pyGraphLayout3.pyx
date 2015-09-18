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
    def __init__(self,id,nodeAttributes,degree=None,component=None,neighbors=None):
        self['id']=id        
        # Attributes can be of any type, this is the strong point of python
        self['nodeAttributes']=nodeAttributes
        
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

cdef extern from "Graph.h":
    cdef cppclass Graph:
        vector[Node*] nodesRand
        map[int,Node*] nodes
        int statsNodesCount
        int statsEdgesCount
        int statsComponentsCount
        Graph()
        void loadDIMACS(string filename)
        Node* insertNode(int id)
        void removeNode(int id)
        Edge* insertEdge(int fromNode, int toNode, double weight)
        void removeEdge(int fromNode, int toNode)
        int countConnectedComponents() except +
        int getEdgesCount()
        int getNodesCount()
        int getComponentsCount()
        Node* getNode(int nodeId) except +


cdef class wrapperGraph(object):
    cdef Graph *thisptr      # hold a C++ instance which we're wrapping
    nodes=dict()
    def __cinit__(self,graphname=None):
        if graphname is None:
            self.thisptr = new Graph()
        if isinstance(graphname,str):
            self.thisptr = new Graph()
            self.thisptr.loadDIMACS(graphname)

    def __dealloc__(self):
        del self.thisptr

    def insertNode(self, int nodeId,nodeAttribute=None):
        n=self.thisptr.insertNode(nodeId)
        self.nodes[nodeId]=NodeDict(n.id,nodeAttribute,n.degree,n.component,[])
    
    def setNodeAttribute(self, int nodeId, nodeAttribute):
        if (nodeId in self.nodes.keys() ):
            self.nodes[nodeId]['nodeAttributes']=nodeAttribute
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
        
    def insertEdge(self, int fromNode, int toNode, double weight=1.0):
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
        n=self.thisptr.getNode(nodeid)
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
