#include <random>
#include <algorithm>
#include "Sort.h"


Sort::Sort(int size){
    this->size = size;
    InitArray();
}

Sort::~Sort(){
    delete list;
}

void Sort::MergeTask(int i, int m, int k){
    const int ts = k-i+1;
    int temp [ts];
    int fi = i;
    int si = m+1;
    
    for (int l=0;l<ts;l++){
        if ((fi < m+1 && list[fi] < list[si]) || si > k){
            temp[l] = list[fi++];
        } else {
            temp[l] = list[si++];
        }
    }
    for (int l=0;l<ts;l++){
        list[l+i] = temp[l];
    }
}

void Sort::MergeSort(){
    MergeSortRecursionHelper(0, size-1);
}

void Sort::MergeSortRecursionHelper(int i, int k)
{
    RecursionCounter rcTmp;    // used for Unit Testing. DO NOT REMOVE
    // add more code here
    int dif = k-i;
    if (dif > 1){
        int medIdx = (k-i)/2 + i;
        MergeSortRecursionHelper(i, medIdx);
        MergeSortRecursionHelper(medIdx+1, k);
        MergeTask(i, medIdx, k);
    } else if (list[i] > list[k]){
        int temp = list[k];
        list[k] = list[i];
        list[i] = temp;
    }
    
}


void Sort::QuickSortRecursionHelper(int initialLowIndex, int initialHighIndex)
{
    RecursionCounter rcTmp;    // used for Unit Testing. DO NOT REMOVE
    
    int m = (initialLowIndex + initialHighIndex) / 2;
    int pivot = list[m];
    int i = initialLowIndex;
    int j = initialHighIndex;
    
    while (i < j){
        // find two to be swapped
        while (list[i] < pivot && i < j) {
            i++;
        }
        // The most confusing and crucial part of this algorithm >=
        // You must only put this on one side (i or j) so that one iterator may slip past,
        // effectively making that side the one able to contain duplicates of the pivot.
        // if both have "=" option, i will skip a switch in the case of a partition size of 2
        // if neither have the "=" option, they will swap back and forth forever once one
        // of them reaches the pivot
        while (list[j] >= pivot && j > i) {
            j--;
        }
        // swap the data at i and j
        if (i < j){
            int temp = list[i];
            list[i] = list[j];
            list[j] = temp;
        }
    }
    
    // recurse in the partitioned data
    if (initialHighIndex - initialLowIndex > 2){        // if there are only 3, the previous code has sorted it
        QuickSortRecursionHelper(initialLowIndex, m);
        QuickSortRecursionHelper(m+1, initialHighIndex);
    }
}

void Sort::SelectionSort(){
    for (int i=0;i<size;i++){
        int min = list[i];
        int minIdx = i;
        for (int j=i;j<size;j++){
            if (list[j] < min){
                min = list[j];
                minIdx = j;
            }
        }
        list[minIdx] = list[i];
        list[i] = min;
    }
}

void Sort::InsertionSort(){
    for (int i=1;i<size;i++){
        int temp = list[i];
        for (int j=0;j<i+1;j++){
            if (temp<=list[j]){
                for (int k=i;k>j;k--){
                    list[k] = list[k-1];
                }
                list[j] = temp;
                break;
            }
        }
    }
}

void Sort::AlgorithmSort(){
    std::sort(&list[0], &list[size-1]);
}

void Sort::QuickSort(){
    QuickSortRecursionHelper(0, size-1);
}

int Sort::GetSize() const{
    return size;
}

int *Sort::GetDataArray() const{
    return list;
}

void Sort::InitArray(){
    srand(0);
    list = new int [size];
    for (int i=0;i<size;i++){
        int number = rand() % 50000000;
        list[i] = number;
    }
}
