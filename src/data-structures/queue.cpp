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


using namespace WrapperDataStr;

template <typename T>
Queue<T>::Queue():SingleLinkedList<T>(){

}

template <typename T>
Queue<T>::~Queue(){

}

template <typename T>
typename Queue<T>::Node* Queue<T>::Push(T value){
    return (Node*)SingleLinkedList<T>::Push(value);
}

template <typename T>
typename Queue<T>::Node* Queue<T>::Pop(){
    return (Node*)SingleLinkedList<T>::Pop();
}

template <typename T>
int Queue<T>::GetCount(){
    return SingleLinkedList<T>::GetCount();
}

template <typename T>
string Queue<T>::ToString(){
    return SingleLinkedList<T>::ToString();
}

template class Queue<int>;
template class Queue<double>;
