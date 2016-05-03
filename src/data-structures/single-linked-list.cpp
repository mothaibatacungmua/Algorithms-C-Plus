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

using namespace DataStructures;

template <typename T, class Node>
SingleLinkedList<T,Node>::SingleLinkedList(){
    head = 0;
}

template <typename T, class Node>
SingleLinkedList<T,Node>::~SingleLinkedList(){
    //free all node in the list
    Node* travel = head;
    Node* next = NULL;

    try{
        while(travel != NULL){
            next = travel->next;
            delete travel;
            travel = next;
        }
    }
    catch(const std::exception& e){
        //do nothing
    }
}

template <typename T, class Node>
Node* SingleLinkedList<T,Node>::Push(T value){
    Node* new_node = (new Node(value));

    Node* tail = head;

    if(tail == NULL){
        head = new_node;
        return new_node;
    }

    while(tail->next != NULL){
        tail = tail->next;
    }

    tail->next = new_node;

    return new_node;
}

template <typename T, class Node>
Node* SingleLinkedList<T,Node>::Find(T value){
    Node* travel = head;

    if(travel == NULL) return NULL;

    while(travel != NULL){
        if(travel->value == value){
            return travel;
        }

        travel = travel->next;
    }

    return NULL;
}

template <typename T, class Node>
Node* SingleLinkedList<T,Node>::Pop(){
    Node* ret = head;
    if(head != NULL){
        head = head->next;
    }

    return ret;
}

template <typename T, class Node>
int SingleLinkedList<T,Node>::GetCount(){
    int number_nodes = 0;
    Node* travel = head;

    if(head == NULL) return number_nodes;

    while(travel != NULL){
        travel = (Node*)travel->next;
        number_nodes++;
    }

    return number_nodes;
}

template <typename T, class Node>
string SingleLinkedList<T,Node>::ToString(){
    string ret_str;
    Node* travel = head;

    ret_str.append("[");
    while(travel != NULL){
       ret_str.append(" ");
       ret_str.append(Utils::ToString(travel->value));
       ret_str.append(" ");
       travel = travel->next;
    }
    ret_str.append("]");

    return ret_str;
}

template class SingleLinkedList<int>;
template class SingleLinkedList<double>;

