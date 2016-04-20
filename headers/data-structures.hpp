/*
 * data-structures.hpp
 *
 *  Created on: Apr 16, 2016
 *      Author: asm
 */

#ifndef DATA_STRUCTURES_HPP_
#define DATA_STRUCTURES_HPP_

#include <string>
using namespace std;


namespace DataStructures{
    template <typename T>
    class ForwardNode{
    public:
        ForwardNode<T>* next;
        T value;

        ForwardNode(T value){
            next = NULL;
            this->value = value;
        }
        bool operator== (const ForwardNode<T>& a){
            return (value == a.value);
        }
    };

    template <typename T>
    class CycleNode{
    public:
        CycleNode<T>* next;
        CycleNode<T>* prev;
        T value;

        CycleNode(T value){
            next = prev = NULL;
            this->value = value;
        }

        bool operator== (const CycleNode<T>& a){
            return (value == a.value);
        }
    };
    //
    // Single Linked List declare
    //
    template <typename T>
    class SingleLinkedList{
    public:
        class Node: public ForwardNode<T>{
        public:
            Node(T value):ForwardNode<T>(value){}
        };

        Node* head;

        SingleLinkedList();
        virtual ~SingleLinkedList();
        virtual Node* Push(T value);
        virtual Node* Pop();
        virtual int GetCount();
        virtual string ToString();
    };

    //
    // Queue declare
    //
    template <typename T>
    class Queue:public SingleLinkedList<T>{
    public:
        class Node: public SingleLinkedList<T>::Node{
        public:
            Node(T value):SingleLinkedList<T>::Node(value){}
        };

        Queue();
        virtual ~Queue();
        virtual Node* Push(T value);
        virtual Node* Pop();
    };

    //
    // Stack declare
    //
    template <typename T>
    class Stack:public SingleLinkedList<T>{
    public:
        class Node: public SingleLinkedList<T>::Node{
        public:
            Node(T value):SingleLinkedList<T>::Node(value){}
        };

        Stack();
        virtual ~Stack();
        virtual Node* Push(T value);
        virtual Node* Pop();
    };

    //
    // Doubly linked list
    //
    template <typename T>
    class DoublyLinkedList{
    public:
        class Node: public CycleNode<T>{
        public:
            Node(T value):CycleNode<T>(value){}
        };

        DoublyLinkedList();
        Node* head;
        Node* tail;
        virtual ~DoublyLinkedList();
        virtual Node* InsertAfter(Node* node, Node* new_node);
        virtual Node* InsertAfter(Node* node, T value);
        virtual Node* InsertBefore(Node* node, Node* new_node);
        virtual Node* InsertBefore(Node* node, T value);
        virtual Node* InsertBeginning(Node* new_node);
        virtual Node* InsertBeginning(T value);
        virtual Node* InsertEnd(Node* new_node);
        virtual Node* InsertEnd(T value);
        virtual Node* Remove(Node* node);
        virtual Node* RemoveBeginning();
        virtual Node* RemoveEnd();
        virtual int GetCount();
        virtual string ToString();
    };

    //
    // Open Doubly Linked List
    //
    template <typename T>
    class OpenDoublyLinkedList: public DoublyLinkedList<T>{
    public:
        class Node: public DoublyLinkedList<T>::Node{
        public:
            Node(T value):DoublyLinkedList<T>::Node(value){}
        };

        OpenDoublyLinkedList();
        virtual ~OpenDoublyLinkedList();
        virtual Node* InsertAfter(Node* node, Node* new_node);
        virtual Node* InsertAfter(Node* node, T value);
        virtual Node* InsertBefore(Node* node, Node* new_node);
        virtual Node* InsertBefore(Node* node, T value);
        virtual Node* InsertBeginning(Node* new_node);
        virtual Node* InsertBeginning(T value);
        virtual Node* InsertEnd(Node* new_node);
        virtual Node* InsertEnd(T value);
        virtual Node* Remove(Node* node);
        virtual Node* RemoveBeginning();
        virtual Node* RemoveEnd();
    };

    //
    // Circular Doubly Linked List
    //
    template <typename T>
    class CircularDoublyLinkedList: public DoublyLinkedList<T>{
    public:
        class Node: public DoublyLinkedList<T>::Node{
        public:
            Node(T value):DoublyLinkedList<T>::Node(value){}
        };

        CircularDoublyLinkedList();
        virtual ~CircularDoublyLinkedList();
        virtual Node* InsertAfter(Node* node, Node* new_node);
        virtual Node* InsertAfter(Node* node, T value);
        virtual Node* InsertBefore(Node* node, Node* new_node);
        virtual Node* InsertBefore(Node* node, T value);
        virtual Node* InsertBeginning(Node* new_node);
        virtual Node* InsertBeginning(T value);
        virtual Node* InsertEnd(Node* new_node);
        virtual Node* InsertEnd(T value);
        virtual Node* Remove(Node* node);
        virtual Node* RemoveBeginning();
        virtual Node* RemoveEnd();
    };
}


#endif /* DATA_STRUCTURES_HPP_ */
