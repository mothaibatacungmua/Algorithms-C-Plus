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

using namespace WrapperDataStr;

template <typename T>
Stack<T>::Stack():SingleLinkedList<T>(){

}

template <typename T>
typename Stack<T>::Node* Stack<T>::Push(T value){
    return (Node*)this->Push(value);
}

template <typename T>
typename Stack<T>::Node* Stack<T>::Pop(){
    //pop tail
    if(this->head == NULL) return NULL;

    Node* tail = (Node*)this->head;
    if(tail->next == NULL){
        this->head = NULL;
        return tail;
    }

    Node* prev_tail = tail;
    tail = (Node*)tail->next;

    while(tail-> next != NULL){
        prev_tail = (Node*)prev_tail->next;
        tail = (Node*)tail->next;
    }

    prev_tail->next = NULL;

    return tail;
}



