# Get the current graph G as variable mygraph
mygraph=G;

# Init an empty graph from it
mygraph.initEmpty()


# Start adding some nodes with random IDs
from random import randrange

# Insert nodes, ignores exception thrown when the node already exists
for i in range(0,100):
    try:
        mygraph.insertNode(randrange(0,20))
    except:
        pass

# Insert edges randomly in the graph
# Ignores exceptions thrown if the nodes of the edge don't exists or
# if the edge already exists

for i in range(0,1000):
    try:
        mygraph.insertEdge(randrange(0,20),randrange(0,20))
    except:
        pass

# Print the number of undirected edges
print G.getEdgesCount()

# Print the number of nodes
print G.getNodesCount()

# Print the number of connected components
print G.getComponentsCount()

# Remove edges randomly until the number of connected components is 1
ncomponents=G.getComponentsCount()

while (G.getComponentsCount() > 1):
    try:
        fromNode=randrange(0,20)
        toNode=randrange(0,20)
        G.removeNode(fromNode)
        G.removeNode(toNode)
    except:
        pass

# Print the nodes in the remaining component
for n in G.nodes().values():
    print ("%d %d") % (n.getId(),n.getComponent())


