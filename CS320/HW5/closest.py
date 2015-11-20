from time import time
import math
import random

'''
FORMATTING CONVENTION

The convention for formatting a list of points in this program is to use
a list of lists of pairs of floating-point values.  The first
element in each pair is the x coordinate of a point and the second
is its y coordinate.  There must be at least two points in a list.

Example:  [[3.2,5.8],[4.7,1.2]]
'''

'''
Read a set of points from a file.
Prconditions:  The file consists of two floating-point values per
  line, where the first gives the x coordinate of a point and the
  second gives its y coordinate.
Postconditions:  the returned list is a list of the points, adhering
  to the formatting convention (above)
'''
def readPts(filename):
  fp = open(filename)
  Lines = [line for line in fp]
  L = [[float(i) for i in line.split()] for line in Lines]
  return L

'''
Merge of mergesort, for sorted lists of points.
Preconditions:  S1 and S2 are two lists of lists of size two, adhering
  to the formatting convention (above).  In addition, coord is either 0 or 1.
  If it is 0, then the two lists must be sorted by x coordinate
  and if it is 1, they must be sorted by y coordinate.
Postconditions:  The returned list is the union of the two lists.
  If coord == 0, it is sorted by x coordinate and if coord == 1, it
  is sorted by y coordinate.
'''
def mergePts(S1, S2, coord):
  i=j=0
  S = []
  while (i<len(S1) and j<len(S2)):#should exit when either of the lists are done (finish the other below)
    if S1[i][coord] < S2[j][coord]:
      S.append(S1[i])
      i += 1
    else:
      S.append(S2[j])
      j += 1
  S = S + S1[i:]
  S = S + S2[j:]
  return S

'''
Mergesort for a list of points.
preconditions:  S is a set of points adhering to the formatting convention
  (above), and coord is 0 or 1
postconditions:  if coord == 0, the returned list is the elements of S
  sorted by x coordinate, and if coord == 1, the returned list is the
  elements of S sorted by y coordinate.
'''
def msPts(S, coord):
  if len(S) > 1:#supposed to break it down into size 2 lists, but why when I could be lazy instead
    S1 = msPts(S[:len(S)/2], coord)
    S2 = msPts(S[len(S)/2:], coord)
    S = mergePts(S1, S2, coord)#could be done on one line, but this makes it more readable
  #else we are done
  return S

'''
This is an O(n^2) closest-pair algorithm.  (Using this as the base case
 prevents us from having to consider what answer to return if there
 is only one point in the list).  It should examine all pairwise
 squared distances and pick the minimum squared distance found, as well
 as a pair of points whose square of distance has this value.

 You can also apply it to large sets of points, to compare its running
 time to what you wrote.  If your solution does not get dramatically
 faster as the number of points gets large, you have messed up something
 in your analysis of your time bound.

 preconditions:  S is a set of points in two-space.
 postconditions:  S is sorted by y coordinate.
 The returned values are the square of the distance
 between the closest pair of points, and a list of two points
 adhering to the formatting convention (above), giving the closest
 pair, and a list of points in S sorted by y coordinate

'''
def brute(S):
  min_dist = distsq(S[0], S[1]) #keep track of min distsq
  loc = min_p1 = min_p2 = 0 #keeps track of the values of the coordinate
  y_sort = msPts(S, 1)
  for i in y_sort:
    loc += 1
    for j in y_sort[loc:]:#everything before loc has already been compared to whatever we are on
      tmp = distsq(i, j)
      if tmp < min_dist:
        min_dist = tmp
        min_p1 = i
        min_p2 = j

  return min_dist, [min_p1, min_p2], y_sort  # fill in return square of dist, closest points, list of points sorted by y coordinate

'''
Find the closest pair in S

Precondition:  S conforms to the formatting convention, and no two points
  have the same x coordinate
Postcondition:  A tuple has been returned whose first element is the min
  distance squared, and whose second element is a list of two points.
'''
def closest(S):
  X = msPts(S, 0) #sort by x coordinate
  return closestAux(X)



'''
preconditions:  X is the set of points in the plane, no
    two of which share the same x coordinate.  X is sorted by X coordinate.
postconditions:
  The returned tuple is the square of the distance of
  the closest pair, and a list of size two giving a closest pair,
  and a list of the points of X, sorted by y coordinate
'''
def closestAux(X):
  points = []
  S = []
  delta = min_dist = 0
  if len(X) <= 3:
    return brute(X) #the brute force method will be fast for 3 elements
  #Else we need to do more things
  Q = X[0:len(X)/2]
  R = X[len(X)/2:]
  R_delta, R_points, R_ylist = closestAux(R)
  Q_delta, Q_points, Q_ylist = closestAux(Q)
  if Q_delta < R_delta:
    min_dist = delta = Q_delta #assign min_dist in case it does not get assigned later due to small S list
    points = Q_points
  else:
    min_dist = delta = R_delta
    points = R_points
  L = Q[len(Q)-1][0] #they are sorted by x, so get last element to get right most x vaule in Q
  for element in reversed(Q):#reversed just traverses backwards, no overhead
    if L - element[0] > delta:#if it is larger than delta, it cang be in list s
      break
    #else
    S.append(element)#if order ends up not mattering
    #S = mergePts(S, [element], 0)#otherwise, add it to list S. This will be at most 15 points, so doesn't matter how we append to the list (as long as it is still sorted by x, hence the merge)
  for element in R:
    if element[0] - L > delta: #if this point is farther than delta, we are done
      break
    #else
    S.append(element)
  if len(S) > 1:
    min_dist, points, trash = brute(S) #dont need Y sorted return because we already have it. in O(n) time, and this would just complicate things
    if delta < min_dist: #if delta is actually smaller than smallest here, it is smallest
      min_dist = delta
  Y = mergePts(Q_ylist, R_ylist, 1) #merge them back together by y coordinate
  return min_dist, points, Y

##############################################

#Seems like we can break these pieces in half x wise until there is one left, then merge sort them back into a y sort and have both lists. (when there is only one point, it is in coreect order, so if we merge, we are fine, after that, it is a merged list so it will be ordered correctly too.)Do this recursion in closestAux?where do we get y sorted list?

##############################################
'''
Find the square of the distance between two points.
Preconditions:  p1 and p2 are two points in the plane
  where the first element in each list is the x coordinate and the second
  is the y coordinate.
Postcondition:  the square of the distance between the two points has
  been returned
'''
def distsq(p1, p2):
  return ((p1[0]-p2[0])**2 + (p1[1]-p2[1])**2)

'''One way to test out the correctness and efficiency of your code is
to uncomment some of the following:
'''

if __name__ == '__main__':
  pass
# ''' ************************************* '''
# #S = readPts('points.txt')

# size = int(input("Enter number of points:  "))
# print size
# S = [[random.random(), random.random()] for i in range(size)]
# print S

# start=time();
# Soln = closest(S)
# end = time();
# print '\n    Solution for closest: ', Soln
# print '\n     Elapsed for closest: ', end - start
# fast = end - start
# start = time()
# Soln = brute(S)
# end = time()
# print '\nSolution for brute-force: ', Soln
# print '\n Elapsed for brute-force: ', end - start
# brute = end - start
# print '\nRatio closest/brute-force: ', fast/brute
