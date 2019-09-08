//
//  BinarySearchTree.hpp
//  BinarySearchTree
//
//  Created by Blake Williams on 7/29/19.
//  Copyright © 2019 Blake Williams. All rights reserved.
//

#ifndef BinarySearchTree_h
#define BinarySearchTree_h

#include <stdio.h>
#include <iostream>
#include "Node.h"

class BinarySearchTree{
public:
    BinarySearchTree();
    ~BinarySearchTree();
    void DestructionHelper(Node* cursor);
    
    void Insert(int data);
    Node* Search(int data);
    void Remove(int data);
    void InorderTraversal();
    void Print();
    int Size();
    
    Node* root;
    
private:
    Node* InsertHelper(Node* cursor, int data);
    Node* SearchHelper(Node* cursor, int data);
    Node* RemoveHelper(Node* cursor, int data);
    void InorderHelper(Node* cursor);
    void PrintHelper(std::string& offset, Node* cursor);
    int SizeHelper(Node* cursor);
    Node* FindMin(Node* cursor);
    Node* FindMax(Node* cursor);
};

#endif /* BinarySearchTree_hpp */
