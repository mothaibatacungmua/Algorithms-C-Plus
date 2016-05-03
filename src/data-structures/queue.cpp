/*
 * Queue.cpp
 *
 *  Created on: Apr 17, 2016
 *      Author: asm
 */
#include <iostream>
#include <string>
#include "../../headers/type-parse.hpp"
#include "../../headers/data-structures.hpp"


using namespace DataStructures;

template <typename T, class Node>
Queue<T, Node>::Queue():SingleLinkedList<T>(){

}

template <typename T, class Node>
Queue<T, Node>::~Queue(){

}

template <typename T, class Node>
Node* Queue<T, Node>::Push(T value){
    return SingleLinkedList<T>::Push(value);
}

template <typename T, class Node>
Node* Queue<T, Node>::Pop(){
    return SingleLinkedList<T>::Pop();
}


template class Queue<int>;
template class Queue<double>;
