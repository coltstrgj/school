# -*- coding: utf-8 -*-
# Heap class: The internal variables are:
# self._H: Heap array as defined in the book
# self._allocation: size of self._H; some elements at the end of this
# array might be unused. This is always a power of two.
# self._size: Number of elements currently stored in self._H; this
# is always at least self._allocation/4 and at most self._allocation
class Heap(object):

    # constructor: create a heap with allocation 1 and size 0:

    #This is where the instance variables for the class are defined.
    # ’self’ is the Python equivalent of ’this’. Python requires you
    # to mention ’self’ explicitly in a lot of contexts where ’this’
    # can be omitted in Java.
    #
    # To call it, execute P = Heap(); this assigns a reference to an
    # empty heap to variable P. (It implements the "priority queue" ADT.)
    def __init__(self, k):
        self._H = [0]
        self._size = 0
        self._allocation = 1
        self._k = k

    # get current size
    # If P contains a reference to it, then call it with P.getSize()
    # The P before the dot will assign a reference to the parameter ’self’
    def getSize(self):
        return self._size

    # get current allocation
    def getAllocation(self):
        return self._allocation

    # get a reference to the heap array
    def getArray(self):
        return self._H

    # Find the parent of index pos, or return None if it’s the root.
    # There is no check to see if pos >= self._size
    # Example of a call: P.parent(i). This assigns the reference in P
    # to ’self’ and the reference to the integer in pos to i.
    def parent(self, pos):
        if pos <= 0: return None
        else: return (pos - 1) / self._k

    # Swap the elements at pos1 and pos2 of the heap array. Leave the
    # structure unchanged if one or more of the indices are not in
    # {0, 1, 2, ... getSize()-1}. Otherwise, swap the elements.
    def swap (self, pos1, pos2):
        s = self.getSize()
        if 0 <= pos1 and 0 <= pos2 and pos1 < s and pos2 < s:
            self._H[pos1], self._H[pos2] = self._H[pos2], self._H[pos1]

    # insert integer to heap. Call: P.insert(i)
    def insert(self, item):
        # double allocation of array if it’s full. This takes time
        # proportional to the number n of items in the heap, but
        # the last time it happened, the heap had n/2 elements in it.
         #Averaging the cost of this over the n/2 insertions that have
        # taken place since this gives a constant average (amortized) cost
        # per insertion.
        if self._size == self._allocation:
            self._H = self._H[:] + [0] * self._allocation
            self._allocation = self._allocation * 2

        # insert the item at the end ...
        self._H[self._size] = item
        pos = self._size
        self._size += 1
        # restore the heap property by bubbling it up to a point where
        # it’s at the root or its parent’s key is at least as small ...
        while pos > 0 and self._H[self.parent(pos)] > self._H[pos]:
            self.swap(self.parent(pos), pos)
            pos = self.parent(pos)

    # Return the index of child number i of the node at position pos.
    # Preconditions are that pos is a valid index. It will return
    # the index of this child, whether or not it exists and whether
    # or not its position is beyond the end of the heap array
    def childIndex (self, pos, i):
        return (pos * self._k) + i + 1 #fix the two later to be 'k' +1 because arrays start from 0 not 1

    # Tell the key in child number i (i in {0,1}) of the node at position ’pos’
    # of heap array. If there is no such child, return None. Precondition
    # is that i is in {0,1}
    def child (self, pos, i):
        if (pos * self._k) + i + 1 > self.getSize() - 1:
            return "None"
        tmp = self.getArray()
        return tmp[(pos * self._k) + 1 + i]


    """
    Return a list of keys at children of the node at position pos.
    Return None if ’pos’ is not in {0, 1, 2, ... size-1}
    If it is, it might have 2, 1 or 0 children; return a list of length 2, 1
    or 0.
    Here’s a hint: create a list of self.child(pos,i) for i in
    [leftChild, leftChild+1]. One or both of these could be None,
    indicating the child doesn’t exist. Create and return a new
    list that is equal to this list, but with the None values omitted.

    """
    def children(self, pos):
        if pos + 1 > self.getSize():
            return []
        child_list = []
        for i in range(0, self._k):
            key = self.child(pos, i)
            if key != "None":
                child_list = child_list + [key]
        return child_list

    # Extract the minimum element of the heap, and restore the heap property.
    # See our book for the algorithm.
    def extractMin(self):
        # double allocation of array if it’s full. This takes time
        # proportional to the number n of items in the heap, but
        # the last time it happened, the heap had n/2 elements in it.
         #Averaging the cost of this over the n/2 insertions that have
        # taken place since this gives a constant average (amortized) cost
        # per insertion.
        if self._size - 1 == self._allocation/4:
            self._H = self._H[0:self._allocation/2] #is this or self._H[0:self._allocation/4]+[0] * self._allocation*4 faster?
            self._allocation = self._allocation/2

        if self._size == 0:
            return "Empty"
        # insert the item at the end ...
        min_item = self._H[0]
        self._H[0] = self._H[self._size - 1] #move the last element to min position
        self._H[self._size - 1] = 0 #zero the unused element (for debug, really isnt important other than for getArray())
        self._size -= 1
        # restore the heap property by bubbling it down to a point where
        # it’s at last spot  or its children are at least as large and parents
        # are at least as small
        #print str(self.getArray())
        self.heapify(0)
        return min_item

    '''
        In a subtree rooted at pos in which the only place where the heap
        property does not apply is at the root, restore the heap property.
        A precondition is that 0 <= pos < self._size.
        Here’s a hint: call self.children(pos). If the returned list C
        is empty, the element at ’pos’ has no children, and the heap
        property applies. Otherwise, if min(C) > self._H(pos),
        the heap property applies. Otherwise, you can find which child
        number contains the minimum key with childNum = C.index(min(C)). (Look
        up this ’index’ method.) You can tell the index of this child
        in self._H with a call to self.childIndex(pos, childNum).

    '''

    def heapify(self, pos):
        children = self.children(pos)
        if not children : #if this has no children we are at the bottom, we are done
            return
        #otherwise we have to do this again
        min_child = min(children)#only want to run this once
        if self._H[pos] > min_child:
            #we have to swap them
            min_child_pos = self.childIndex(pos, children.index(min_child))
            self.swap(pos, min_child_pos)
            pos = min_child_pos #we swapped so we have to recurse
            self.heapify(pos)

        return
    """
        Create a string that is suitable for displaying structure of the heap
        To print the heap array, print P._H. This one displays which key
        is a child of which using indentation. For example:
        3
            5
                10
                29
            4
                20
                15
        The least indented element, 3, is at the root. Its children
        are the elements 5 and 4 at the next level of indentation.
        The two elements at the next level of indentation following 5,
        namely, 10 and 29, are the children of 5. Similarly, 20 and 15
        are the children of 4.

    """

    # '''
    #I’ve commented it out because it won’t work until you’ve written
    #some of your methods ...
    def __str__(self):
        if self.getSize() == 0: return ""
        else: return self.strAux(0, 0, "")

    def strAux(self, pos, depth, outString):
        outString = outString + "\n" + '|' * depth + str(self._H[pos])#changed ' ' to '|' for visibility
        children = self.children(pos)
        for i in range(len(children)):
            outString = self.strAux(self.childIndex(pos,i), depth+1, outString)
        return outString

    #'''
if __name__ == "__main__":
    P = Heap(3)
    P.insert(10)
    P.insert(5)
    P.insert(15)
    P.insert(3)
    P.insert(29)
    for i in range(11, 22):
        P.insert(i)
    print"Heap array: " + str(P.getArray())
    print"Size: " + str(P.getSize())
    print"allocation " + str(P.getAllocation())
    # This will print the structure of the heap once you’ve written
    # your other methods, because of the __str__ method I’ve written
    print P
