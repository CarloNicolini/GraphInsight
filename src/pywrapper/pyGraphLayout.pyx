from libcpp.vector cimport vector
from libcpp.set cimport set
from libcpp.pair cimport pair
from libcpp.string cimport string
from libcpp cimport bool

#####################################
#### std::vector implementation #####
#####################################
#####################################
##### Edge implementation ##########
#####################################
cdef extern from "Edge.h":
    cdef cppclass Edge:
        Edge() except +
        Edge( double weight) except +
        double weight
        bool mark
         
cdef class pyEdge:
    cdef Edge *thisptr      # hold a C++ instance which we're wrapping

    def __cinit__(self, weight=None):
        if weight is not None:
            if type(weight) is not float:
                raise Exception(":::: Weight of edges must be float!")
            self.thisptr = new Edge(weight)
                
        # Otherwise use the default constructor
        if weight is None:
            self.thisptr = new Edge()
                
    def __dealloc__(self):
        del self.thisptr

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
        
cdef class pyNode:
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
    
    def __repr__(self):
        return "ID=%s Deg=%s Weight=%s" % (self.thisptr.id, self.thisptr.degree, self.thisptr.weight )

#####################################
##### LNode implementation ##########
#####################################
cdef extern from "LNode.h":
    cdef cppclass LNode(Node):
        double px,py,pz
        double dx,dy,dz
        double degree
        double weight
        double distance
        int color, id,index,component
        vector[ pair[Edge, Node ] ] neighborsRand

cdef class pyLNode(pyNode):
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

    property degree:
        def __get__(self):
            return (<LNode*>self.thisptr).degree

    property weight:
        def __get__(self):
            return (<LNode*>self.thisptr).weight

    property id:
        def __get__(self):
            return (<LNode*>self.thisptr).id

    property component:
        def __get__(self):
            return (<LNode*>self.thisptr).component

    property distance:
        def __get__(self):
            return (<LNode*>self.thisptr).distance

    def __repr__(self):
        return "ID=%s Deg=%s Weight=%s P=(%s,%s,%s)" % (self.id, self.degree, self.weight,self.px,self.py,self.pz )


#####################################
##### Graph implementation ##########
#####################################

cdef extern from "Graph.h":
    cdef cppclass Graph:
        vector[Node*] nodesRand
        Graph() except +
        void insertNode(int id)
        void removeNode(int id)
        void insertEdge(int fromNode, int toNode)
        void removeEdge(int fromNode, int toNode)
        double getDiameter()
        Graph* coarsen(int method)
        int countConnectedComponents()
        void printStats()
        int getEdgesCount()
        vector[int]  getMaximalIndependentSet()
        vector[set[int]] getMaximalCliques(int k)

cdef class pyGraph:
    cdef Graph *thisptr      # hold a C++ instance which we're wrapping
    cdef vector[Node*] nodesRand
    #def __cinit__(self):
    #    self.thisptr = new Graph()
    
    def __dealloc__(self):
        del self.thisptr
    
    def insertNode(self, int nodeId):
        self.thisptr.insertNode(nodeId)
    
    def removeNode(self, int nodeId):
        self.thisptr.removeNode(nodeId)
    
    def insertEdge(self, int nodeId1, int nodeId2):
        self.thisptr.insertEdge(nodeId1,nodeId2)
    
    def removeEdge(self, int nodeId1, int nodeId2):
        self.thisptr.removeEdge(nodeId1,nodeId2)
    
    def countConnectedComponents(self):
        return self.thisptr.countConnectedComponents()
    
    def getEdgesCount(self):
        return self.thisptr.getEdgesCount()
        
    def coarsen(self,int method):
        self.thisptr.coarsen(method)
    
    def printStats(self):
        self.thisptr.printStats()

    def getMaximalIndependentSet(self):
        cdef vector[int] aa
        cdef int N
        b= []
        aa = self.thisptr.getMaximalIndependentSet()
        N=aa.size()
        for i in range(N):
            b.append(aa[i])
        return b;

    def getMaximalCliques(self, int k):
        cdef vector[set[int]] aa
        cdef int N
        b=[]
        aa = self.thisptr.getMaximalCliques(k)
        N=aa.size()
        for i in range(N):
            b.append(aa[i])
        return b;
        

#####################################
##### GraphLayout implementation ####
#####################################

cdef extern from "GraphLayout.h":
    cdef cppclass GraphLayout(Graph):
        GraphLayout() except +
        GraphLayout(string graphname) except +RuntimeError
        int steps(int nsteps)
        int init(int methodType, int nDimensions, bool randomize, bool shake)
        void writeGnuplot(string graphname, bool withColors)
        void loadDimacs(string graphname) except +
        int getMemoryFootprintInBytes()
        double getAverageLength()
        
cdef class pyGraphLayout:
    cdef GraphLayout *thisptr      # hold a C++ instance which we're wrapping

    def __cinit__(self, graphname):
        if graphname is None:
            self.thisptr = new GraphLayout()
        if type(graphname) is str:
            try:
                self.thisptr.loadDimacs(graphname)
            except Exception:
                print "Can't load the file"
        else:
            print "Specify a file name in dimacs format"
        
    def __dealloc__(self):
        del self.thisptr

    def insertNode(self, int nodeId):
        (<GraphLayout *>(self.thisptr)).insertNode(nodeId)
    
    def removeNode(self, int nodeId):
        (<GraphLayout *>(self.thisptr)).removeNode(nodeId)
    
    def insertEdge(self, int nodeId1, int nodeId2):
        (<GraphLayout *>(self.thisptr)).insertEdge(nodeId1,nodeId2)
    
    def removeEdge(self, int nodeId1, int nodeId2):
        (<GraphLayout *>(self.thisptr)).removeEdge(nodeId1,nodeId2)
    
    def printStats(self):
        (<GraphLayout *>(self.thisptr)).printStats()
    
    def getMaximalCliques(self, int k):
        return (<GraphLayout*>(self.thisptr)).getMaximalCliques(k)
        
    def getMaximalIndependentSet(self):
        return (<GraphLayout*>(self.thisptr)).getMaximalIndependentSet()

    def writeGnuplot(self, string graphname, bool withColors):
        self.thisptr.writeGnuplot(graphname, withColors)
        
    def loadDimacs(self, string graphname):
        try:
            self.thisptr.loadDimacs(graphname)
        except RuntimeError:
            raise RuntimeError("File doesn't exist")
            
    def getMemoryFootprintInBytes(self):
        return self.thisptr.getMemoryFootprintInBytes()
        
    def getAverageLength(self):
        return self.thisptr.getAverageLength()
        
    def steps(self,int nsteps):
        returnval=0
        try:
            returnval=self.thisptr.steps(nsteps)
        except KeyboardInterrupt:
            return returnval
        except RuntimeError:
            return returnval
    
    def init(self, int methodType, int nDimensions, bool randomize, bool shake):
        self.thisptr.init(methodType, nDimensions, randomize, shake )

    def computeLayout(self, layoutname, nDimensions):
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
            print "This layout method is not contempled, please specify one of the following"
            for m in layout2Code.keys():
                print "\t%s" % (m)
            return None
        
        self.thisptr.init(layout2Code[layoutname],nDimensions,1,1)
        computed=0;
        
        print ("%s") % ("Computing layout...")
        nsteps=0
        while ( computed==0 ):
            try:
                computed = self.thisptr.steps(1)
                nsteps=nsteps+1
            except (KeyboardInterrupt, SystemExit):
                computed=1
                print '\n! Received keyboard interrupt, quitting threads.\n'
                break;
            
        print "Layout done, total steps= %s" % (nsteps) 
    
