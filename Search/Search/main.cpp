/********************************************************************************************
 **    Project: Search Project
 **  Programmer: Dana Doggett
 **  Course:        cs2420
 **    Section:    001
 **    Assignment: 4
 **    Data:        Sept 6, 2018
 **
 **    I certify that I wrote all code in this project except that which was
 **    provided by the instructor.
 **
 ***********************************************************************************************/

#include <iostream>
#include <random>
#include "Timer.h"
#include "Search.h"

using namespace std;

// used for Recursion Unit Testing. DO NOT REMOVE
int RecursionCounter::currentDepth = 0;
int RecursionCounter::maxDepth = 0;

// add code here
int main(){
    Timer ti;
    cout << "Creating a sorted array of 10000000" << endl;
    Search waldo(10000000);
    cout << "Finished creating a sorted array of 10000000" << endl;
    
    cout << "the last number is " << waldo.GetDataArray()[9999999] << endl;
    
    bool result;
    
    //
    // beginning of array search
    //
    
    cout << "\nSearching for a number at the beginning of the array" << endl;
    
    ti.Start();
    result = waldo.RecursiveBinarySearch(0);
    ti.End();

    cout << "waldo.RecursiveBinarySearch() returned " << result << " in " << ti.DurationInNanoSeconds() << "ns" << endl;
    
    ti.Start();
    result = waldo.IterativeBinarySearch(0);
    ti.End();
    
    cout << "waldo.IterativeBinarySearch() returned " << result << " in " << ti.DurationInNanoSeconds() << "ns" << endl;
    
    ti.Start();
    result = waldo.SequentialSearch(0);
    ti.End();
    
    cout << "waldo.SequentialSearch() returned " << result << " in " << ti.DurationInNanoSeconds() << "ns" << endl;
    
    //
    // middle of the array search
    //
    
    cout << "\nSearching for a number in the middle of the array" << endl;
    
    ti.Start();
    result = waldo.RecursiveBinarySearch(10004483);
    ti.End();
    
    cout << "waldo.RecursiveBinarySearch() returned " << result << " in " << ti.DurationInNanoSeconds() << "ns" << endl;
    
    ti.Start();
    result = waldo.IterativeBinarySearch(10004483);
    ti.End();
    
    cout << "waldo.IterativeBinarySearch() returned " << result << " in " << ti.DurationInNanoSeconds() << "ns" << endl;
    
    ti.Start();
    result = waldo.SequentialSearch(10004483);
    ti.End();
    
    cout << "waldo.SequentialSearch() returned " << result << " in " << ti.DurationInNanoSeconds() << "ns" << endl;
    
    //
    // end of the array search
    //
    
    cout << "\nSearching for a number at the end of the array" << endl;
    
    ti.Start();
    result = waldo.RecursiveBinarySearch(20003155);
    ti.End();
    
    cout << "waldo.RecursiveBinarySearch() returned " << result << " in " << ti.DurationInNanoSeconds() << "ns" << endl;
    
    ti.Start();
    result = waldo.IterativeBinarySearch(20003155);
    ti.End();
    
    cout << "waldo.IterativeBinarySearch() returned " << result << " in " << ti.DurationInNanoSeconds() << "ns" << endl;
    
    ti.Start();
    result = waldo.SequentialSearch(20003155);
    ti.End();
    
    cout << "waldo.SequentialSearch() returned " << result << " in " << ti.DurationInNanoSeconds() << "ns" << endl;
    
    //
    // not found search
    //
    
    cout << "\nSearching for a number at the beginning of the array" << endl;
    
    ti.Start();
    result = waldo.RecursiveBinarySearch(50);
    ti.End();
    
    cout << "waldo.RecursiveBinarySearch() returned " << result << " in " << ti.DurationInNanoSeconds() << "ns" << endl;
    
    ti.Start();
    result = waldo.IterativeBinarySearch(50);
    ti.End();
    
    cout << "waldo.IterativeBinarySearch() returned " << result << " in " << ti.DurationInNanoSeconds() << "ns" << endl;
    
    ti.Start();
    result = waldo.SequentialSearch(50);
    ti.End();
    
    cout << "waldo.SequentialSearch() returned " << result << " in " << ti.DurationInNanoSeconds() << "ns" << endl;

}
