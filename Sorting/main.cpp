/********************************************************************************************
 **    Project: Sort
 **  Programmer: Dana Doggett
 **  Course:        cs2420
 **    Section:    001
 **    Assignment: 5
 **    Data:        Sept 12, 2018
 **
 **    I certify that I wrote all code in this project except that which was
 **    provided by the instructor.
 **
 ***********************************************************************************************/

#include <iostream>
#include "Sort.h"
#include "Timer.h"

using namespace std;

// used for Unit Testing. DO NOT REMOVE
int RecursionCounter::currentDepth = 0;
int RecursionCounter::maxDepth = 0;

int main(){
    Sort mole(1000000);
    int* list = mole.GetDataArray();
    cout << list[0] << " " << list[1] << " " << list[2] << " " << list[3] << " " << list[4] <<endl;
    mole.QuickSort();
    list = mole.GetDataArray();
    cout << list[0] << " " << list[1] << " " << list[2] << " " << list[3] << " " << list[4] <<endl;
    
    
}
