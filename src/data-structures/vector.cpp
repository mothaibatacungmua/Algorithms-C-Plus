/*
 * vector.cpp
 *
 *  Created on: May 15, 2016
 *      Author: asm
 */

#include <string>

#include "../../headers/type-parse.hpp"
#include "../../headers/data-structures.hpp"
#include "../../headers/error-codes.hpp"
#include "../../headers/misc.hpp"

using namespace DataStructures;

template <typename V>
Vector<V>::Vector(){

}

template <typename V>
Vector<V>::Vector(int length){
    this->storage.resize(length);
}

template <typename V>
Vector<V>::Vector(V* values, int length){
    this->storage.resize(length);

    for(int i = 0; i < length; i++){
        this->storage[i] = values[i];
    }
}


template <typename V>
Vector<V>::~Vector(){
    this->storage.clear();
}

template <typename V>
vector<V>& Vector<V>::GetStorage(){
    return this->storage;
}

template <typename V>
vector<V>& Vector<V>::SetStorage(Vector<V>& x){
    this->storage = x.GetStorage();

    return this->storage;
}

template <typename V>
int Vector<V>::Size(){
    return this->storage.size();
}

template <typename V>
int Vector<V>::Resize(int length){
    int old_len = this->Size();

    this->storage.resize(length);

    return old_len;
}

template <typename V>
Vector<V>& Vector<V>::operator =(Vector<V>& x){
    this->SetStorage(x);

    return *this;
}

template <typename V>
V Vector<V>::operator [](int index) const{
    return this->storage[index];
}

template <typename V>
V& Vector<V>::operator [](int index){
    return this->storage[index];
}

template <typename V>
Vector<V>* Vector<V>::Copy(){
    Vector<V>* new_v = new Vector();

    *new_v = *this;

    return new_v;
}

template <typename V>
string Vector<V>::ToString(){
    string ret = "";

    for(int i = 0; i < this->storage.size(); i++){
        ret.append(" ");
        ret.append(Utils::ToString(this->storage[i]));
        ret.append(" ");
    }

    return ret;
}

template class Vector<int>;
template class Vector<double>;
template class Vector<string>;
