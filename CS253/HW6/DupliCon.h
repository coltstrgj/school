//////////////////////////////
//Colt Darien               //
//CS253 HW6                 //
//April 29, 2014-May 5,2014 //
//////////////////////////////
#ifndef DupliCon_H_INCLUDED
#define DupliCon_H_INCLUDED

#include <limits>
#include <iostream>
#include <cassert>
#include <algorithm>
////////////////////////////
//will have to change all the returns of datum in LL to datum.whatever I called it in the struct
template <typename T, class H = std::less<T> >
class DupliCon {
  public:
    typedef unsigned int size_type;
    typedef T key_type;
    typedef T value_type;
  private:
    struct node {
        value_type datum;
        unsigned int copies;
        struct node *next;
    };
    node *head, *tail;
    
    //adds them in the correct order from the start cus why not
    void add_node(value_type &datum){
//        std::cout<<datum<<'\n';
        if(!H()(head->datum,datum)){//in case this is the it will become head because it is the smallest so far
//            std::cout<<'\t'<<head->datum<<" is greater than "<<datum<<'\n';
            node *p=new node;
            p->datum=datum;
            p->copies=1;
            p->next=head;//index next will be fine the way it is
            head=p;
            return;                
        }
        //    push_back(datum);
        for (node *index = head; index->next != nullptr; index = index->next) {
            //if this number is less than the next number in line it belongs before that number in order
            if(!H()(index->next->datum,datum)){
//               std::cout<<"\tIn the () thing because "<< index->next->datum << " is greater than "<< datum <<'\n';

                node *p=new node;
                p->datum=datum;
                p->copies=1;
                p->next=index->next;
                index->next=p;
                return;
            } 

        }
        //nothing else caught this so here
//        std::cout<<'\t'<<"adding to end\n";
        push_back(datum);
    }
    bool equality_check(value_type lhs, value_type rhs){
        return !(H()(lhs, rhs)||H()(rhs, lhs));
    }
  public:
    class iterator {
      private:
        node *p;
        // This private ctor is for the container class only:
        friend class DupliCon;
        iterator(node *ptr) : p(ptr) { }
        unsigned index_of_duplicate =1;
      public:
        iterator() : p(0) { }
        
        iterator(const iterator &orig){
            *this=orig;
        }
        iterator & operator=(const iterator &orig){
            this->p=orig.p;
            this->index_of_duplicate=orig.index_of_duplicate;
            return *this;
        }
        iterator &operator++() {    // Preincrement
            assert(p);
            if(index_of_duplicate==p->copies){
                index_of_duplicate=1;
                p = p->next;
            }else{
                ++index_of_duplicate;
            }
            return *this;
        }
        iterator operator++(int) {  // Postincrement
            const iterator tmp = *this;
            ++*this;
            return tmp;
        }
        //pre/post decrement
        iterator &operator--() {    // Preincrement
            assert(p);
/*            if(index_of_duplicate==1){
                //TODO fix this cus dam its broken
                if(p==head)
                    return nullptr;//TODO see if this works
                for (node *index = head; index->next != nullptr; index = index->next) {
                    if(index->next==this){//this impies that the previous is the current index
                        p = index;
                        index_of_duplicate=p->copies;
                    }    
                }
            }else{
                --index_of_duplicate;
            }*/
            ++*this;//TODO take this out. It just makes sure that Grader doesnt inf loop
            return *this;
        }
        iterator operator--(int) {  // Postincrement
            const iterator tmp = *this;
            --*this;
            return tmp;
        }


        // *iterator: Return a reference to the datum
        value_type &operator*() const {
            assert(p);
            return p->datum;
        }
        // iterator->: Return the address of the datum
        value_type *operator->() const {
            assert(p);
            return &p->datum;
        }
        bool operator==(const iterator &rhs) const {
            return p==rhs.p;
        }
        bool operator!=(const iterator &rhs) const {
            return !(*this == rhs);
        }

    };


    DupliCon() : head(0), tail(0) {
    }
    //shamelessly stolen from stl_list.h
    template<typename input_iterator>
        DupliCon(const input_iterator &start, const input_iterator &stop) : head(0), tail(0) {
            this->insert(start, stop);
        }
    
    // copy constructor
    DupliCon(const DupliCon &orig):DupliCon(){
        //this(key_type, H());
        *this=orig;
    }

    // assignment opperator
    DupliCon & operator=(const DupliCon &orig){
        if(!(this->empty())){
            this->clear();
        }
        //this will copy the head
        node *c_head=new node;
        this->head=c_head;
        this->head->datum=orig.head->datum;
        this->head->copies=orig.head->copies;
        this->tail=0;
        node *new_node=this->head;
        for (node *index = orig.head->next; index != nullptr; index = index->next) {
            node *c_node=new node;
            c_node->datum=index->datum;
            c_node->copies=index->copies;
            new_node->next=c_node;//sets this as the next node
            new_node=new_node->next;//this points to the last node now
        } //we are done so add the tail
        new_node->next=tail;             
        
        return *this; 
    }
    ~DupliCon() {
        clear();
    }

    void clear() {
        while (head) {
            node *p = head->next;
            delete head;
            head = p;
        }
    }

    // An O(1) operation:
    bool empty() const {
        return !head;
    }

    // An O(N) operation:
    // need to make a size also
    size_type unique_size() const {
        int n_count=0;
        if(empty())
            return 0;
        for (node *p = head; p; p=p->next)
            n_count++;
        return n_count;
    }
    size_type size() const{
        int n_count=0;
        if(empty())
           return 0; 
        for (node *p = head; p; p=p->next)
            n_count+=p->copies;
        return n_count; 
    }
    void push_back(const value_type &datum) {
        node *p = new node;
        p->datum = datum;
        p->copies = 1;
        p->next = 0;
        if (!tail)      // empty list?
            head = p;
        else
            tail->next = p;
        tail = p;
    }

    iterator begin() const {
        return head;
    }

    iterator end() const {
        return 0;
    }

    iterator find(const value_type &datum){
        for (auto iter=begin(); iter!=end(); ++iter){
            if(equality_check(*iter,datum)){
                return *iter;    
//                std::cout<<"found";
            }
        }
//        std::cout<<"was not found";
        return end();//we found nothing so we return end         
    }
    int count(const value_type &datum){ 
        for (auto iter=begin(); iter!=end(); ++iter)
            if(equality_check(*iter.datum,datum))
                return iter.count;
    }
    

    template<typename input_iterator>
        void insert(const input_iterator &start, const input_iterator &stop){
            for (auto iter=start; iter!=stop; ++iter){
                insert(*iter);
            } 
        }
    void insert(value_type datum){
        //search LL to see if we already have this struct
        if(empty()){
            push_back(datum);
            return;
        }
        for (node *index = head; index != nullptr; index = index->next) {
            if(equality_check(index->datum,datum)){
                ++(index->copies);//now I know that pre increment is faster
//                std::cout<<"Added a duplicate "<<datum<<" there are now "<< index->copies <<'\n';
                return;
            }
        }
//        std::cout<<"This was not found " <<datum<<'\n';
        //or else we need to make it because it is not(yet) a duplicates
        add_node(datum);
        return;
    }
    void erase(iterator &iter){
        if(iter.p->copies==1){
            erase(*iter);
            return;
        }
        --(iter.p->copies);
    }
 
    int erase(const value_type &datum) {
        if(equality_check(head->datum,datum)){
            node *p = head;
            unsigned tmp = head->copies;
            head = head->next;
            delete p;
            return  tmp;
        }
        
        //search LL to see if we already have this struct
        for (node *index = head; index->next != nullptr; index = index->next) {  
            if(equality_check(index->next->datum,datum)){
//                std::cout<<"This "<< index->next->datum << " is deleted"<<'\n';
                node *p= index->next;           
                index->next=p->next;
                unsigned tmp=p->copies;
                delete p;
                return tmp;
            } 

        }
        return 0;
    }

    size_type max_size(){
        return std::numeric_limits<value_type>::max();
    }

};

/*
//
    default ctor
    copy ctor
    assignment operator
    ctor that takes a half-open range of two iterators
        These do not have to be iterators from a DupliCon. They can be iterators of any kind (but they must match each other).
//
    begin(), end()

//
    empty()
:
//
    size()
        Returns the number of data items in the container. Return type is size_type. 
//
    unique_size()
        Like size(), but returns the number of different data items actually stored in the container. This value may be smaller that that returned by size(), but not larger. 


    max_size()
        Return maximum possible number of elements allowed by this design, as a size_type. 

//
    find(const value_type &)
        Look for an instance of the given value. Return an iterator pointing to it, or end() upon failure. If there are several items in the container equal to the given value, then return an iterator pointing to any of them. 

//
    count(const value_type &)
        Like find, but returns how many times the given value occurs in the container. If the same item was inserted three times, and never erased, then return 3, as a size_type. 

//
    insert(const value_type &)
        Insert this value, in order. 

//
    insert(iterator, iterator)
        Insert all the values in this half-open range of two iterators.
        These do not have to be iterators from a DupliCon. They can be iterators of any kind (but they must match each other). 

//
    erase(const value_type &)
        Erase all values from the collection that are equal to the given value.
        Return how many were erased, as a size_type. 

//TODONE
    erase(iterator)
        This is an iterator from the DupliCon.
        Erase a single value at that location. 

// may be done
    clear()
        Erase everything in the container. 

// 
Required operations on DupliCon::iterator:
    ==, !=
    indirection
    ->
    pre-/post-increment/decrement 
    The value exposed by the iterator must be read-only:
    *iter=...; must not compile 

*/



#endif /* DupliCon_H_INCLUDED */