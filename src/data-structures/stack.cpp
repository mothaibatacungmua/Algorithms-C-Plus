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
#include "../../headers/error-codes.hpp"

using namespace DataStructures;

template <typename T, class Node>
Stack<T, Node>::Stack():SingleLinkedList<T>(){

}

template <typename T, class Node>
Stack<T, Node>::~Stack(){

}

template <typename T, class Node>
T Stack<T,Node>::Head(){
    if(this->head == NULL) throw ErrorCodes::OUT_OF_INDEX;

    return this->head->value;
}

template <typename T, class Node>
Node* Stack<T, Node>::Push(T value){
    Node* new_node = new Node(value);

    if(this->head == NULL){
        this->head = new_node;
        return new_node;
    }

    new_node->next = this->head;
    this->head = new_node->next;

    return new_node;
}

template <typename T, class Node>
void Stack<T, Node>::Pop(){
    if(this->head == NULL) return;

    if(this->head->next == NULL){
        delete this->head;
        this->head = NULL;
    }

    Node* old_head = this->head;

    this->head = this->head->next;
    delete old_head;

}

template class Stack<int>;
template class Stack<double>;



