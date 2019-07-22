#ifndef __SEARCH__
#define __SEARCH__
#include "RecursionCounter.h"

class Search
{
public:
    Search(int size);
    ~Search();
    bool SequentialSearch(int target);              // returns true if target is found in the object's data array
    bool RecursiveBinarySearch(int target);         // returns true if target is found in the object's data array (recursive)
    bool RecursiveBinarySearchHelper(int lowIndex, int highIndex, int target);      //called by RecursiveBinarySearch()
    bool IterativeBinarySearch(int target);         // returns true if target is found in the object's data array
    void InitSortedArray();
    int *GetDataArray();                            // returns a pointer to the array of integers
    
    
private:
    bool RecursiveBinarySearchHelper(int lowIndex, int highIndex, int target) const;
    int size;
    int* list;
};


#endif
