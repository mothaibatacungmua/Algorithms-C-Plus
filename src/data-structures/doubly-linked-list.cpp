/*
 * doubly-linked-list.cpp
 *
 *  Created on: Apr 21, 2016
 *      Author: asm
 */
#include <iostream>
#include <string>
#include <stdio.h>

#include "../../headers/type-parse.hpp"
#include "../../headers/data-structures.hpp"


using namespace DataStructures;

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList(){
    head = NULL;
    tail = NULL;
}

template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList(){
    //travel in list and delete
    if(head == NULL || tail == NULL)
        return;

    Node* travel = head;
    Node* save = travel;

    //forward traveling to delete all node
    try{
        while(travel != tail){
            travel = (Node*)travel->next;
            delete save;
            save = travel;
        }
    }catch(const std::exception& e){
        //do nothing
    }
    head = NULL;
    tail = NULL;
}

template <typename T>
typename DoublyLinkedList<T>::Node* DoublyLinkedList<T>::InsertAfter(Node* node, Node* new_node){
    if(node == NULL || new_node == NULL)
        return NULL;

    Node* save = (Node*)node->next;

    node->next = new_node;
    new_node->next = save;

    new_node->prev = node;

    if(save != NULL)
        save->prev = new_node;

    return new_node;

}

template <typename T>
typename DoublyLinkedList<T>::Node* DoublyLinkedList<T>::InsertAfter(Node* node, T value){
    Node* new_node = new Node(value);

    return this->InsertAfter(node, new_node);
}

template <typename T>
typename DoublyLinkedList<T>::Node* DoublyLinkedList<T>::InsertBefore(Node* node, Node* new_node){
    if(node == NULL || new_node == NULL)
        return NULL;

    Node* save = (Node*)node->prev;

    node->prev = new_node;
    new_node->prev = save;

    new_node->next = node;

    if(save != NULL)
        save->next = new_node;

    return new_node;
}

template <typename T>
typename DoublyLinkedList<T>::Node* DoublyLinkedList<T>::InsertBefore(Node* node, T value){
    Node* new_node = new Node(value);

    return this->InsertBefore(node, new_node);
}

template <typename T>
typename DoublyLinkedList<T>::Node* DoublyLinkedList<T>::InsertBeginning(Node* new_node){
    /* NOT IMPLEMENTED */
    return NULL;
}

template <typename T>
typename DoublyLinkedList<T>::Node* DoublyLinkedList<T>::InsertEnd(Node* new_node){
    /* NOT IMPLEMENTED */
    return NULL;
}

template <typename T>
typename DoublyLinkedList<T>::Node* DoublyLinkedList<T>::InsertBeginning(T value){
    /* NOT IMPLEMENTED */
    return NULL;
}

template <typename T>
typename DoublyLinkedList<T>::Node* DoublyLinkedList<T>::InsertEnd(T value){
    /* NOT IMPLEMENTED */
    return NULL;
}

template <typename T>
typename DoublyLinkedList<T>::Node* DoublyLinkedList<T>::Remove(Node* node){
    if(node == NULL)
        return NULL;

    Node* next = (Node*)node->next;
    Node* prev = (Node*)node->prev;

    if(prev){
        prev->next = next;
    }

    if(next){
        next->prev = prev;
    }

    return node;
}

template <typename T>
typename DoublyLinkedList<T>::Node* DoublyLinkedList<T>::RemoveBeginning(){
    if(head == NULL)
        return NULL;

    Node* new_head = (Node*)head->next;
    Node* remove_head = this->Remove(head);

    head = new_head;

    return remove_head;
}

template <typename T>
typename DoublyLinkedList<T>::Node* DoublyLinkedList<T>::RemoveEnd(){
    if(tail == NULL)
        return NULL;

    Node* new_tail = (Node*)tail->next;
    Node* remove_tail = this->Remove(tail);

    tail = new_tail;

    return remove_tail;
}

template <typename T>
int DoublyLinkedList<T>::GetCount(){
    int count_node = 0;
    Node* travel = head;

    if(head != NULL)
        count_node = 1;

    //forward traveling to count all nodes
    while(travel != tail && travel != NULL){
        travel = (Node*)travel->next;
        count_node++;
    }

    return count_node;
}

template <typename T>
string DoublyLinkedList<T>::ToString(){
    string ret_str;
    Node* travel = head;
    char buffer[512];

    if(head == NULL){
        ret_str = "[]\n";
        return ret_str;
    }

    sprintf(buffer, "\n0x%X:[prev=0x%X, value=%s, next=0x%X]\n", (int)head, (int)head->prev, Utils::ToString(head->value).c_str(), (int)head->next);
    ret_str.append(buffer);

    if((int)head == (int)tail){
        return ret_str;
    }


    while(travel != tail){
       travel = (Node*)travel->next;
       sprintf(buffer, "\n0x%X:[prev=0x%X, value=%s, next=0x%X]\n", (int)travel, (int)travel->prev, Utils::ToString(travel->value).c_str(), (int)travel->next);
       ret_str.append(buffer);
    }

    return ret_str;
}

template class DoublyLinkedList<int>;
template class DoublyLinkedList<double>;
