/*
 * circular-doubly-linked-list.cpp
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
CircularDoublyLinkedList<T,Node>::CircularDoublyLinkedList(){

}

template <typename T, class Node>
CircularDoublyLinkedList<T,Node>::~CircularDoublyLinkedList(){

}

template <typename T, class Node>
Node* CircularDoublyLinkedList<T,Node>::InsertBeginning(Node* new_node){
    if(new_node == NULL)
        return NULL;

    if(this->head == NULL){
        this->head = new_node;
        this->tail = this->head;

        new_node->prev = new_node;
        new_node->next = new_node;
        return new_node;
    }

    this->InsertAfter(this->head, new_node);

    if(this->head == this->tail){
        this->tail = new_node;
        this->head->prev = new_node;
    }
    return new_node;
}
template <typename T, class Node>
Node* CircularDoublyLinkedList<T,Node>::InsertBeginning(T value){
    Node* new_node = new Node(value);

    return this->InsertBeginning(new_node);
}

template <typename T, class Node>
Node* CircularDoublyLinkedList<T,Node>::InsertEnd(Node* new_node){
    if(new_node == NULL)
        return NULL;

    if(this->tail == NULL){
        this->head = new_node;
        this->tail = new_node;

        new_node->prev = new_node;
        new_node->next = new_node;
        return new_node;
    }

    this->InsertAfter(this->tail, new_node);

    this->tail = new_node;
    if(this->head == this->tail){
        this->head->prev= new_node;
    }

    return new_node;
}
template <typename T, class Node>
Node* CircularDoublyLinkedList<T,Node>::InsertEnd(T value){
    Node* new_node = new Node(value);

    return this->InsertEnd(new_node);
}

template <typename T, class Node>
Node* CircularDoublyLinkedList<T,Node>::RemoveBeginning(){
    Node* remove = this->head;

    if(remove == NULL) return remove;

    if(remove->next == this->head){
        this->head = NULL;
        this->tail = NULL;
        return remove;
    }

    remove = DoublyLinkedList<T>::Remove(remove);

    this->head = this->tail->next;
    if(this->tail->next == this->tail){
        this->head = this->tail;
    }

    return remove;
}

template <typename T, class Node>
Node* CircularDoublyLinkedList<T,Node>::RemoveEnd(){
    Node* remove = this->tail;

    if(remove == NULL) return remove;

    if(remove->next == this->tail){
        this->head = NULL;
        this->tail = NULL;
        return remove;
    }

    remove = DoublyLinkedList<T>::Remove(remove);

    this->tail = this->head->prev;
    if(this->head->next == this->head){
        this->tail = this->head;
    }
    return remove;
}

template class CircularDoublyLinkedList<int>;
template class CircularDoublyLinkedList<double>;
