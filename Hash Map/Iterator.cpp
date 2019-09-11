#include "HashMap.h"

Iterator::Iterator(int index, Node **hashArray, int sizeOfArray){
    this->hashArray = hashArray;
    this->sizeOfArray = sizeOfArray;
    this->index = index;
    this->current = hashArray[index];
}

Iterator::Iterator(){
    
}

string Iterator::operator*(){
    return current->key;
}

void Iterator::operator++(){
    if (current){
        if (current->next){
            current = current->next;
        } else {
            for (int i=index+1;i<sizeOfArray;i++){
                if (hashArray[i]){
                    index = i;
                    current = hashArray[index];
                    return;
                }
            }
            current = current->next;
        }
    }
}

bool Iterator::operator!=(Iterator& other){
    if (current == other.current){
        return false;
    } else {
        return true;
    }
}

bool Iterator::is_item(){
    if (current)
        return true;
    else
        return false;
}
