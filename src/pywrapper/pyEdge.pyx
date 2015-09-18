cdef extern from "Edge.h":
    ctypedef struct c_Edge "Edge":
        double degree,px,py,pz,weight,distance
        double getWeight()
    c_Edge *new_Edge "new Edge" ()
    void del_Edge "delete" (c_Edge *rect)

cdef class Edge:
    cdef c_Edge *thisptr      # hold a C++ instance which we're wrapping
    def __cinit__(self):
        self.thisptr = new_Edge()
    def __dealloc__(self):
        del_Edge(self.thisptr)
    
    def __repr__(self):
        return "Edge weight= %s" % (self.thisptr.weight)

