cdef extern from "Node.h":
    ctypedef struct c_Node "Node":
        double degree
        double weight
        double distance
        int color, id,index,component
    c_Node *new_Node "new Node" (int id, double weight)
    void del_Node "delete" (c_Node *rect)

cdef class Node:
    cdef c_Node *thisptr      # hold a C++ instance which we're wrapping
    def __cinit__(self, int id, double weight):
        self.thisptr = new_Node(id, weight)
    def __dealloc__(self):
        del_Node(self.thisptr)
    def __repr__(self):
        return "ID=%s Deg=%s Weight=%s" % (self.thisptr.id, self.thisptr.degree, self.thisptr.weight )

