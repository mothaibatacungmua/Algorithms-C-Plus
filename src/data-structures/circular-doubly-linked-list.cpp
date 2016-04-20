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
    /* NOT IMPLEMENTED */
    return NULL;
}

template <typename T>
typename CircularDoublyLinkedList<T>::Node* CircularDoublyLinkedList<T>::InsertEnd(Node* new_node){
    /* NOT IMPLEMENTED */
    return NULL;
}

template <typename T>
typename CircularDoublyLinkedList<T>::Node* CircularDoublyLinkedList<T>::Remove(Node* node){
    return (Node*)DoublyLinkedList<T>::Remove(
                (typename DoublyLinkedList<T>::Node*)node);
}
