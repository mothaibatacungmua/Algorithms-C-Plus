/*
 * data-structures.hpp
 *
 *  Created on: Apr 16, 2016
 *      Author: asm
 */

#ifndef DATA_STRUCTURES_HPP_
#define DATA_STRUCTURES_HPP_

#include <string>
#include "../headers/comparator.hpp"
#include "../headers/hashor.hpp"

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
    template <typename T, class Node=ForwardNode<T>>
    class SingleLinkedList{
    public:
        typedef Node NodeCls;
        Node* head;
        SingleLinkedList();
        virtual ~SingleLinkedList();
        virtual Node* Push(T value);
        virtual Node* Pop();
        virtual Node* Find(T value);
        virtual int GetCount();
        virtual string ToString();
    };

    //
    // Queue declare
    //
    template <typename T, class Node=ForwardNode<T>>
    class Queue:public SingleLinkedList<T, Node>{
    public:
        typedef Node NodeCls;
        Queue();
        virtual ~Queue();
        virtual Node* Push(T value);
        virtual Node* Pop();
    };

    //
    // Stack declare
    //
    template <typename T, class Node=ForwardNode<T>>
    class Stack:public SingleLinkedList<T, Node>{
    public:
        typedef Node NodeCls;
        Stack();
        virtual ~Stack();
        virtual Node* Push(T value);
        virtual Node* Pop();
    };

    //
    // Doubly linked list
    //
    template <typename T, class Node=CycleNode<T>>
    class DoublyLinkedList{
    public:
        /*
        class Node: public CycleNode<T>{
        public:
            Node(T value):CycleNode<T>(value){}
        };
        */
        typedef Node NodeCls;
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
        virtual Node* Find(T value);
        virtual Node* Remove(Node* node);
        virtual Node* RemoveBeginning();
        virtual Node* RemoveEnd();
        virtual int GetCount();
        virtual string ToString();
    };

    //
    // Open Doubly Linked List
    //
    template <typename T, class Node=CycleNode<T>>
    class OpenDoublyLinkedList: public DoublyLinkedList<T,Node>{
    public:
        typedef Node NodeCls;
        OpenDoublyLinkedList();
        virtual ~OpenDoublyLinkedList();
        virtual Node* InsertBeginning(Node* new_node);
        virtual Node* InsertBeginning(T value);
        virtual Node* InsertEnd(Node* new_node);
        virtual Node* InsertEnd(T value);
        virtual Node* RemoveBeginning();
        virtual Node* RemoveEnd();
    };

    //
    // Circular Doubly Linked List
    //
    template <typename T, class Node=CycleNode<T>>
    class CircularDoublyLinkedList: public DoublyLinkedList<T,Node>{
    public:
        typedef Node NodeCls;
        CircularDoublyLinkedList();
        virtual ~CircularDoublyLinkedList();
        virtual Node* InsertBeginning(Node* new_node);
        virtual Node* InsertBeginning(T value);
        virtual Node* InsertEnd(Node* new_node);
        virtual Node* InsertEnd(T value);
        virtual Node* RemoveBeginning();
        virtual Node* RemoveEnd();
    };

    //
    // Priority Queue
    //
    template <typename T, class Comp=Utils::Comparator<T>>
    class PriorityQueue{
    public:
        PriorityQueue(int max_length);
        ~PriorityQueue();
        T* heap;
        void Push(T value);
        T GetTop();
        T Pop();
        string ToString();
        int GetCount();
        T operator[](int pos);
        T Delete(int pos);
    private:
        int max_length;
        int current_length;
        void HeapifyUp(int pos);
        void HeapifyDown(int pos);
        Comp compar;
    };

    //
    // Hashmap
    //
    template <typename K, typename V, class Hash=Utils::JenkinsHash>
    class Hashmap{
    public:
        class HashEntryNode{
        public:
            HashEntryNode* next;
            HashEntryNode* prev;
            HashEntryNode(int index, V value){
                this->index = index;
                this->value = value;
                this->next = this->prev = NULL;
            }

            int index;
            V value;

            bool operator==(const HashEntryNode& A, const HashEntryNode& B){
                return (A.index == B.index);
            }
        };
        Hashmap(int bucket_length);
        ~Hashmap();
        CircularDoublyLinkedList<int, HashEntryNode>** map;
        void Set(K key, V value);
        bool Get(K key, V& ret);
        int GetCount();
        string ToString();
    private:
        int bucket_length;
        Hash hash;
    };
}


#endif /* DATA_STRUCTURES_HPP_ */
