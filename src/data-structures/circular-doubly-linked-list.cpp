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

template <typename T>
CircularDoublyLinkedList<T>::CircularDoublyLinkedList(){

}

template <typename T>
CircularDoublyLinkedList<T>::~CircularDoublyLinkedList(){

}
template <typename T>
typename CircularDoublyLinkedList<T>::Node* CircularDoublyLinkedList<T>::InsertAfter(Node* node, Node* new_node){
    return (Node*)DoublyLinkedList<T>::InsertAfter(
            (typename DoublyLinkedList<T>::Node*) node,
            (typename DoublyLinkedList<T>::Node*) new_node);
}

template <typename T>
typename CircularDoublyLinkedList<T>::Node* CircularDoublyLinkedList<T>::InsertAfter(Node* node, T value){
    return (Node*)DoublyLinkedList<T>::InsertAfter(
            (typename DoublyLinkedList<T>::Node*)node,
            value);
}

template <typename T>
typename CircularDoublyLinkedList<T>::Node* CircularDoublyLinkedList<T>::InsertBefore(Node* node, Node* new_node){
    return (Node*)DoublyLinkedList<T>::InsertBefore(
            (typename DoublyLinkedList<T>::Node*)node,
            (typename DoublyLinkedList<T>::Node*)new_node);
}

template <typename T>
typename CircularDoublyLinkedList<T>::Node* CircularDoublyLinkedList<T>::InsertBefore(Node* node, T value){
    return (Node*)DoublyLinkedList<T>::InsertBefore(
            (typename DoublyLinkedList<T>::Node*)node,
            value);
}

template <typename T>
typename CircularDoublyLinkedList<T>::Node* CircularDoublyLinkedList<T>::InsertBeginning(Node* new_node){
    if(new_node == NULL)
        return NULL;

    if(this->head == NULL){
        this->head = (Node*)new_node;
        this->tail = (Node*)new_node;

        new_node->prev = (Node*)new_node;
        new_node->next = (Node*)new_node;
        return new_node;
    }

    this->InsertAfter((Node*)this->head, new_node);

    if(this->head == this->tail){
        this->tail = (Node*)new_node;
        this->head->prev= (Node*)new_node;
    }
    return new_node;
}
template <typename T>
typename CircularDoublyLinkedList<T>::Node* CircularDoublyLinkedList<T>::InsertBeginning(T value){
    Node* new_node = new Node(value);

    return this->InsertBeginning(new_node);
}

template <typename T>
typename CircularDoublyLinkedList<T>::Node* CircularDoublyLinkedList<T>::InsertEnd(Node* new_node){
    if(new_node == NULL)
        return NULL;

    if(this->tail == NULL){
        this->head = (Node*)new_node;
        this->tail = (Node*)new_node;

        new_node->prev = (Node*)new_node;
        new_node->next = (Node*)new_node;
        return new_node;
    }

    this->InsertAfter((Node*)this->tail, new_node);

    this->tail = new_node;
    if(this->head == this->tail){
        this->head->prev= new_node;
    }

    return new_node;
}
template <typename T>
typename CircularDoublyLinkedList<T>::Node* CircularDoublyLinkedList<T>::InsertEnd(T value){
    Node* new_node = new Node(value);

    return this->InsertEnd(new_node);
}

template <typename T>
typename CircularDoublyLinkedList<T>::Node* CircularDoublyLinkedList<T>::Remove(Node* node){
    return (Node*)DoublyLinkedList<T>::Remove(
                (typename DoublyLinkedList<T>::Node*)node);
}

template <typename T>
typename CircularDoublyLinkedList<T>::Node* CircularDoublyLinkedList<T>::RemoveBeginning(){
    Node* remove = (Node*)this->head;

    if(remove == NULL) return remove;

    if(remove->next == this->head){
        this->head = NULL;
        this->tail = NULL;
        return remove;
    }

    return (Node*)DoublyLinkedList<T>::Remove(
                    (typename DoublyLinkedList<T>::Node*)remove);
}

template <typename T>
typename CircularDoublyLinkedList<T>::Node* CircularDoublyLinkedList<T>::RemoveEnd(){
    Node* remove = (Node*)this->tail;

    if(remove == NULL) return remove;

    if(remove->next == this->tail){
        this->head = NULL;
        this->tail = NULL;
        return remove;
    }

    return (Node*)DoublyLinkedList<T>::Remove(
                    (typename DoublyLinkedList<T>::Node*)remove);
}

template class CircularDoublyLinkedList<int>;
template class CircularDoublyLinkedList<double>;
