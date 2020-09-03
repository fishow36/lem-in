# lem-in
This project deals with the problem of finding the maximum flow of a graph, but with additional restrictions: nodes have a capacity of one (except start and end nodes).
Thus, the standard Edmonds-Karp algorithm does not work for graphs with possibly intersecting paths. That is why we had to add duplicate nodes for each node except start and end nodes.
This approach allowed us to avoid intersecting paths and at the same time find all the possible paths. Then, at the stage of moving the "stuff" (in our case, it's ants moving through the tunnels to rooms), we check if we should use the given path at every step.
