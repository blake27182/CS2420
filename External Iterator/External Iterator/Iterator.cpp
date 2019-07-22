#include <cassert>
#include "Iterator.h"

Iterator::Iterator(Node *start){
    selected = start;
}

int Iterator::operator*(){
    return selected->data;
}

Iterator Iterator::operator++(){
    Iterator temp(selected);
    selected = selected->next;
    return temp;
}

bool Iterator::operator!=(const Iterator &other){
    if (this->selected == other.selected){
        return false;
    } else {
        return true;
    }
}

bool Iterator::is_item(){
    if(selected == nullptr){
        return false;
    } else {
        return true;
    }
}
