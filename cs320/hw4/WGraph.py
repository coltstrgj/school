# If you just put 'import UF' here, then each reference to the class
# requires you to put 'UF.UF', to specify the module (UF.py)
# and the class (class UF in UF.py).  This allows us to reference
# the class with just 'UF':
from UF import UF

'''
This is an implementation of the adjacency-list representation of a graph
with integer edge weights, where the vertices are numbered from 0 through n-1.

The class has integer variables recording the number n of vertices
and number m of edges.  It has a list ._verts of length n of lists of integers.
The list that appears in position i of this list is the list of neighbors
of vertex i.  That is, ._verts[i][j] is the jth vertex in the adjacency
list for i.

It also has a list ._weights of length n of lists of integers, where
._weights[i][j] is the weight of the edge to the jth vertex in the adjacency
list for i
'''
class WGraph:

  # Return number of vertices in the graph
  def getn(self):
     return len(self._verts)

  # Return number of edges in the graph
  def getm(self):
     return self._m

  # Return a list of ordered triples, one for each edge.  The first element
  #  of the triple gives the starting vertex, the second gives the ending
  #  vertex and the third gives the weight of the edge
  def getEdges(self):
     edgeList = []
     for i in range(self.getn()):
        for j,w in zip(self._verts[i], self._weights[i]):
           edgeList.append((i,j,w))
     return edgeList

  ''' constructor.  __init-- is a reserved keyword identifying it
      as a constructor.  numVerts tells how many vertices it should have.
      edgeList is a list of ordered pairs, one for each edge, in any order.
      Example: numVerts = 3 and edgeList = [(0,1), (1,2), (0,2), (2,0)]'''
  def __init__ (self, numVerts, edgeList):
    self._m = len(edgeList)
    self._verts = [[] for i in range(numVerts)]
    self._weights = [[] for i in range(numVerts)]
    for u, v, w in edgeList:
      self._verts[u].append(v)
      self._weights[u].append(w)

  # Add an edge of weight 'weight' from 'tail' to 'head'
  def addEdge(self, tail, head, weight):
    self._verts[tail].append(head)
    self._weights[tail].append(weight)
    self._m += 1

  ''' This is similar to the Java toString() for the class.
      The string '__str__ 'is a reserved string, just as 'toString' is in Java.'''
  def __str__(self):
     return 'n = ' + str(self.getn()) + ' m = ' + str(self.getm()) + '\n' + ''.join([(str(i)+': ').rjust(6) + str(zip(self._verts[i],self._weights[i]))+'\n' for i in range(self.getn())])


  # Return the edges of an MST of the graph.
  #arent the vertex' supposed to be sorted before Kruskals? Why do we have to sort them?
  def Kruskal (self):
    C = UF(self.getn())
    WeightedVerts = self.getEdges()
    WeightedVerts.sort(key=lambda x: int(x[2]))#sort them based on length (does not take into account the duplicates from two way links)
    minTree = []
    for i in WeightedVerts:
      if(C.union(i[0],i[1])):#will not create cycles because UF checks for that
        minTree.append(i)
    return minTree  # REPLACE THIS

# Read a graph from a file of triples, one per line.  The first element
#  of the triple is the starting vertex, the second is the ending vertex,
#  and the third is the weight.
def readGraph(filename):
  edgeList = []
  fp = open(filename, 'r')
  n = int(fp.readline())
  for line in fp:
     u,v,w  = [int(x) for x in line.split(',')]
     edgeList.append((u,v,w))
  return WGraph(n, edgeList)

''' This is what executes when you run the command python -i hw5.py '''

if __name__ == '__main__':
  G = readGraph('winput.txt')
  print(G)

#print G.MST()
