#ifndef __LIST__
#define __LIST__
#include "Node.h"
#include "Iterator.h"

class List
{
public:
    List();
    ~List();
    
    void push_back(const int& value);       // add new node to back of the list
    void push_front(const int& value);      // add new node to front of the list
    void PrintList();                    // mainly for debugging
    void remove(const int& value);          // removes ALL nodes in list with this value
    Iterator begin();                        // iterator to the beginning of the list
    Iterator end();                          // iterator to the end of the list
    int size();                         // number of elements currently in list
    void DeleteNotHead(Node* precursor);
    void DeleteHead();
    
private:
    void deallocator(Node* cursor);
    Node* head;
    Node* tail;

};

#endif
