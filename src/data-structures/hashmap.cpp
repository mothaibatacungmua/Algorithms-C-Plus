/*
 * hashmap.cpp
 *
 *  Created on: Apr 27, 2016
 *      Author: asm
 */
#include <iostream>
#include <string>

#include "../../headers/type-parse.hpp"
#include "../../headers/data-structures.hpp"
#include "../../headers/error-codes.hpp"

using namespace DataStructures;

template <typename K, typename V, class Hash>
Hashmap<K,V,Hash>::Hashmap(int bucket_length){
    this->map = new  CircularDoublyLinkedList<int, HashEntryNode>*[bucket_length];
    this->bucket_length = bucket_length;

    for(int i=0;i<this->bucket_length;i++){
        this->map[i] = new CircularDoublyLinkedList<int, HashEntryNode>();
    }
}

template <typename K, typename V, class Hash>
Hashmap<K,V,Hash>::~Hashmap(){
    for(int i=0;i < this->bucket_length;i++){
        delete this->map[i];
    }

    delete [] this->map;

}

template <typename K, typename V, class Hash>
bool Hashmap<K,V,Hash>::Get(K key, V& ret){
    unsigned int hash = this->hash(key);
    unsigned int bucket = hash % this->bucket_length;
    unsigned int index = hash - bucket*this->bucket_length;

    typename CircularDoublyLinkedList<int, HashEntryNode>::NodeCls* Node = this->map[bucket]->Find(index);

    if(Node == NULL) return false;

    ret = Node->value;

    return true;

}

template <typename K, typename V, class Hash>
void Hashmap<K,V,Hash>::Set(K key, V value){
    unsigned int hash = this->hash(key);
    unsigned int bucket = hash % this->bucket_length;
    unsigned int index = hash - bucket*this->bucket_length;

    typename CircularDoublyLinkedList<int, HashEntryNode>::NodeCls* Node = this->map[bucket]->Find(index);

    if(Node == NULL){
        Node = new typename CircularDoublyLinkedList<int, HashEntryNode>::NodeCls(index, value);
        this->map[bucket]->InsertEnd(Node);
        return;
    }

    Node->value = value;

    return;
}

template <typename K, typename V, class Hash>
V Hashmap<K, V, Hash>::operator[](K key) const{
    V ret;

    if(this->Get(key, ret)){
        return ret;
    }

    throw ErrorCodes::KEY_NOT_SET;
}


template <typename K, typename V, class Hash>
int Hashmap<K,V,Hash>::Size(){
    int count = 0;

    for (int i=0; i < this->bucket_length;i++){
        count += this->map[i]->GetCount();
    }

    return count;
}

template <typename K, typename V, class Hash>
string Hashmap<K,V,Hash>::ToString(){
    return "NOT IMPLEMENTED YET";
}

template class Hashmap<string, string>;
template class Hashmap<int, string>;
template class Hashmap<char, string>;
template class Hashmap<int, int>;
template class Hashmap<string, int>;
