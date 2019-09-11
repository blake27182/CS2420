#ifndef __SORT__
#define __SORT__

#include "RecursionCounter.h"
#include <array>
class Sort
{
public:
    Sort(int size);
    ~Sort();
    
    void InitArray();
    
    void SelectionSort();
    void InsertionSort();
    void AlgorithmSort();
    void MergeSort();
    void QuickSort();
    void MergeTask(int i, int m, int k);
    
    int GetSize() const;
    int *GetDataArray() const;
private:
    int* list;
    int size;
    
    void MergeSortRecursionHelper(int indexI, int indexK);
    void QuickSortRecursionHelper(int initialLowIndex, int initialHighIndex);
};

#endif
