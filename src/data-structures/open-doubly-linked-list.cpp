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

template <typename T>
OpenDoublyLinkedList<T>::OpenDoublyLinkedList(){

}

template <typename T>
OpenDoublyLinkedList<T>::~OpenDoublyLinkedList(){

}

template <typename T>
typename OpenDoublyLinkedList<T>::Node* OpenDoublyLinkedList<T>::InsertAfter(Node* node, Node* new_node){
    return (Node*)DoublyLinkedList<T>::InsertAfter(
            (typename DoublyLinkedList<T>::Node*)node,
            (typename DoublyLinkedList<T>::Node*)new_node);
}

template <typename T>
typename OpenDoublyLinkedList<T>::Node* OpenDoublyLinkedList<T>::InsertAfter(Node* node, T value){
    return (Node*)DoublyLinkedList<T>::InsertAfter(
            (typename DoublyLinkedList<T>::Node*)node,
            value);
}

template <typename T>
typename OpenDoublyLinkedList<T>::Node* OpenDoublyLinkedList<T>::InsertBefore(Node* node, Node* new_node){
    return (Node*)DoublyLinkedList<T>::InsertBefore(
            (typename DoublyLinkedList<T>::Node*)node,
            (typename DoublyLinkedList<T>::Node*)new_node);
}

template <typename T>
typename OpenDoublyLinkedList<T>::Node* OpenDoublyLinkedList<T>::InsertBefore(Node* node, T value){
    return (Node*)DoublyLinkedList<T>::InsertBefore(
            (typename DoublyLinkedList<T>::Node*)node,
            value);
}

template <typename T>
typename OpenDoublyLinkedList<T>::Node* OpenDoublyLinkedList<T>::InsertBeginning(Node* new_node){
    if(new_node == NULL)
        return NULL;

    if(this->head == NULL){
        this->head = new_node;
        this->tail = new_node;
        return new_node;
    }

    new_node->next = this->head;
    this->head->prev = new_node;
    new_node->prev = NULL;

    this->head = new_node;

    return new_node;
}
template <typename T>
typename OpenDoublyLinkedList<T>::Node* OpenDoublyLinkedList<T>::InsertBeginning(T value){
    Node* new_node = new Node(value);

    return this->InsertBeginning(new_node);
}

template <typename T>
typename OpenDoublyLinkedList<T>::Node* OpenDoublyLinkedList<T>::InsertEnd(Node* new_node){
    if(new_node == NULL)
        return NULL;

    if(this->tail == NULL){
        this->head = new_node;
        this->tail = new_node;
        return new_node;
    }

    new_node->next = NULL;
    this->tail->next = new_node;
    new_node->prev = this->tail;

    this->tail = new_node;

    return new_node;
}

template <typename T>
typename OpenDoublyLinkedList<T>::Node* OpenDoublyLinkedList<T>::InsertEnd(T value){
    Node* new_node = new Node(value);

    return this->InsertEnd(new_node);
}

template <typename T>
typename OpenDoublyLinkedList<T>::Node* OpenDoublyLinkedList<T>::Remove(Node* node){
    return (Node*)DoublyLinkedList<T>::Remove(
                (typename DoublyLinkedList<T>::Node*)node);
}

template <typename T>
typename OpenDoublyLinkedList<T>::Node* OpenDoublyLinkedList<T>::RemoveBeginning(){
    Node* remove = (Node*)this->head;

    if(remove == NULL) return remove;

    if(remove->next == NULL){
        this->head = NULL;
        this->tail = NULL;
        return remove;
    }

    (this->head->next)->prev = NULL;

    this->head = (Node*)this->head->next;

    return remove;
}

template <typename T>
typename OpenDoublyLinkedList<T>::Node* OpenDoublyLinkedList<T>::RemoveEnd(){
    Node* remove = (Node*)this->tail;

    if(remove == NULL) return remove;

    if(remove->prev == NULL){
        this->head = NULL;
        this->tail = NULL;
        return remove;
    }

    (this->tail->prev)->next = NULL;

    this->tail = (Node*)this->tail->prev;

    return remove;
}

template class OpenDoublyLinkedList<int>;
template class OpenDoublyLinkedList<double>;
