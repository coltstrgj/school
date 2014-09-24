#include <cstdlib>
#include "ll.h" 

using namespace std;

LinkedList::LinkedList(): m_pHead(NULL){}


//LinkedList::Link(unsigned int uiData, LinkedList::Link *pNext) : m_uiData(uiData), m_pNext(pNext) {}
void LinkedList::Link::Initialize (unsigned int uiData, Link *pNext) {
    m_uiData = uiData;
    m_pNext = pNext;
}



void LinkedList::Initialize() {
    m_pHead = NULL;
}

bool LinkedList::Insert (unsigned int uiData) {
    Link* new_link = new Link;

    new_link->Initialize (uiData, m_pHead);
    m_pHead = new_link;

    return true;
}

bool LinkedList::Delete (unsigned int &Data) {

    bool ret_val = false;

    if (m_pHead != NULL) {
	Link *temp = m_pHead;
	m_pHead = m_pHead->m_pNext;
	Data = temp->m_uiData;

	ret_val = true;
	delete temp;

    }

    return ret_val;
}



void LinkedList::Print(std::ostream &os){
	Link *tmp = m_pHead;
	os<<"Elements:{";
	while(tmp!=NULL){
		os<<tmp->m_uiData<<endl;	
	}
	


}
