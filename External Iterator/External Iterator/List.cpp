#include "List.h"

void List::deallocator(Node* cursor){
    if(cursor->next == nullptr){
        delete cursor;
    } else {
        deallocator(cursor->next);
        delete cursor;
    }
}

List::~List(){
    deallocator(head);
}

List::List(){
    head = nullptr;
    tail = nullptr;
}

Iterator List::begin(){
    return Iterator(head);
}

Iterator List::end(){
    return Iterator(tail->next);
}

void List::push_back(const int &value){
    Node* temp = new Node(value);
    if (tail){
        tail->next = temp;
        tail = temp;
    } else {
        tail = temp;
        head = temp;
    }
}

void List::push_front(const int &value){
    Node* temp = new Node(value);
    temp->next = head;
    head = temp;
    if (!tail){
        tail = temp;
    }
}

int List::size(){
    Node* cursor = head;
    int si = 0;
    while (cursor->next != nullptr) {
        si++;
        cursor = cursor->next;
    }
    return ++si;
}

void List::PrintList(){
    Node *cursor = head;
    while (cursor) {
        std::cout << cursor->data << " ";
        cursor = cursor->next;
    }
}

void List::remove(const int &value){
    while(head->data == value){
        DeleteHead();
    }
    Node* precursor = head;
    while(precursor->next){
        while(precursor->next && precursor->next->data == value){
            DeleteNotHead(precursor);
        }
        if (precursor->next)
            precursor = precursor->next;
    }
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  Precondition: precursor must be at least
//      one space behind tail
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void List::DeleteNotHead(Node* precursor){
    Node* temp = precursor->next;
    if (precursor->next == tail)
        tail = precursor;
    precursor->next = precursor->next->next;
    delete temp;
}

void List::DeleteHead(){
    Node* temp = head;
    head = head->next;
    delete temp;
}
