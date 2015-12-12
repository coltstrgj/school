import random
from Graph2 import Graph



''' is an undirected special case of Graph class.  It demonstrates
    some algorithms optimization problems on graphs, and illustrates
    how to show that problems are NP-complete and NP-hard '''
class UndirectedGraph(Graph):

  #problem1 minWeightVertCover
  '''
  Write a similar method for finding a minimum-weight vertex cover.
  The returned Python list should consist of two elements. The first element should be
  an integer or real value giving the weight of the minimum weight vertex cover and the
  second element should be another Python list giving the vertices of the vertex cover.
  It should use an auxiliary recursive method, just like maxIndSet, maxWeightIndSet,
  and minVertCover, and, just as those methods do, it should return a list of the vertices
  in the minimum-weight independent set. The strategy is similar to that of recursive
  algorithms we wrote as a first step in developing dynamic programming algorithms.
  '''
  def minWeightVertCover(self, Weights):#no time to check for correctness
    selected = [False]*self.getn()
    weight, max_weight_ind_set =  self.minWeightVertCover_Aux(self.getn(), selected, Weights)
    min_weight_vert_cover = list(set(range(self.getn())) - set(max_weight_ind_set))
    weight = 0
    for vert in min_weight_vert_cover:
      weight += Weights[vert]
    return weight, min_weight_vert_cover

  def minWeightVertCover_Aux(self, i, selected, Weights):
    if i == 0:
       return [0, []]
    else:
       s1 = self.minWeightVertCover_Aux(i-1, selected, Weights)
       if True not in [selected[j] for j in self.neighbors(i-1)]:
          selected[i-1] = True
          s2 = self.minWeightVertCover_Aux(i-1, selected, Weights)
          s2[0] += Weights[i-1]
          s2[1].append(i-1)
          selected[i-1] = False
       else:
          s2 = [0,[]]
       if s1[0] >= s2[0]:
          return s1
       else:
          return s2


  # problem2 minWeightVertCover2
  '''
  Write a method for finding a minimum weight vertex cover that works by reduction
  to maxWeightIndSet, which is already written for you.
  That is, the method should use a call to maxWeightIndSet to help it solve the problem,
  but it should work just like the one you wrote for the previous problem. If you think
  creatively, you will find a way to use it that requires only a tiny bit of code.
  '''
  def minWeightVertCover2(self, Weights):#IND set and Vert Cover are mutually exclusive (no overlap)
    max_weight_ind_set = self.maxWeightIndSet(Weights)[1]
    min_weight_vert_cover = set(range(self.getn())) - set(max_weight_ind_set)
    min_weight = 0
    for vert in min_weight_vert_cover:
      min_weight = min_weight + Weights[vert]
    return min_weight, min_weight_vert_cover

  #problem3 complement
  '''
  Write an UndirectedGraph method that returns the complement of the graph. The
  complement of G is a graph on the same vertex set (the integers from 0 through n-1)
  and that has an edge between two distinct vertices iff they don't hava an
  edge between them in G.
  This would set GPrime to contain a reference to a new graph representing the complement of G.
  '''
  def Complement(self):
    G = UndirectedGraph(self.getn(), []*self.getn())
    for vert in range(self.getn()):
      for edge in list(set(range(self.getn())) - set(self._verts[vert])):
        if vert == edge:#dont add a edge to yourself
          continue
        if edge not in G._verts[vert]:#dont add edges that already exist
          G.addEdge(vert, edge)
    return G

  #TODO problem 4
  '''
  A clique in a graph is a set X of vertices such that every pair of
  members of X has an edge between them.
  CLIQUE is the problem of determining whether a graph has a clique of a given size
  k. The problem is in the class NP, because if someone points out a clique of size k,
  it is easy to verify that they are telling the truth in polynomial time.
  INDEPENDENT-SET is known to be NP-complete in order to prove that WEIGHTEDINDEPENDENT-SET
  is NP-complete. Similarly, INDEPENDENT SET3 in the
  Python file is a reduction that uses the fact that INDEPENDENT-SET is known
  to be NP-complete to prove that VERTEX-COVER is NP-complete. Read about the
  reductions in the handout.
  Write a method that uses the fact that INDEPENDENT-SET is known to be NPcomplete
  to prove that CLIQUE is NP-COMPLETE. It must create a graph that has
  a clique of size k if and only if the given graph has an independent set of size k, and it
  must run in polynomial time. That way, if someone finds a polynomial algorithm to
  solve CLIQUE, it will imply a polynomial algorithm to solve INDEPENDENT-SET,
  which will imply one to solve every problem in NP.
  Its signature should be like this:
  def INDEPENDENT\_SET4(self,k):
  I have provided you with an exponential-time method for CLIQUE in NPCSupplement.py,
  so that you can try out your proof and see if your reduction of INDEPENDENT SET
  to CLIQUE works correctly.
  '''
  def INDEPENDENT_SET4(self,k):#only one element can be chosen if we find all cliques.
    max_clique = self.maxClique()
    if len(max_clique) >= k:
      pass

  # Check whether the graph has a clique of size k ...
  def CLIQUE (self, k):
     return len(self.maxClique()) >= k

  '''  Find a maximum clique in the graph '''
  def maxClique (self):
    selected = [False]*self.getn()
    return self.maxClique_Aux(self.getn(), selected)

  def maxClique_Aux(self, i, selected):
    if i == 0:
       return []
    else:
       s1 = self.maxClique_Aux(i-1, selected)
       NonNeighbors = frozenset(range(self.getn())) - frozenset(self.neighbors(i-1))
       if True not in [selected[j] for j in NonNeighbors]:
          selected[i-1] = True
          s2 = self.maxClique_Aux(i-1, selected)
          s2.append(i-1)
          selected[i-1] = False
       else:
          s2 = []
       if len(s1) > len(s2): return s1
       else:  return s2



  #TODO problem 5
  '''
   Look at the gadgets designed to get ASAT to determine the answer to various problems
  in NP. These are examples of the idea behind Cook's theorem, which is that a
  polynomial-time algorithm for ASAT would imply a polynomial-time algorithm for
  every problem in NP. It is a recipe for using the fact that there is a polynomial-time
  algorithm for checking a proposed certificate of a "yess"answer in order to provide
  a polynomial-time reduction to ASAT. Thus, a polynomial-time algorithm for ASAT
  would imply that P = NP. A variant of ASAT was the first NP-complete problem
  known. Before that, nobody realized that there existed such a problem in NP.
  Write a gadget that gets it to return the answer to the decision problem for SubsetSum:
  can you reach the target without going over. Hard-code the following instance:
  [35295649, 3183127, 8264528, 3292534, 2842252, 4414449, 6553326, 2821438]
  with a target of 47983761.
  Notice that when the numbers are too big, dynamic programming doesn't give us a
  good solution, because the size of the table is too great. This one would need almost
  50 million columns.
  The answer is "yes" for this instance. Change the target a little to see that you also
  get "no" answsers.
  Hint: The number of items to choose from is 8. Have the certificate consist of a
  Python list of length 8, where each element is either 0 or 1, indicating whether the
  corresponding item should be selected to reach the target.
  '''
  def SubsetSumGadget(Hint):
    pass



  #TODO problem 6
  '''
  Write a similar gadget for HAMILTONIAN-CYCLE. Use the other graph examples
  as a guide. Hardcode our running example of a graph. A certificate should be seven
  integers, each from 0 through 7. If they are not all distinct, the certificate is no good.
  It should give the sequence of vertices in the cycle, where the first vertex follows the
  last
  '''
  def HamTourGadget(Hint):
    pass

  # return a list of undirected edges
  def getEdges(self):
     edgeList = []
     for i in range(self.getn()):
        for j in self.neighbors(i):
           if j > i:
              edgeList.append((i,j))
     return edgeList

  ''' constructor.  numVerts tells how many vertices it should have.
      edgeList is a list of ordered pairs, one for each edge, in any order.
      Example: numVerts = 3 and edgeList = [(0,1), (1,2), (0,2), (2,0)]'''
  def __init__ (self, numVerts, edgeList):
    Graph.__init__(self, numVerts, [])
    for x,y in edgeList:
        self.addEdge(x,y)

  # add an undirected edge (two directed edges, opposite directions)
  def addEdge(self, i, j):
    self.neighbors(i).append(j)
    self.neighbors(j).append(i)
    self._m += 1

  ''' ---------------------------------------------------------------
  Exponential algorithms for some NP-hard optimization problems
    --------------------------------------------------------------- '''

  '''  Find a maximum independent set in the graph '''
  def maxIndSet(self):
    selected = [False]*self.getn()
    return self.maxIndSet_Aux(self.getn(), selected)

  def maxIndSet_Aux(self, i, selected):
    if i == 0:
       return []
    else:
       s1 = self.maxIndSet_Aux(i-1, selected)
       if True not in [selected[j] for j in self.neighbors(i-1)]:
          selected[i-1] = True
          s2 = self.maxIndSet_Aux(i-1, selected)
          s2.append(i-1)
          selected[i-1] = False
       else:
          s2 = []
       if len(s1) > len(s2): return s1
       else:  return s2

  ''' A maximum-weight independent set in a graph where Weights[i]
      is the weight of vertex i. '''

  # Find the weight of a maximum-weight independent set, and a max
  #  independent set
  def maxWeightIndSet(self, Weights):
    selected = [False]*self.getn()
    return self.maxWeightIndSet_Aux(self.getn(), selected, Weights)

  def maxWeightIndSet_Aux(self, i, selected, Weights):
    if i == 0:
       return [0, []]
    else:
       s1 = self.maxWeightIndSet_Aux(i-1, selected, Weights)
       if True not in [selected[j] for j in self.neighbors(i-1)]:
          selected[i-1] = True
          s2 = self.maxWeightIndSet_Aux(i-1, selected, Weights)
          s2[0] += Weights[i-1]
          s2[1].append(i-1)
          selected[i-1] = False
       else:
          s2 = [0,[]]
       if s1[0] >= s2[0]:
          return s1
       else:
          return s2

  # Find a minimum number of vertices in a vertex cover
  def minVertCover(self):
     selected = []
     return self.minCoverAux(self.getn(), selected)

  def minCoverAux(self, i, selected):
     if self.isVertexCover(selected):
        return selected
     elif i == 0:
        return range(self.getn())
     else:
        selectCopy = selected[:]
        s1 = self.minCoverAux(i-1, selectCopy)
        selectCopy = selected[:]
        selectCopy.append(i-1)
        s2 = self.minCoverAux(i-1, selectCopy)
        if len(s1) <= len(s2):
           return s1
        else:
           return s2

  ''' ----------------------------------------------------------------
  Reductions of decision problems to optimization problems
  ---------------------------------------------------------------- '''

  # Check whether the graph has an independent set of size k
  def INDEPENDENT_SET(self, k):
     return len(self.maxIndSet()) >= k

  # Check whether a weights graph has an independent set of weight w.
  #  Weights[i] is the weight of vertex i
  def WEIGHTED_INDEPENDENT_SET(self, w, Weights):
     return self.maxWeightIndSet(Weights)[0] >= w

  # Check whether the graph has a vertex cover of size k ...
  def VERTEX_COVER(self, k):
     if len(self.minVertCover()) <= k: return True
     else:  return False


  ''' ----------------------------------------------------------------
  Checkers of certificates of yes answers ...
  ---------------------------------------------------------------- '''

  #  Test whether an alleged independent set of size k really is one ...
  #  Hint is a frozenset of integers allegedly giving vertex numbers of
  #  an independent set
  def INDEPENDENT_SET_HINT(self, k, Hint):
     if len(Hint) < k: return False    # O(1) (polynomial) time
     return self.isIndSet(Hint)  # we know this takes polynomial time

  # Hint is a frozenset of vertex numbers;  return true if it is an
  #  independent set
  def isIndSet(self, Hint):
    n = self.getn()
    V = frozenset(range(n))
    if not Hint <= V:  return False
    for i in Hint:
       for j in self.neighbors(i):
           if j in Hint:
              return False
    return True

  #  Test whether an alleged weighted independent set of weight w really
  #  is an independent set and has weight w.  Hint is a frozenset of
  #  alleged vertex numbers of an independent set of weight w.  Weights[i]
  #  is the weight of vertex i
  def WEIGHTED_INDEPENDENT_SET_HINT(self, w, Weights, Hint):
     if max(Hint) >= self.getn(): return False
     if sum([Weights[i] for i in Hint]) < w:
         return False
     else:
         return self.isIndSet(frozenset(Hint))

  #  Test whether an alleged vertex cover of size k really is a vertex
  #  cover of size k.    Hint is a frozenset of integers, allegedly the
  #  vertex numbers of a vertex cover of size at most k.
  def VERT_COVER_HINT(self, k, Hint):
     if len(Hint) > k: return False
     else:  return self.isVertexCover(Hint)

  # Supplementary method for testing an alleged vertex cover.
  #  Return True if X is a vertex cover
  #  This obviously takes O(n+m), which is polynomial.
  def isVertexCover(self, Hint):
     marked = [False] * self.getn()
     for i in Hint: marked[i] = True
     for i,j in self.getEdges():
        if not marked[i] and not marked[j]:  # if some edge is uncovered
           return False
     return True

  #ind set 2
  ''' ----------------------------------------------------------------
  Reductions of INDEPENDENT_SET to WEIGHTED_INDEPENDENT SET
  and VERTEX_COVER
  ---------------------------------------------------------------- '''


  def INDEPENDENT_SET2(self, k):
     Weights = [1] * self.getn() # set all weights set to 1.  A max-weight
                                 # independent set is now a max independent set
     return self.WEIGHTED_INDEPENDENT_SET(k, Weights)

  def INDEPENDENT_SET3(self, k):
     return self.VERTEX_COVER(self.getn()-k)

#ASAT
''' ----------------------------------------------------------------
How to use ASAT to solve any problem in NP
---------------------------------------------------------------- '''

def ASAT(Method, k, maxValue):
    Input = [0]*k
    for i in xrange((maxValue+1)**k):
       if Method(Input):
          return True
       for j in range(k):
           if Input[j] < maxValue:
               Input[j] += 1
               break
           else:
               Input[j] = 0
    return False

'''
   Here's an example of how to use it to solve INDEPENDENT_SET.  Create
   the following program, hardcoding the instance of the problem you
   want to know about.  Hint is a Python frozenset of vertices that
   allegedly make up an independent set in the hard-coded graph
'''
def IndSetGadget(Hint):
    # Hard code the instance of the problem into the code
    NumVertices = 7
    Edges = [(0, 5), (0, 2), (0, 6), (1, 2), (1, 5), (2, 3), (4, 5), (5, 6)]
    IndSetSize = 5
    G = UndirectedGraph(NumVertices, Edges)

    RemoveIrrelevantBits(Hint, NumVertices-1)
    if G.INDEPENDENT_SET_HINT(IndSetSize, frozenset(Hint)):  return True
    else:  return False

'''
    Here's an example of how to use it to solve WEIGHTED_INDEPENDENT_SET.
    Hint is a Python frozenset of integers.  If it makes up a weighted
    independent set of TargetWeight in the hard-coded graph, it returns
    True, otherwise it returns False
'''
def WeightedIndSetGadget (Hint):
    # Hard code the instance of the problem into the code
    NumVertices = 7
    Edges = [(0, 5), (0, 2), (0, 6), (1, 2), (1, 5), (2, 3), (4, 5), (5, 6)]
    G = UndirectedGraph(NumVertices, Edges)
    Weights = [1,1,2,2,1,6,3]
    TargetWeight = 8

    RemoveIrrelevantBits(Hint, NumVertices-1)
    if G.WEIGHTED_INDEPENDENT_SET_HINT(TargetWeight, Weights, frozenset(Hint)):
       return True
    else:
       return False


'''
    Hint is a frozenset containing one integer other than 1 or n.  If it is a
    factor of n, it returns True; otherwise it returns false.
'''
def CompositeGadget(Hint):
    n = 998353

    RemoveIrrelevantBits(Hint, 1023)
    i = Hint[0]
    if i <= 1 or i == n:
        return False
    elif n % i == 0:
        return True
    else:
        return False

def SATGadget(Hint):
    RemoveIrrelevantBits(Hint, 1)
    X = [False] * 4
    for i in range(4):
       if Hint[i] == 1:
           X[i] = True
    return (not X[0] or X[1]) and (not X[1] or X[2]) and (not X[2] or X[3]) and (not X[3] or not X[0]) and X[0]

# Next power of two greater than n
def nextPowerTwo(n):
  i = 1
  while i <= n:
     i *= 2
  return i

# A is a list of integers.
# Zero out all bits of each element oF A except for those needed to
#  store an integer as large as maxValue
def RemoveIrrelevantBits(A, maxValue):
  p = nextPowerTwo(maxValue)
  for i in range(len(A)):
     A[i] = A[i] % p

def readUndirectedGraph(filename):
  edgeList = []
  fp = open(filename, 'r')
  n = int(fp.readline())
  for line in fp:
     u,v  = [int(x) for x in line.split(',')]
     edgeList.append((u,v))
  return UndirectedGraph(n, edgeList)

'''  *************************************************************
     That's all for the lesson; rest is utility functions.
     *************************************************************
'''

'''  Read a graph in from a file.  The format of the file is as follows:
     The first line gives the number of vertices.
     Each subsequent line gives a pair of vertices, separated by
     a comma, indicating an undirected edge.

     Example:
     ----
     3
     0,1
     1,2
     0,2
     ----

     This gives a graph with three vertices and three undirected edges,
     {0,1}, {1,2}, {0,2}
'''


# generate a random graph on n vertices
def randGraph(n):
  E = [(i,j) for i in range(n) for j in range(i+1,n) if random.randrange(0,30) == 0]
  return UndirectedGraph(n, E)

if __name__ == '__main__':
   E = [(0, 5), (0, 2), (0, 6), (1, 2), (1, 5), (2, 3), (4, 5), (5, 6)]

   G = UndirectedGraph(7, E)

   print ('Graph:   ' + str(G))

   print('\nList of edges: ' + str(G.getEdges()))
   Weights = [1,1,2,2,1,6,3]
   print 'Weights ', Weights

