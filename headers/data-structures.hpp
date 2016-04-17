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

namespace Algorithms{

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
            virtual ~SingleLinkedList(){};
            virtual Node* Push(Node* node);
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
            virtual ~Queue(){};
            virtual Node* Push(Node* node);
            virtual Node* Push(T value);
            virtual Node* Pop();
            virtual int GetCount();
            virtual string ToString();
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
            virtual ~Stack(){};
            virtual Node* Push(Node* node);
            virtual Node* Push(T value);
            virtual Node* Pop();
            virtual int GetCount();
            virtual string ToString();
        };
    }
}

namespace WrapperDataStr = Algorithms::DataStructures;

#endif /* DATA_STRUCTURES_HPP_ */
