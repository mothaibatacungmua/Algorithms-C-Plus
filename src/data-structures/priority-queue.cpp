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
#include "../../headers/error-codes.hpp"

using namespace DataStructures;

template <typename T, class Comp>
PriorityQueue<T,Comp>::PriorityQueue(int max_length){
    if(max_length <= 0) return;

    this->heap.resize(max_length);
    this->max_length = max_length;
    this->current_length = 0;
}

template <typename T, class Comp>
PriorityQueue<T,Comp>::~PriorityQueue(){
    this->heap.clear();
}

template <typename T, class Comp>
int PriorityQueue<T,Comp>::HeapifyUp(int pos){
    if(pos > this->current_length-1) return -1;

    int travel = pos;
    T* parent = &this->heap[(travel-1)/2];
    T* current = &this->heap[travel];

    while(this->compar(*current, *parent) < 0){
        Utils::Swap(*current, *parent);
        travel = (travel - 1)/2;
        parent = &this->heap[(travel-1)/2];
        current = &this->heap[travel];
    }

    return travel;
}

template <typename T, class Comp>
int PriorityQueue<T,Comp>::HeapifyDown(int pos){
    if(pos > this->current_length-1) return -1;

    if((2*pos + 1) > current_length-1) return pos;

    int select_path = 2*pos + 1;
    if(2*pos + 2 <= current_length -1){
        select_path = this->compar(this->heap[2*pos + 1], this->heap[2*pos + 2]) > 0?(2*pos+2):(2*pos+1);
    }

    if(this->compar(this->heap[pos], this->heap[select_path]) > 0){
        Utils::Swap(this->heap[pos], this->heap[select_path]);
        return this->HeapifyDown(select_path);
    }

    return pos;
}

template <typename T, class Comp>
int PriorityQueue<T,Comp>::Push(T value){
    /* FIXME: realloc heap */
    if((current_length + 1) > max_length) return -1;

    this->heap[++current_length - 1] = value;

    return this->HeapifyUp(current_length - 1);
}

template <typename T, class Comp>
int PriorityQueue<T,Comp>::ChangeValue(T value, int pos){
    this->heap[pos] = value;

    int up = this->HeapifyUp(pos);
    int down = this->HeapifyDown(pos);

    if(up == -1 && down == -1) return -1;
    if(up != pos && up != -1) return up;
    if(down != pos && down != -1) return down;

    return pos;
}

template <typename T, class Comp>
void PriorityQueue<T,Comp>::Pop(){
    if(current_length <= 0) return;

    Utils::Swap(this->heap[0],this->heap[current_length-1]);

    current_length--;

    this->HeapifyDown(0);
}

template <typename T, class Comp>
T PriorityQueue<T,Comp>::Head(){
    if(current_length <= 0) throw ErrorCodes::OUT_OF_INDEX;

    return this->heap[0];
}

template <typename T, class Comp>
T PriorityQueue<T,Comp>::Delete(int pos){
    if(current_length <= 0) throw ErrorCodes::OUT_OF_INDEX;

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
T PriorityQueue<T,Comp>::operator [](int pos){
    if(current_length <= 0) throw ErrorCodes::OUT_OF_INDEX;

    return this->heap[pos > (current_length - 1)?(current_length - 1):pos];
}

template <typename T, class Comp>
int PriorityQueue<T,Comp>::Size(){
    return current_length;
}

template <typename T, class Comp>
int PriorityQueue<T,Comp>::Find(T value){
    int travel = 0;

    while(travel < current_length){
        if(this->heap[travel] == value) return travel;

        if(this->heap[travel] > value) travel = travel*2+2;
        else travel = travel*2+1;
    }

    return -1;
}

template <typename T, class Comp>
std::string PriorityQueue<T,Comp>::ToString(){
    std::string ret_str = "[";
    for(int i = 0; i < current_length; i++){
        ret_str.append(Utils::ToString(this->heap[i]));
    }

    ret_str.append("]");

    return ret_str;

}

template class PriorityQueue<int>;
template class PriorityQueue<double>;
template class PriorityQueue<SGraph::Path>;
template class PriorityQueue<SGraph::WeightedVertex>;
template class PriorityQueue<SGraph::Edge>;
template class PriorityQueue<SGraph::MinEdge>;
