//
//  Node.cpp
//  BinarySearchTree
//
//  Created by Blake Williams on 7/29/19.
//  Copyright © 2019 Blake Williams. All rights reserved.
//

#include "Node.h"
#include <iostream>

Node::Node(){
    data = -1;
    leftChild = nullptr;
    rightChild = nullptr;
    height = -1;
}

Node::~Node(){
    
}

Node::Node(int data, Node* left, Node* right){
    this->data = data;
    rightChild = right;
    leftChild = left;
    height = 0;         // put real data here
}

bool Node::IsLeaf(){
    if (leftChild == nullptr && rightChild == nullptr)
        return true;
    return false;
}

void Node::UpdateHeight(){
    int left = -1;
    int right = -1;
    if (leftChild){
        left = leftChild->height;
    }
    if (rightChild){
        right = rightChild->height;
    }
    if (left > right){
        height = ++left;
    } else {
        height = ++right;
    }
}
