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

        template <typename T>
        class SingleLinkedList{
        public:
            class Node: public ForwardNode<T>{
            public:
                Node(T value):ForwardNode<T>(value){}
            };

            Node* head;

            SingleLinkedList();
            Node* Push(Node* node);
            Node* Push(T value);
            Node* Pop();
            int GetCount();
            string ToString();
        };
    }
}

namespace WrapperDataStr = Algorithms::DataStructures;

#endif /* DATA_STRUCTURES_HPP_ */
