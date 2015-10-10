'''
This is an implementation of the adjacency-list representation of a graph
where the vertices are numbered from 0 through n-1.

The class has integer variables recording the number n of vertices
and number m of edges.  It has a list self.verts of length n of lists of integers.
The list that appears in position i of this list is the list of neighbors
of vertex i.  For example, if self.verts is [[1,2], [], [0]], then
there are three vertices, since there are three lists in it.  Vertex 0
has neighbors 1 and 2, vertex 1 has no neighbors, and vertex has 0 as
its only neighbor.
'''
White = 0
Red = 1
Blue = 2
'''  Read a graph in from a file.  The format of the file is as follows:
     The first line gives the number of vertices.
     Each subsequent line gives an ordered pair of vertices, separated by
     a comma, indicating a directed edge.

     Example:
     ----
     3
     0,1
     1,2
     0,2
     2,0
     ----

     This gives a graph with three vertices and four directed edges,
     (0,1), (1,2), (0,2), (2,0)
'''
def readGraph(filename):
  edgeList = []
  fp = open(filename, 'r')
  n = int(fp.readline())
  for line in fp:
    u,v  = [int(x) for x in line.split(',')]
    edgeList.append((u,v))
  return Graph(n, edgeList)

class Graph(object):

  # return number of vertices
  def getn(self):
    return len(self.verts)

  # return number of edges
  def getm(self):
    return self.m

  def neighbors(self, i):
    return self.verts[i]

  # return a list of ordered pairs giving the edges of the graph
  def getEdges(self):
    return [(i,j) for i in range(self.getn()) for j in self.neighbors(i)]


  ''' constructor.  __init__ is a reserved keyword identifying it
      as a constructor.  numVerts tells how many vertices it should have.
      edgeList is a list of ordered pairs, one for each edge, in any order.
      Example: numVerts = 3 and edgeList = [(0,1), (1,2), (0,2), (2,0)]'''

  def __init__ (self, numVerts, edgeList):
    self.m = len(edgeList)
    self.verts = [[] for i in range(numVerts)]
    self.parentOf = [None for i in range(self.getn())]
    for u, v in edgeList:
      self.neighbors(u).append(v)  # works because neighbors returns a reference
                                   #  to the neighbor list

  # add an edge from tail to head.  No checking for errors, such as multi-edges
  def addEdge(self, tail, head):
    self.neighbors(tail).append(head)
    self.m += 1

  ''' String representation of the graph.  If G is an instance of the class,
      this is called with str(G).  It is called implicitly when a string
      is expected, e.g. in a call to print(G) '''
  def __str__(self):
    return '\n        n:  ' + str(self.getn()) + '\n        m:  ' + str(self.getm()) + '\n' + 'Adj lists:  ' + str(self.verts) + '\n' + '  parents:  ' + str(self.parentOf) + '\n'


  ''' DFS.  *colored* is a list of length self.getn().
      colored[j] = True if vertex j is colored, and it's False if j is
      white.  The parameter i is the vertex number of the vertex to start
      at, and it must be white.  The call must color all vertices
      reachable from i in the white subgraph. '''
  def dfs(self, i, colored):
    colored[i] = True #color i for sure
    for vert in self.verts[i]: #for all the vertices that will be children of vertice active in queue
      if colored[vert] != True: #if it is already colored we dont want to re do this
        self.parentOf[vert] = i
        self.dfs(vert, colored)
    #for vert in range(len(colored)):#check to see if any are not connected
    #  if colored[vert] != True:
    #    self.dfs(vert, colored) #drop down a level
    return #should this return anything? TODO

  ''' Return the transpose of the graph, that is, the result of reversing
      all the edges, represented in the format specified by the Graph class  '''
  def transpose (self):
    other = Graph(self.getn(), [])#creates the new graph
    other.m = self.getm()#sets m because there is no need to run len()
    for i in range(self.getn()):#wow this will be slow
      for vert in self.verts[i]:
        other.verts[vert] = other.verts[vert] + [i] #normally 'i' has a vertex to 'vert'. Now 'vert' has a vertex to 'i'
    return other

  ''' BFS starting at i.  Label each node with its parent in the resulting
      BFS tree.  Return a list D of length n, where D[j] tells the distance
      of vertex j from vertex i, and a list L that gives the order in which
      vertex were extracted from the queue.  '''
  def bfs(self, i):
    L = [None]*self.getn() #this was not in instructions? TODO
    distance = [None]*self.getn()
    #distnaces = [None for i in range(self.getn())] #which is better this or above?
    queue = [i] #Add I to the queue
    distance[i] = 0
    L[i] = 0
    front = 0
    visit = 0
    while front != len(queue):
      for vert in self.verts[queue[front]]:#take the last thing on the queue, go through its children
        if distance[vert] == None: #could also check queue, but that would take O(n) is worse, and having extra list 'discovered' is pointless
          self.parentOf[vert] = queue[front]#set the parents
          distance[vert] = distance[queue[front]] + 1 #set the distance to parents distance+1 location(distance from base)
          queue.append(vert) #add it to queue so we can check it's children
          visit += 1 #keep track of when we visited it for some reason not in instructions.
          L[vert]=visit
      front += 1
    #for vert in range(len(distance)):#check to see if any are not connected
    #  if distance[vert] == None:
    #    self.bfs(vert) #if we find one that is not connected we have to do it as well
    return distance, L

  ''' Return the vertices on a shortest path from i to j.  The precondition
      is that the parent pointers in the graph give a BFS tree rooted at i. '''
  def shortestPath(self, i, j):#started recursive, but it will come out in 'correct' order
    if self.parentOf[j] != None:
      if self.parentOf[j] != i:
        return [j] + self.shortestPath(i, self.parentOf[j])
      #else we are parent of j = i
      return [j, i]
    elif i == j:
      return [j]
    return [None]


  '''  Determine whether the graph is strongly connected.  It should
       return False if it is not, True if it is.  '''
  #if S.BFS(0) and S_transpose.BFS(0) are complete, graph is strongly connected
  def isStronglyConnected(self):#is it allowed to change the variables in self, or do I copy it then test? TODO
    colored = [White]*self.getn() #create the initial colored list
    self.dfs(0, colored)
    for i in colored:
      if i == White:#node has not been touched
        return False
    trans = self.transpose()
    colored = [White]*self.getn()
    trans.dfs(0, colored)
    for i in colored:
      if i == White:#node has not been touched
        return False
    return True

  ''' Return (True, None)  if the graph is bipartite.  If it is not
      bipartite, have it return (False, L), where L is the list of
      vertices on an odd cycle, in order. '''
  def isBipartite(self):
    colorOf = [White for i in range(self.getn())]
    self.parentOf = [None for i in range(self.getn())]
    return self.isBipartiteAux(0, Red, colorOf)
  ''' Preconditions are that 'i' is a white vertex, 'color' is either Red or
      Blue, and colorOf[k] gives the current color of each vertex k.
      Do one of the following:

        1.  Color all vertices reachable from i on a white path with Red and
        Blue, starting by giving 'i' the color given by 'color', so that none
        of these vertices is a neighbor of a vertex of the same color.  Return
        (True, None).

        2.  Return (False, L), where L is the list of vertices on an odd cycle,
        in the order in which they appear on the cycle.
  '''
  def isBipartiteAux(self, i, color, colorOf):#TODO copy or change original
    colorOf[i] = color #color this node
    if color == Red:
      op_color = Blue
    else:
      op_color = Red
    for vert in self.verts[i]: #for all the vertices that will be children of vertice active in queue
      if colorOf[vert] == color:#if this is red and parent is red, then not bipartite
        #return ancestor that caused failure
        #because of DFS we know that the ancestor is not a cousin, so just add parents until we get to culprit
        return False, [vert, i] #add the offender
      if colorOf[vert] != White: #we dont need to check this farther because it is
        continue
      #if we made it this far, we are ad a white node
      self.parentOf[vert] = i
      bipartite, cycle = self.isBipartiteAux(vert, op_color, colorOf)  #drop down a level
      if bipartite == False:#if we are in an odd cycle, construct it
        if len(cycle) != 2: #we must have added something already
          return False, cycle
        cycle = self.constructCycle(cycle)#why was this not working without the cycle = at beginning?
        return False, cycle
    return True, None

  #this is not really a cycle, but it is the only way to guarentee that we can show non bipartiteness
  def constructCycle(self, nodes):
    pEnd = nodes[1]
    pRoot = nodes[0]
    ancestors = []
    for i in range(self.getn()):
      if self.parentOf[pEnd] != None:#root will have no parent
        ancestors = ancestors + [pEnd]
        pEnd = self.parentOf[pEnd]
      else:
        break #exit the for loop, we are at root node
    for i in range(len(self.parentOf)):
      loc = 0 #set loc to the first ancestor (root)
      for vert in ancestors:
        if pRoot == vert:# we found the common ancestor
          parent = self.parentOf[nodes[1]]
          for j in range(loc, len(ancestors)):#have to add the parents between loc (common ancestor) and base node to list
            nodes = nodes + [parent] #add it to the list
            parent = self.parentOf[parent]
          return nodes
        #else
        loc = loc + 1# this is not the common ancestor, move back one and try again
      pRoot = self.parentOf[pRoot]#move up from there
    return#should never hit this


  ''' This is a varant on DFS that returns a list of vertices that
      were blackened during the call, in the order in which they finished.
      'colored' is a list of n None's.  'finished' is a list of vertices
      on which a recursive call has finished, in the order in which
      they finished.  When a vertex finishes, append it to this list.  '''
  """
  def dfs(self, i, colored):
    colored[i] = True #color i for sure
    for vert in self.verts[i]: #for all the vertices that will be children of vertice active in queue
      if colored[vert] != True: #if it is already colored we dont want to re do this
        self.parentOf[vert] = i
        self.dfs(vert, colored)
    for vert in range(len(colored)):#check to see if any are not connected
      if colored[vert] != True:
        self.dfs(vert, colored) #drop down a level
    return #should this return anything? TODO"""
  def finishOrder(self, i, colored, finished):#why are we using DFS, this whole assignment is bonkers
    colored[i] = True #color i for sure
    for vert in self.verts[i]: #for all the vertices that will be children of vertice active in queue
      if colored[vert] != True: #if it is already colored we dont want to re do this
        self.parentOf[vert] = i
        finished = self.finishOrder(vert, colored, finished) #drop down a level
    finished = finished + [i]
#   for vert in range(len(colored)):#check to see if any are not connected
#     if colored[vert] != True:
#       finished = self.finishOrder(vert, colored, finished) #if we find one that is not connected we have to do it as well
    return finished

  ''' Return the strongly-connected components, as a list L of lists of
      integers.  Each list in L has the vertices in one strongly-connected
      components. '''
  def scc(self):
    SCC = []
    vertices = range(self.getn()) #create a list of vertices
    connectedTo = [None]*self.getn() #stores lists
    for i in range(self.getn()):
      finished = self.blacken([i])[0]#get the nodes it is connected to
      connectedTo[i] = finished#store list so we can find shortest later
    while len(vertices) != 0:#if vertices is empty we are done
      minSoFar = len(connectedTo[vertices[0]]) #initialize it to first length
      minVert = vertices[0] #initialize to first vertex
      for i in vertices:#find the vert with the fewest connections to other virts, start from here
        tmp = len(connectedTo[i])
        if tmp < minSoFar:
          minVert = i
          minSoFar = tmp
      stronglyConnected = [minVert]
      for vert in connectedTo[minVert]:
        if vert == minVert:#checking itself
          continue
        if minVert in connectedTo[vert]:#if it is in the list then they are strongly connected together
          stronglyConnected = stronglyConnected + [vert]
          vertices.remove(vert)
      vertices.remove(minVert)#go back through while loop, but cant find this again
      SCC =  SCC + [stronglyConnected]#add this list to the list of lists
    return SCC

  ''' Go through each in the graph in the order given by vertOrder,
      calling DFS on the vertex if it's still white.  If no vertOrder
      parameter is given, then go through them in ascending order of
      vertex number.   Return a list L of lists, where each list in L
      is the vertices blackened by one of the calls to DFS generated
      from blacken.

      Being able to specify the order in which you go through them is
      useful for the strongly-connected componentns algorithm. '''
  def blacken(self, vertOrder = None):
    finished = []
    if vertOrder == None:
      vertOrder = range(self.getn())
    colored = [False]*self.getn()
    for i in vertOrder:
      if not colored[i]: #so this is how to do not...
        finished.append(self.finishOrder(i, colored, []))
    return finished

if __name__ == '__main__':
  G1=readGraph('input1.txt')
  G2=readGraph('input2.txt')
  G3=readGraph('input3.txt')
  G4=readGraph('input4.txt')
