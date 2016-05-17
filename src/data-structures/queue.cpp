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
    return SingleLinkedList<T, Node>::Push(value);
}

template <typename T, class Node>
T Queue<T, Node>::Head(){
    return SingleLinkedList<T, Node>::Head();
}

template <typename T, class Node>
void Queue<T, Node>::Pop(){
    return SingleLinkedList<T, Node>::Pop();
}


template class Queue<int>;
template class Queue<double>;
