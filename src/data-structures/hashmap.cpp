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
    this->map = new  CircularDoublyLinkedList<int, HashEntryNode<V> >*[bucket_length];
    this->bucket_length = bucket_length;

    for(int i=0;i<this->bucket_length;i++){
        this->map[i] = new CircularDoublyLinkedList<int, HashEntryNode<V> >();
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

    //std::cout<<"Get:"<<index<<"\n";
    typename CircularDoublyLinkedList<int, HashEntryNode<V> >::NodeCls* node = this->map[bucket]->Find(index);

    if(node == NULL) return false;

    ret = node->real;

    return true;

}

template <typename K, typename V, class Hash>
void Hashmap<K,V,Hash>::Set(K key, V value){
    unsigned int hash = this->hash(key);
    unsigned int bucket = hash % this->bucket_length;
    unsigned int index = hash - bucket*this->bucket_length;

    //std::cout<<"Set:"<<index<<"\n";
    typename CircularDoublyLinkedList<int, HashEntryNode<V> >::NodeCls* node = this->map[bucket]->Find(index);

    if(node == NULL){
        node = new typename CircularDoublyLinkedList<int, HashEntryNode<V> >::NodeCls(index, value);
        this->map[bucket]->InsertEnd(node);
        return;
    }

    node->real = value;

    return;
}

template <typename K, typename V, class Hash>
bool Hashmap<K,V,Hash>::Remove(K key){
    unsigned int hash = this->hash(key);
    unsigned int bucket = hash % this->bucket_length;
    unsigned int index = hash - bucket*this->bucket_length;

    typename CircularDoublyLinkedList<int, HashEntryNode<V> >::NodeCls* node = this->map[bucket]->Find(index);

    if(node == NULL){
        return false;
    }

    this->map[bucket]->Remove(node);

    return true;
}

template <typename K, typename V, class Hash>
V& Hashmap<K, V, Hash>::operator[](K key){
    unsigned int hash = this->hash(key);
    unsigned int bucket = hash % this->bucket_length;
    unsigned int index = hash - bucket*this->bucket_length;

    typename CircularDoublyLinkedList<int, HashEntryNode<V> >::NodeCls* node = this->map[bucket]->Find(index);

    if(node == NULL) throw ErrorCodes::KEY_NOT_SET;

    return node->real;

}

template <typename K, typename V, class Hash>
int Hashmap<K,V,Hash>::Size(){
    int count = 0;

    for (int i=0; i < this->bucket_length;i++){
        count += this->map[i]->Size();
    }

    return count;
}

template <typename K, typename V, class Hash>
std::string Hashmap<K,V,Hash>::ToString(){
    return "NOT IMPLEMENTED YET";
}

/* build some useful classes */

template class Hashmap<std::string, std::string>;
template class Hashmap<int, std::string>;
template class Hashmap<char, std::string>;
template class Hashmap<int, int>;
template class Hashmap<std::string, int>;
template class Hashmap<int, Vector<double> >;
template class Hashmap<int, SGraph::Edge>;
