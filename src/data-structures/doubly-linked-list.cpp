/*
 * doubly-linked-list.cpp
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
            travel = travel->next;
            delete save;
            save = travel;
        }
    }catch(const std::exception& e){
        //do nothing
    }
}

template <typename T>
typename DoublyLinkedList<T>::Node* DoublyLinkedList<T>::InsertAfter(Node* node, Node* new_node){
    if(node == NULL || new_node == NULL)
        return NULL;

    Node* save = node->next;

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

    Node* save = node->prev;

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
typename DoublyLinkedList<T>::Node* DoublyLinkedList<T>::Remove(Node* node){
    if(node == NULL)
        return NULL;

    Node* next = node->next;
    Node* prev = node->prev;

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

    Node* new_head = head->next;
    Node* remove_head = this->Remove(head);

    head = new_head;

    return remove_head;
}

template <typename T>
typename DoublyLinkedList<T>::Node* DoublyLinkedList<T>::RemoveEnd(){
    if(tail == NULL)
        return NULL;

    Node* new_tail = tail->next;
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

    //forward traveling to delete all node
    while(travel != tail){
        travel = travel->next;
        count_node++;
    }

    return count_node;
}
