#ifndef __NODE__
#define __NODE__
#include "Observer.h"

class Node
{
public:
    Node() = default;
    Node(int value){data = value; next = nullptr;};
    ~Node() = default;
    
    Node* next;
    int data;

private:
    Observer tmp;  // for testing purposes only. DO NOT REMOVE
};

#endif
