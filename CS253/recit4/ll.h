#include<i:ostream>
#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_ 

class LinkedList {
  public:
	LinkedList();
	void Initialize();
	bool Insert(unsigned int uiData);
	bool Delete(unsigned int &pData);
	void Print(std::ostream &os);
	void	
  private:
    struct Link {
	unsigned int m_uiData;
	Link* m_pNext;
	//LinkedList::Link::Link(unsigned int uiData, Link *pNext);
	void Initialize (unsigned int uiData, Link *pNext);
    } *m_pHead;
};

#endif /* _LINKED_LIST_H_ */ 
