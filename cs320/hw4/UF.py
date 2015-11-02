class UF:
  def __init__ (self, elements):
    self._l = [[i] for i in range(elements)]
    self._id = [i for i in range(elements)]
    self._numElements = elements

#To be able to print out the classes, you will need to write a toString-type method.
# Use the str methods from the Graph or WGraph class as a guide. Your method
# output should match what I have displayed above, character-for-character, so that
# we can grade the output with a script. (Also, formatting in Python is part of this
# exercise.)
  def __str__ (self):
    return "id: " + str(self._id) + "\nl: " + str(self._l)


#You should write a getn() method that returns the number of elements in all of the
# classes. This will never change as unions occur.
  def getn(self):
    return self._numElements
#update the parent class after find, if needed, not durring merge.
  def find(self, element):
#Book would uncomment this next part and do it this way instead of way in union
#   ParClass = self._id[element] #set the original parent class of element to its parent class
#   toUpdate = []
#   while ParClass != element:#if parent class is not the name of element, then it is not the base
#     toUpdate.append(element)
#     element = ParClass
#     ParClass = self._id[element]
#   for i in toUpdate:#update the parent class id number
#     self._id[i] = ParClass
#   return ParClass
    return self._id[element]


#Write your union method so that it returns False and returns without doing anything
# if both of the parameters are currently already in the same class. Otherwise, it must
# merge the classes and return True.
  def union(self, class1, class2):#in book, we dont update all id's here, just classid (head of the class that was changed)
    C1 = self.find(class1)
    C2 = self.find(class2)
    if C1 == C2:#from book subsequent calls to find should be O(1) provided it has not been unioned, but C1 and C2 are easier to Read
      return False
    if len(self._l[C2]) > len(self._l[C1]):#if class 2 is larger, append class1 to That
      self._l[C2].extend(self._l[C1])
      for C in self._l[C1]:#this is the part that book does in find
        self._id[C] = C2
      self._l[C1] = None
      self._id[C1] = C2
      return True
    self._l[C1].extend(self._l[C2])
    for C in self._l[C2]:
      self._id[C] = C1
    self._l[C2] = None
    self._id[C2] = C1
    return True


##This was taking too long, so I will just use lists instead of class because it should be better anyway
##class l:#l[j] is a reference to a Python list giving the elements for class j. l[j] should be None if no class currently has that I.D. number.
##  def __init__ (self, listVerts):
##    self._elements = listVerts
##  def __str__ (self):
##    return str(self.elements)
##class id:#id[i] tells id number of union-find class that element i is in
##  def __init__ (self, idNum):
##    self._idNum = idNum
##    print(idNum)
##    print(" " + str(self._idNum))
##  def __str__ (self):
##    return str(self.idNum)
