/*
 * open-doubly-linked-list.cpp
 *
 *  Created on: Apr 21, 2016
 *      Author: asm
 */
#include <iostream>
#include <string>
#include "../../headers/type-parse.hpp"
#include "../../headers/data-structures.hpp"


using namespace DataStructures;

template <typename T, class Node>
OpenDoublyLinkedList<T, Node>::OpenDoublyLinkedList(){

}

template <typename T, class Node>
OpenDoublyLinkedList<T, Node>::~OpenDoublyLinkedList(){

}


template <typename T, class Node>
Node* OpenDoublyLinkedList<T, Node>::InsertBeginning(Node* new_node){
    if(new_node == NULL)
        return NULL;

    if(this->head == NULL){
        this->head = new_node;
        this->tail = new_node;
        return new_node;
    }

    this->InsertAfter(this->head, new_node);

    if(this->head == this->tail)
        this->tail = new_node;

    return new_node;
}
template <typename T, class Node>
Node* OpenDoublyLinkedList<T, Node>::InsertBeginning(T value){
    Node* new_node = new Node(value);

    return this->InsertBeginning(new_node);
}

template <typename T, class Node>
Node* OpenDoublyLinkedList<T, Node>::InsertEnd(Node* new_node){
    if(new_node == NULL)
        return NULL;

    if(this->tail == NULL){
        this->head = new_node;
        this->tail = new_node;
        return new_node;
    }

    this->InsertAfter(this->tail, new_node);

    this->tail = new_node;

    return new_node;
}

template <typename T, class Node>
Node* OpenDoublyLinkedList<T, Node>::InsertEnd(T value){
    Node* new_node = new Node(value);

    return this->InsertEnd(new_node);
}


template <typename T, class Node>
Node* OpenDoublyLinkedList<T, Node>::RemoveBeginning(){
    Node* remove = this->head;

    if(remove == NULL) return remove;

    if(remove->next == NULL){
        this->head = NULL;
        this->tail = NULL;
        return remove;
    }

    (this->head->next)->prev = NULL;

    this->head = this->head->next;

    if(remove == this->tail){
        this->tail = NULL;
    }

    return remove;
}

template <typename T, class Node>
Node* OpenDoublyLinkedList<T, Node>::RemoveEnd(){
    Node* remove = this->tail;

    if(remove == NULL) return remove;

    if(remove->prev == NULL){
        this->head = NULL;
        this->tail = NULL;
        return remove;
    }

    (this->tail->prev)->next = NULL;

    this->tail = this->tail->prev;

    if(remove == this->head){
        this->head = NULL;
    }

    return remove;
}

template class OpenDoublyLinkedList<int>;
template class OpenDoublyLinkedList<double>;
