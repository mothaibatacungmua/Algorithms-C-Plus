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

template <typename T, class Comp>
PriorityQueue<T, Comp>::PriorityQueue(int max_length){
    if(max_length <= 0) return;

    this->heap = new T[max_length];
    this->max_length = max_length;
    this->current_length = 0;
}

template <typename T, class Comp>
PriorityQueue<T, Comp>::~PriorityQueue(){
    delete this->heap;
}

template <typename T, class Comp>
void PriorityQueue<T, Comp>::HeapifyUp(int pos){
    if(pos > this->current_length-1) return;

    int travel = pos;
    T* parent = &this->heap[(travel-1)/2];
    T* current = &this->heap[travel];

    while(this->compar(*current, *parent) < 0){
        Utils::Swap(*current, *parent);
        travel = (travel - 1)/2;
        parent = &this->heap[(travel-1)/2];
        current = &this->heap[travel];
    }

}

template <typename T, class Comp>
void PriorityQueue<T, Comp>::HeapifyDown(int pos){
    if(pos > this->current_length-1) return;

    if((2*pos + 1) > current_length-1) return;

    int select_path = 2*pos + 1;
    if(2*pos + 2 <= current_length -1){
        select_path = this->compar(this->heap[2*pos + 1], this->heap[2*pos + 2]) > 0?(2*pos+2):(2*pos+1);
    }

    if(this->compar(this->heap[pos], this->heap[select_path]) > 0){
        Utils::Swap(this->heap[pos], this->heap[select_path]);
        return this->HeapifyDown(select_path);
    }
}

template <typename T, class Comp>
void PriorityQueue<T, Comp>::Push(T value){
    /* FIXME: realloc heap */
    if((current_length + 1) > max_length) return;

    this->heap[++current_length - 1] = value;

    return this->HeapifyUp(current_length - 1);
}

template <typename T, class Comp>
T PriorityQueue<T, Comp>::Pop(){
    T ret = this->heap[0];

    Utils::Swap(this->heap[0],this->heap[current_length-1]);

    current_length--;

    this->HeapifyDown(0);

    return ret;
}

template <typename T, class Comp>
T PriorityQueue<T, Comp>::GetTop(){
    return this->heap[0];
}

template <typename T, class Comp>
T PriorityQueue<T, Comp>::Delete(int pos){
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

template <typename T, class Comp>
T PriorityQueue<T, Comp>::operator [](int pos){
    return this->heap[pos > (current_length - 1)?(current_length - 1):pos];
}

template <typename T, class Comp>
int PriorityQueue<T, Comp>::GetCount(){
    return current_length;
}

template <typename T, class Comp>
string PriorityQueue<T, class Comp>::ToString(){
    string ret_str = "[";
    for(int i = 0; i < current_length; i++){
        ret_str.append(Utils::ToString(this->heap[i]));
    }

    ret_str.append("]");

    return ret_str;

}

template class PriorityQueue<int>;
template class PriorityQueue<double>;
