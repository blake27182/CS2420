//
//  Node.hpp
//  BinarySearchTree
//
//  Created by Blake Williams on 7/29/19.
//  Copyright © 2019 Blake Williams. All rights reserved.
//

#ifndef Node_h
#define Node_h

#include <stdio.h>
#include "Observer.h"

class Node{
public:
    Node();
    Node(int data, Node* left, Node* right);
    ~Node();
    
    bool IsLeaf();
    void UpdateHeight();
    
    int data;
    int height;
    Node* leftChild;
    Node* rightChild;

private:
    Observer neededForUnittest;
    
};

#endif /* Node_hpp */
