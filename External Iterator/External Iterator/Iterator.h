#ifndef __ITERATOR__
#define __ITERATOR__
#include "Node.h"

class Iterator
{
public:
    Iterator(Node *start); // The iterator initially points to "start".
    int operator*(); // dereference the iterator
    Iterator operator++(); // advance the iterator
    bool operator!=(const Iterator& other); // returns true if and only if other iterator does not equal this iterator
    bool is_item(); // returns true if Iterator points to a valid Node (if nullptr return false…)
    
private:
    Node* selected;
};

#endif
