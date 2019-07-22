//
//  DynamicArray.cpp
//  Debit Card Project
//
//  Created by Blake Williams on 6/26/19.
//  Copyright © 2019 Blake Williams. All rights reserved.
//

#include "DynamicArray.h"

DynamicArray::DynamicArray(){
    capacity = INITIAL_CAPACITY;
    used = 0;
    transactions = new Transaction[INITIAL_CAPACITY];
}

DynamicArray::~DynamicArray(){
    delete [] transactions;
    transactions = nullptr;
    capacity = used = 0;
}

void DynamicArray::push_back(const Transaction &newTransaction){
    if (used >= capacity){
        Realloc();
    }
    transactions[used] = newTransaction;
    used++;
}

int DynamicArray::size() const{
    return used;
}

int DynamicArray::currentCapacity() const{
    return capacity;
}

Transaction& DynamicArray::at(int index){
    return transactions[index];
}

void DynamicArray::Realloc(){
    Transaction* temp = transactions;
    transactions = new Transaction[capacity*2];
    for (int i=0;i<used;i++){
        transactions[i] = temp[i];
    }
    delete [] temp;
    capacity *= 2;
}
