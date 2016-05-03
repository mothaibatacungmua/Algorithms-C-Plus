/*
 * stack.cpp
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
Stack<T, Node>::Stack():SingleLinkedList<T>(){

}

template <typename T, class Node>
Stack<T, Node>::~Stack(){

}

template <typename T, class Node>
Node* Stack<T, Node>::Push(T value){
    return SingleLinkedList<T>::Push(value);
}

template <typename T, class Node>
Node* Stack<T, Node>::Pop(){
    //pop tail
    if(this->head == NULL) return NULL;

    Node* tail = this->head;
    if(tail->next == NULL){
        this->head = NULL;
        return tail;
    }

    Node* prev_tail = tail;
    tail = tail->next;

    while(tail-> next != NULL){
        prev_tail = prev_tail->next;
        tail = tail->next;
    }

    prev_tail->next = NULL;

    return tail;
}

template class Stack<int>;
template class Stack<double>;



