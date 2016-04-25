/*
 * priority-queue.cpp
 *
 *  Created on: Apr 24, 2016
 *      Author: asm
 */
#include <iostream>
#include <string>
#include "../../headers/type-parse.hpp"
#include "../../headers/data-structures.hpp"
#include "../../headers/misc.hpp"

using namespace DataStructures;

template <typename T>
PriorityQueue<T>::PriorityQueue(int max_length, int(*compar)(const T, const T)){
    if(max_length <= 0) return;

    this->heap = new T[max_length];
    this->max_length = max_length;
    this->current_length = 0;
    this->compar = compar;
}

template <typename T>
PriorityQueue<T>::~PriorityQueue(){
    delete this->heap;
}

template <typename T>
void PriorityQueue<T>::HeapifyUp(int pos){
    if(pos > this->current_length-1) return;

    int travel = pos;
    T* parent = &this->heap[(travel-1)/2];
    T* current = &this->heap[travel];

    while(Utils::DoCompare(*current, *parent) < 0){
        Utils::Swap(*current, *parent);
        travel = (travel - 1)/2;
        parent = &this->heap[(travel-1)/2];
        current = &this->heap[travel];
    }

}

template <typename T>
void PriorityQueue<T>::HeapifyDown(int pos){
    if(pos > this->current_length-1) return;

    if((2*pos + 1) > current_length-1) return;

    if(Utils::DoCompare(this->heap[pos], this->heap[2*pos + 1]) > 0){
        Utils::Swap(this->heap[pos], this->heap[2*pos + 1]);
        return this->HeapifyDown(2*pos + 1);
    }

    if(Utils::DoCompare(this->heap[pos], this->heap[2*pos + 2]) > 0){
        Utils::Swap(this->heap[pos], this->heap[2*pos + 2]);
        return this->HeapifyDown(2*pos + 2);
    }
}

template <typename T>
void PriorityQueue<T>::Push(T value){
    /* FIXME: realloc heap */
    if((current_length + 1) > max_length) return;

    this->heap[++current_length - 1] = value;

    return this->HeapifyUp(current_length - 1);
}

template <typename T>
T PriorityQueue<T>::Pop(){
    T ret = this->heap[0];

    Utils::Swap(this->heap[0],this->heap[current_length-1]);

    current_length--;

    this->HeapifyDown(0);

    return ret;
}

template <typename T>
T PriorityQueue<T>::GetTop(){
    return this->heap[0];
}

template <typename T>
T PriorityQueue<T>::Delete(int pos){
    T ret = this->heap[current_length-1];
    current_length--;

    if(pos > current_length-1){
        return ret;
    }

    ret = this->heap[pos];
    Utils::Swap(this->heap[pos], this->heap[current_length-1]);

    this->HeapifyDown(pos);

    return ret;
}

template <typename T>
T PriorityQueue<T>::operator [](int pos){
    return this->heap[pos > (current_length - 1)?(current_length - 1):pos];
}

template <typename T>
int PriorityQueue<T>::GetCount(){
    return current_length;
}

template <typename T>
string PriorityQueue<T>::ToString(){
    string ret_str = "[";
    for(int i = 0; i < current_length; i++){
        ret_str.append(Utils::ToString(this->heap[i]));
    }

    ret_str.append("]");

    return ret_str;

}

template class PriorityQueue<int>;
template class PriorityQueue<double>;
