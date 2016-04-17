/*
 * data-structures.cpp
 *
 *  Created on: Apr 16, 2016
 *      Author: asm
 */
#include <iostream>
#include <string>
#include "../../headers/type-parse.hpp"
#include "../../headers/data-structures.hpp"

using namespace WrapperDataStr;

template <typename T>
SingleLinkedList<T>::SingleLinkedList(){
    head = 0;
}

template <typename T>
SingleLinkedList<T>::~SingleLinkedList(){
    //free all node in the list
    Node* travel = head;
    Node* next = NULL;

    try{
        while(travel != NULL){
            next = (Node*)travel->next;
            delete travel;
            travel = next;
        }
    }
    catch(const std::exception& e){
        //do nothing
    }
}

template <typename T>
typename SingleLinkedList<T>::Node* SingleLinkedList<T>::Push(T value){
    Node* new_node = (Node*)(new Node(value));

    Node* tail = head;

    if(tail == NULL){
        head = new_node;
        return new_node;
    }

    while(tail->next != NULL){
        tail = (Node*)tail->next;
    }

    tail->next = (Node*)new_node;

    return new_node;
}

template <typename T>
typename SingleLinkedList<T>::Node* SingleLinkedList<T>::Pop(){
    Node* ret = head;
    if(head != NULL){
        head = (Node*)head->next;
    }

    return ret;
}

template <typename T>
int SingleLinkedList<T>::GetCount(){
    int number_nodes = 0;
    Node* travel = head;

    if(head == NULL) return number_nodes;

    while(travel != NULL){
        travel = (Node*)travel->next;
        number_nodes++;
    }

    return number_nodes;
}

template <typename T>
string SingleLinkedList<T>::ToString(){
    string ret_str;
    Node* travel = head;

    ret_str.append("[");
    while(travel != NULL){
       ret_str.append(" ");
       ret_str.append(Utils::ToString(travel->value));
       ret_str.append(" ");
       travel = (Node*)travel->next;
    }
    ret_str.append("]");

    return ret_str;
}

template class SingleLinkedList<int>;
template class SingleLinkedList<double>;

