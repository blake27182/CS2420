#include "HashMap.h"

HashMap::HashMap(int size){
    sizeOfArray = size;
    hashArray = new Node* [sizeOfArray];
    for (int i=0;i<sizeOfArray;i++){
        hashArray[i] = nullptr;
    }
}

HashMap::~HashMap(){
    for (int i=0;i<sizeOfArray;i++){
        if (hashArray[i]){
            Node* precursor = hashArray[i];
            Node* cursor = hashArray[i]->next;
            while(cursor){
                delete precursor;
                precursor = cursor;
                cursor = cursor->next;
            }
            delete precursor;
        }
    }
    delete [] hashArray;
}

bool HashMap::IsKeyPresent(string const &key) const{
    int hash = GenerateHash(key);
    Node* cursor = hashArray[hash];
    while (cursor) {
        if (cursor->key == key){
            return true;
        } else {
            cursor = cursor->next;
        }
    }
    return false;
}

void HashMap::SetKeyValue(string const &key, int value){
    int hash = GenerateHash(key);
    Node* cursor = hashArray[hash];
    while (cursor){
        if (cursor->key == key){
            cursor->value = value;
            return;
        } else {
            if (cursor->next){
                cursor = cursor->next;
            } else {
                cursor->next = new Node(key);
                cursor->next->value = value;
                return;
            }
        }
    }
    hashArray[hash] = new Node(key);
    hashArray[hash]->value = value;
}

bool HashMap::GetKeyValue(string const &key, int& value){
    int hash = GenerateHash(key);
    Node* cursor = hashArray[hash];
    while (cursor){
        if (cursor->key == key){
            value = cursor->value;
            return true;
        } else {
            cursor = cursor->next;
        }
    }
    value = 0;
    return false;
}

Iterator HashMap::begin(){
    int index = 0;
    for (int i=0;i<sizeOfArray;i++){
        if (hashArray[i]){
            index = i;
            break;
        }
    }
    return Iterator(index, hashArray, sizeOfArray);
}

Iterator HashMap::end(){
    int index = 0;
    for (int i=0;i<sizeOfArray;i++){
        if (hashArray[i])
            index = i;
    }
    Iterator end(index, hashArray, sizeOfArray);
    while (end.is_item()){
        ++end;
    }
    return end;
}

int HashMap::GenerateHash(string key) const{ // converts the key to a value used to index into the array
    int hash = 0;
    for (int i=0;i<key.size();i++){
        hash += key[i];
    }
    hash = (hash*7) % sizeOfArray;
    return hash;
}
