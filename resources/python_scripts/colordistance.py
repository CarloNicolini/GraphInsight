# This script show how to create a custom colormap for nodes based on their coordinates
from math import sqrt;

# The function fro a double to a jetmap (Matlab style)
def doubleToJetMap(x):
    r = 255*((x >= 0.375 and x < 0.625) * (4.0 * x - 1.5) + (x >= 0.625 and x < 0.875) + (x >= 0.875) * (-4.0 * x + 4.5));
    g = 255*((x >= 0.125 and x < 0.375) * (4.0 * x - 0.5) + (x >= 0.375 and x < 0.625) + (x >= 0.625 and x < 0.875) * (-4.0 * x + 3.5));
    b = 255*((x < 0.125) * (4.0 * x + 0.5) + (x >= 0.125 and x < 0.375) + (x >= 0.375 and x < 0.625) * (-4.0 * x + 2.5));

    return [r,g,b]


# get a copy of the current graph handle
g=G;
# Maximum radius
maxR=-1;
# Current barycenter of the graph
center=[0.0,0.0,0.0];
# Compute the barycenter of the graph
for n in g.nodes().values():
	center[0]=center[0]+n.getX()
	center[1]=center[1]+n.getY()
	center[2]=center[2]+n.getZ()

for i in range(0,2):
    center[i]=center[i]/g.getNodesCount()

# Compute the maximum radius (needed to properly scale the colors)
for n in g.nodes().values():
	r = sqrt( pow(n.getX()-center[0],2) +pow(n.getY()-center[1],2)+pow(n.getZ()-center[2],2) );
	if (maxR < r ):
		maxR=r;

# Colorize the nodes based on the latest nodes colors
for n in g.nodes().values():
	r = sqrt( pow(n.getX()-center[0],2) +pow(n.getY()-center[1],2)+pow(n.getZ()-center[2],2) );
	x=doubleToJetMap(r/maxR);
	n.setColorRGB(x[0],x[1],x[2])