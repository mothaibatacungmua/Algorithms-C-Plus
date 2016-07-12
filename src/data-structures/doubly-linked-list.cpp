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
#include "../../headers/error-codes.hpp"

using namespace DataStructures;

template <typename T, class Node>
DoublyLinkedList<T,Node>::DoublyLinkedList(){
    this->head = NULL;
    this->tail = NULL;
}

template <typename T, class Node>
DoublyLinkedList<T,Node>::~DoublyLinkedList(){
    //travel in list and delete
    if(this->head == NULL || this->tail == NULL)
        return;

    Node* travel = this->head;
    Node* save = travel;

    //forward traveling to delete all node
    try{
        while(travel != this->tail){
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

template <typename T, class Node>
Node* DoublyLinkedList<T,Node>::InsertAfter(Node* node, Node* new_node){
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

template <typename T, class Node>
Node* DoublyLinkedList<T,Node>::InsertAfter(Node* node, T value){
    Node* new_node = new Node(value);

    return this->InsertAfter(node, new_node);
}

template <typename T, class Node>
Node* DoublyLinkedList<T,Node>::InsertBefore(Node* node, Node* new_node){
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

template <typename T, class Node>
Node* DoublyLinkedList<T,Node>::InsertBefore(Node* node, T value){
    Node* new_node = new Node(value);

    return this->InsertBefore(node, new_node);
}

template <typename T, class Node>
Node* DoublyLinkedList<T,Node>::InsertBeginning(Node* new_node){
    /* NOT IMPLEMENTED */
    return NULL;
}

template <typename T, class Node>
Node* DoublyLinkedList<T,Node>::InsertEnd(Node* new_node){
    /* NOT IMPLEMENTED */
    return NULL;
}

template <typename T, class Node>
Node* DoublyLinkedList<T,Node>::InsertBeginning(T value){
    /* NOT IMPLEMENTED */
    return NULL;
}

template <typename T, class Node>
Node* DoublyLinkedList<T,Node>::InsertEnd(T value){
    /* NOT IMPLEMENTED */
    return NULL;
}

template <typename T, class Node>
Node* DoublyLinkedList<T,Node>::Find(T value){
    if(this->head == NULL || this->tail == NULL)
        return NULL;

    Node* travel = this->head;

    while(travel != this->tail){
        if(*travel == value)
            return travel;

        travel = travel->next;
    }

    if(this->tail != NULL && *travel == value){
        return travel;
    }

    return NULL;
}

template <typename T, class Node>
Node* DoublyLinkedList<T,Node>::Remove(Node* node){
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

template <typename T, class Node>
void DoublyLinkedList<T,Node>::RemoveBeginning(){
    if(this->head == NULL) return;

    Node* new_head = this->head->next;
    Node* remove_head = this->Remove(this->head);

    this->head = new_head;

    delete remove_head;
}

template <typename T, class Node>
void DoublyLinkedList<T,Node>::RemoveEnd(){
    if(this->tail == NULL) return;

    Node* new_tail = (Node*)this->tail->next;
    Node* remove_tail = this->Remove(this->tail);

    this->tail = new_tail;

    delete remove_tail;
}

template <typename T, class Node>
T DoublyLinkedList<T,Node>::Head(){
    if(this->head == NULL) throw ErrorCodes::OUT_OF_INDEX;

    return this->head->value;
}

template <typename T, class Node>
T DoublyLinkedList<T,Node>::Tail(){
    if(this->tail == NULL) throw ErrorCodes::OUT_OF_INDEX;

    return this->tail->value;
}

template <typename T, class Node>
int DoublyLinkedList<T,Node>::Size(){
    int count_node = 0;
    Node* travel = this->head;

    if(this->head != NULL)
        count_node = 1;

    //forward traveling to count all nodes
    while(travel != this->tail && travel != NULL){
        travel = travel->next;
        count_node++;
    }

    return count_node;
}

template <typename T, class Node>
std::string DoublyLinkedList<T,Node>::ToString(){
    std::string ret_str;
    Node* travel = this->head;
    char buffer[512];

    if(this->head == NULL){
        ret_str = "[]\n";
        return ret_str;
    }

    sprintf(buffer, "\n0x%X:[prev=0x%X, value=%s, next=0x%X]\n", (int)this->head, (int)this->head->prev, Utils::ToString(this->head->value).c_str(), (int)this->head->next);
    ret_str.append(buffer);

    if((int)this->head == (int)this->tail){
        return ret_str;
    }


    while(travel != this->tail){
       travel = (Node*)travel->next;
       sprintf(buffer, "\n0x%X:[prev=0x%X, value=%s, next=0x%X]\n", (int)travel, (int)travel->prev, Utils::ToString(travel->value).c_str(), (int)travel->next);
       ret_str.append(buffer);
    }

    return ret_str;
}

template class DoublyLinkedList<int>;
template class DoublyLinkedList<double>;

template class DoublyLinkedList<int, HashEntryNode<std::string> >;
template class DoublyLinkedList<int, HashEntryNode<int> >;
template class DoublyLinkedList<int, HashEntryNode<double> >;

template class DoublyLinkedList<int, HashEntryNode<Vector<double> > >;
template class DoublyLinkedList<int, HashEntryNode<SGraph::Edge> >;
template class DoublyLinkedList<int, HashEntryNode<UnionFind> >;
