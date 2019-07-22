#include "Search.h"
#include <stdlib.h>

Search::Search(int size){
    this->size = size;
    InitSortedArray();
}

Search::~Search(){
    delete list;
}

bool Search::RecursiveBinarySearch(int target){
    return RecursiveBinarySearchHelper(0, size-1, target);
}

bool Search::RecursiveBinarySearchHelper(int lowIndex, int highIndex, int target)
{
    RecursionCounter rcTmp;    // used for unit testing DO NOT REMOVE
    
    if (lowIndex != highIndex-1){                   // keep looking
        int medIdx = (highIndex + lowIndex) / 2;
        int median = list[medIdx];
        if (target > median){
            return RecursiveBinarySearchHelper(medIdx, highIndex, target);
        } else if (target <  median){
            return RecursiveBinarySearchHelper(lowIndex, medIdx, target);
        } else {
            return true;                            // target == median
        }
        
    } else if (list[lowIndex] == target || list[highIndex] == target){
        return true;
    } else {
        return false;
    }
    return true;
}

bool Search::SequentialSearch(int target){
    for (int i=0;i<size;i++){
        if (list[i] == target)
            return true;
    }
    return false;
}

bool Search::IterativeBinarySearch(int target){
    int highIndex = size-1;
    int lowIndex = 0;
    
    while (lowIndex != highIndex-1){
        int medIdx = (highIndex + lowIndex) /2;
        int median = list[medIdx];
        if (target == list[lowIndex] || target == list[highIndex]){
            return true;
        } else if (target < median){
            highIndex = medIdx;
        } else if (target > median){
            lowIndex = medIdx;
        } else {                    // target == median
            return true;
        }
    }
    return false;
}

void Search::InitSortedArray(){
    list = new int [size];
    srand(0);
    list[0] = rand() % 5;
    for (int i=0;i<size;i++){
        list[i+1] = list[i] + rand() % 5;
    }
}

int *Search::GetDataArray(){
    return list;
}
