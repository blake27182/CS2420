#include <iostream>
#include "BinarySearchTree.h"
#include "Observer.h"
#include "RecursionCounter.h"


using namespace std;

// needed for Unit Testing. DO NOT REMOVE
int Observer::numConstructions = 0;
int Observer::numDestructions = 0;
int RecursionCounter::currentDepth = 0;
int RecursionCounter::maxDepth = 0;


// test 1: Verify Size() returns the number of Nodes in the tree and uses recursionto count number of Nodes.
bool testSizePassed() {
//
// testing Size() function

    BinarySearchTree bst;

    if (bst.Size() != 0)
    {
          cout << "ERROR: Size() did NOT return 0 for an empty tree." << endl;
          return false;
    }

    for (size_t i = 0; i < 123; i++)
    {
          bst.Insert(rand());
    }

    int size = bst.Size();
    if (size != 123)
    {
          cout << "ERROR: after inserting 123 random integers into tree, Size() did NOT return 123" << endl;
          return false;
    }

    if (RecursionCounter::maxDepth < 5)
    {
          cout << "ERROR: It appear as though Size() has NOT used recursion." << endl;
          return false;
    }

    return true;
}
//Test 2: verify Insert() and Search().Both must use recursion.

//bool testPassed() {
//
//// testing Insert() and Search() function
//
//    BinarySearchTree bst;
//
//    srand(0);
//    for (size_t i = 0; i < 123; i++)
//    {
//          bst.Insert(rand());
//    }
//    if (Observer::numConstructions != 123)
//    {
//          cout << "Insert() called 123 times, but not 123 new Nodes created." << endl;
//          return false;
//    }
//
//    if (RecursionCounter::maxDepth < 12)
//    {
//          cout << "It appears as though Insert() is not using recursion." << endl;
//          return false;
//    }
//
//    RecursionCounter::maxDepth = 0;
//    srand(0);
//    for (size_t i = 0; i < 123; i++)
//    {
//          int data = rand();
//          Node* found = bst.Search(data);
//          if (found == nullptr)
//          {
//                cout << "After Insert(" << data << ") Search() could not find it in the tree." << endl;
//                return false;
//          }
//
//          if (found->data != data)
//          {
//                cout << "After Insert(" << data << ") Search() found a node, but node->data was not correct value." << endl;
//                return false;
//          }
//    }
//
//    if (RecursionCounter::maxDepth < 12)
//    {
//          cout << "It appears as though Search() is not using recursion."<< endl;
//          return false;
//    }
//
//    if (bst.Search(-123) != nullptr)
//    {
//          cout << "Search(-123) found that node in tree when it was neverinserted." << endl;
//          return false;
//    }
//
//    return true;
//}

//Test 3: verify IsLeaf() and height of nodes in tree
//bool testPassed() {
//
//// testing IsLeaf() and height
//    BinarySearchTree bst;
//
//    bst.Insert(123);
//
//    Node* tmp = bst.Search(123);
//    if (tmp == nullptr)
//    {
//          cout << "Search() unable to find the only node in the tree" << endl;
//          return false;
//    }
//
//    if (tmp->IsLeaf() != true)
//
//    {
//          cout << "IsLeaf() returned false when called on a leaf node" <<endl;
//          return false;
//    }
//
//    if (tmp->height != 0)
//    {
//          cout << "height of a leaf node not zero" << endl;
//          return false;
//    }
//
//    bst.Insert(12);
//
//    if (tmp->IsLeaf() == true)
//    {
//          cout << "IsLeaf() returned true when called on a non-leaf node"<< endl;
//          return false;
//    }
//
//    bst.Insert(2);
//
//    if (tmp->height != 2)
//    {
//          cout << "height of root node is not 2. (tree has three nodes: 123, 12, and 3)" << endl;
//          return false;
//    }
//
//    return true;
//}
// Test 4: verify Remove() actually removes nodes properly and uses recursion
//bool testPassed() {
//
//// testing Remove function
//
//    BinarySearchTree bst;
//
//    srand(0);
//    for (size_t i = 0; i < 10; i++)
//    {
//          bst.Insert(rand());
//    }
//
//    RecursionCounter::maxDepth = 0;
//    Observer::numDestructions = 0;
//    srand(0);
//    for (size_t i = 0; i < 10; i++)
//    {
//          int data = rand();
//          bst.Remove(data);
//          if (bst.Size() != 10 - i - 1)
//          {
//                cout << "Remove(" << data << ") did not seem to remove that node properly" << endl;
//                return false;
//          }
//    }
//
//
//    if (Observer::numDestructions != 10)
//    {
//          cout << "Remove() called 10 times, but not 10 Nodes destructed." << endl;
//          return false;
//    }
//
//    bst.Remove(-123);
//    if (Observer::numDestructions != 10)
//    {
//          cout << "Remove() called with bad data but another Node was destructed anyway" << endl;
//          return false;
//    }
//
//    if (RecursionCounter::maxDepth < 4)
//    {
//          cout << "It appears as though Remove() is not using recursion."<< endl;
//          return false;
//    }
//
//    return true;
//}
//Test 5: verify that the tree's Destructor actually deletes all nodes in tree
bool testPassed() {

// testing destructor

    {
          Observer::numDestructions = 0;
          BinarySearchTree bst;
          srand(0);
          for (size_t i = 0; i < 500; i++)
          {
                bst.Insert(rand());
          }
    }

    if (Observer::numDestructions != 500)
    {
          cout << "tree with 500 nodes destructed, but ~Node() not called500 times" << endl;
          return false;
    }

    return true;
}




int main()
{
//    int data[] = { 21,26,30,9,4,14,28,18,15,10,2,3,7 };
    cout << testPassed();
}
