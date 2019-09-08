//
//  BinarySearchTree.cpp
//  BinarySearchTree
//
//  Created by Blake Williams on 7/29/19.
//  Copyright © 2019 Blake Williams. All rights reserved.
//

#include "BinarySearchTree.h"
#include "Node.h"
#include "RecursionCounter.h"

BinarySearchTree::BinarySearchTree(){
    root = nullptr;
}

BinarySearchTree::~BinarySearchTree(){
    DestructionHelper(root);
    delete root;
}

void BinarySearchTree::DestructionHelper(Node *cursor){
    if (cursor->leftChild){
        DestructionHelper(cursor->leftChild);
        delete cursor->leftChild;
    }
    if (cursor->rightChild){
        DestructionHelper(cursor->rightChild);
        delete cursor->rightChild;
    }
}



// public

void BinarySearchTree::Insert(int data){
    if (root == nullptr){
        root = new Node(data, nullptr, nullptr);
    } else {
        InsertHelper(root, data);
    }
}

Node* BinarySearchTree::Search(int data){
    if (root == nullptr)
        return nullptr;
    return SearchHelper(root, data);
}

void BinarySearchTree::Remove(int data){
    root = RemoveHelper(root, data);
}

void BinarySearchTree::InorderTraversal(){
    InorderHelper(root);
}

void BinarySearchTree::Print(){
    
}

int BinarySearchTree::Size(){
    if (root)
        return SizeHelper(root);
    else
        return 0;
}


// private

Node* BinarySearchTree::FindMax(Node* cursor){
    while (cursor->rightChild){
        cursor = cursor->rightChild;
    }
    return cursor;
}

Node* BinarySearchTree::FindMin(Node* cursor){
    while (cursor->leftChild){
        cursor = cursor->leftChild;
    }
    return cursor;
}

Node* BinarySearchTree::InsertHelper(Node* cursor, int data){
    RecursionCounter neededForUnitTest;
    if (data < cursor->data){
        if (cursor->leftChild){
            InsertHelper(cursor->leftChild, data);
            cursor->UpdateHeight();
        } else {
            cursor->leftChild = new Node(data, nullptr, nullptr);
            cursor->UpdateHeight();
        }
    } else if (data > cursor->data){
        if (cursor->rightChild){
            InsertHelper(cursor->rightChild, data);
            cursor->UpdateHeight();
        } else {
            cursor->rightChild = new Node(data, nullptr, nullptr);
            cursor->UpdateHeight();
        }
    }
    return new Node();
}

Node* BinarySearchTree::SearchHelper(Node* cursor, int data){
    RecursionCounter neededForUnitTest;
    if (data < cursor->data){
        if (cursor->leftChild)
            return SearchHelper(cursor->leftChild, data);
        else
            return nullptr;     // didn't find it
    } else if (data > cursor->data){
        if (cursor->rightChild)
            return SearchHelper(cursor->rightChild, data);
        else
            return nullptr;     // didn't find it
    } else {
        return cursor;          // found it
    }
}

Node* BinarySearchTree::RemoveHelper(Node* cursor, int data){
    RecursionCounter neededForUnitTest;
    
    if (!cursor){               // not-present check
        return nullptr;
    }
    
    if (data < cursor->data){
        cursor->leftChild = RemoveHelper(cursor->leftChild, data);
        return cursor;
    } else if (data > cursor->data){
        cursor->rightChild = RemoveHelper(cursor->rightChild, data);
        return cursor;
    } else {                        // base case
        if (cursor->leftChild){
            Node* leftMax = FindMax(cursor->leftChild);
            int temp = leftMax->data;
            Remove(leftMax->data);
            return new Node(temp, cursor->leftChild, cursor->rightChild);
        } else if (cursor->rightChild){
            Node* rightMin = FindMin(cursor->rightChild);
            int temp = rightMin->data;
            Remove(rightMin->data);
            return new Node(temp, cursor->leftChild, cursor->rightChild);
        }else{
            delete cursor;
            return nullptr;
        }
    }
}

void BinarySearchTree::InorderHelper(Node* cursor){
    RecursionCounter neededForUnitTest;
    if (cursor->leftChild){
        InorderHelper(cursor->leftChild);
    }
    std::cout << cursor->data << ", ";
    if (cursor->rightChild){
        InorderHelper(cursor->rightChild);
    }
}

void BinarySearchTree::PrintHelper(std::string& offset, Node* cursor){
    RecursionCounter neededForUnitTest;
    
}

int BinarySearchTree::SizeHelper(Node* cursor){
    RecursionCounter neededForUnitTest;
    int c1 = 0;
    int c2 = 0;
    if (cursor->leftChild){
        c1 = SizeHelper(cursor->leftChild);
    }
    if (cursor->rightChild){
        c2 = SizeHelper(cursor->rightChild);
    }
    return c1 + c2 + 1;
}

