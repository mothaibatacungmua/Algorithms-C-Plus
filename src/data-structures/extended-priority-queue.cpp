/*
 * extended-priority-queue.cpp
 *
 *  Created on: Jul 12, 2016
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
ExtendedPriorityQueue<T,Comp>::ExtendedPriorityQueue(int max_length){
    if(max_length <= 0) return;

    this->map_indices = new Hashmap<int, int>();
    this->heap.resize(max_length);
    this->max_length = max_length;
    this->current_length = 0;
}

template <typename T, class Comp>
ExtendedPriorityQueue<T,Comp>::~ExtendedPriorityQueue(){
    this->heap.clear();
    delete this->map_indices;
}

template <typename T, class Comp>
int ExtendedPriorityQueue<T,Comp>::HeapifyUp(int pos){
    if(pos > this->current_length-1) return -1;

    int travel = pos;
    T* parent = &this->heap[(travel-1)/2];
    T* current = &this->heap[travel];

    while(this->compar(*current, *parent) < 0){
        this->SwapValueByKey(current->GetKey(), parent->GetKey());
        Utils::Swap(*current, *parent);
        travel = (travel - 1)/2;
        parent = &this->heap[(travel-1)/2];
        current = &this->heap[travel];
    }

    return travel;
}

template <typename T, class Comp>
int ExtendedPriorityQueue<T,Comp>::HeapifyDown(int pos){
    if(pos > this->current_length-1) return -1;

    if((2*pos + 1) > current_length-1) return pos;

    int select_path = 2*pos + 1;
    if(2*pos + 2 <= current_length -1){
        select_path = this->compar(this->heap[2*pos + 1], this->heap[2*pos + 2]) > 0?(2*pos+2):(2*pos+1);
    }

    if(this->compar(this->heap[pos], this->heap[select_path]) > 0){
        this->SwapValueByKey(this->heap[pos].GetKey(), this->heap[select_path].GetKey());
        Utils::Swap(this->heap[pos], this->heap[select_path]);
        return this->HeapifyDown(select_path);
    }

    return pos;
}

template <typename T, class Comp>
int ExtendedPriorityQueue<T,Comp>::Push(T value){
    /* FIXME: realloc heap */
    if((current_length + 1) > max_length) return -1;

    this->heap[++current_length - 1] = value;
    this->map_indices->Set(value.GetKey(), current_length - 1);

    return this->HeapifyUp(current_length - 1);
}

template <typename T, class Comp>
int ExtendedPriorityQueue<T,Comp>::ChangeValue(T value, int pos){
    this->heap[pos] = value;

    int up = this->HeapifyUp(pos);
    int down = this->HeapifyDown(pos);

    if(up == -1 && down == -1) return -1;
    if(up != pos && up != -1) return up;
    if(down != pos && down != -1) return down;

    return pos;
}

template <typename T, class Comp>
void ExtendedPriorityQueue<T,Comp>::Pop(){
    if(current_length <= 0) return;

    this->SwapValueByKey(this->heap[0].GetKey(), this->heap[current_length-1].GetKey());
    Utils::Swap(this->heap[0],this->heap[current_length-1]);

    current_length--;

    this->HeapifyDown(0);
}

template <typename T, class Comp>
T ExtendedPriorityQueue<T,Comp>::Head(){
    if(current_length <= 0) throw ErrorCodes::OUT_OF_INDEX;

    return this->heap[0];
}

template <typename T, class Comp>
T ExtendedPriorityQueue<T,Comp>::Delete(int pos){
    if(current_length <= 0) throw ErrorCodes::OUT_OF_INDEX;

    T ret = this->heap[current_length-1];
    current_length--;

    if(pos > current_length-1){
        return ret;
    }

    ret = this->heap[pos];

    this->SwapValueByKey(this->heap[pos].GetKey(), this->heap[current_length-1].GetKey());
    Utils::Swap(this->heap[pos], this->heap[current_length-1]);

    this->HeapifyDown(pos);

    return ret;
}

template <typename T, class Comp>
T ExtendedPriorityQueue<T,Comp>::operator [](int pos){
    if(current_length <= 0) throw ErrorCodes::OUT_OF_INDEX;

    return this->heap[pos > (current_length - 1)?(current_length - 1):pos];
}

template <typename T, class Comp>
int ExtendedPriorityQueue<T,Comp>::Size(){
    return current_length;
}

template <typename T, class Comp>
int ExtendedPriorityQueue<T,Comp>::Find(T value){
    int travel = 0;

    while(travel < current_length){
        if(this->heap[travel] == value) return travel;

        if(this->heap[travel] > value) travel = travel*2+2;
        else travel = travel*2+1;
    }

    return -1;
}

template <typename T, class Comp>
void ExtendedPriorityQueue<T,Comp>::SwapValueByKey(int k1, int k2){
    int i1, i2;

    if(!this->map_indices->Get(k1, i1)) return;
    if(!this->map_indices->Get(k2, i2)) return;

    this->map_indices->Set(k1, i2);
    this->map_indices->Set(k2, i1);
}

template <typename T, class Comp>
std::string ExtendedPriorityQueue<T,Comp>::ToString(){
    std::string ret_str = "[";
    for(int i = 0; i < current_length; i++){
        ret_str.append(Utils::ToString(this->heap[i]));
    }

    ret_str.append("]");

    return ret_str;

}

template <typename T, class Comp>
int ExtendedPriorityQueue<T,Comp>::GetIndexByKey(int k){
    int i;

    if(!this->map_indices->Get(k, i)) return -1;

    return i;
}

template class ExtendedPriorityQueue<SGraph::MinEdge>;


