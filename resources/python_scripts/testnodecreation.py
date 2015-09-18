G.initEmpty()
G.addAttribute("colore")
G.addAttribute("dimensione")

for i in range(0,100):
    G.insertNode(i,["verde","grande"])

for i in range(0,10):
    for j in range(0,10):
        try:
            G.insertEdge(i,j)
        except:
            pass

