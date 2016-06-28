/*
 * union-find.cpp
 *
 *  Created on: Jun 28, 2016
 *      Author: asm
 */

#include <string>
#include <set>

#include "../../headers/type-parse.hpp"
#include "../../headers/data-structures.hpp"
#include "../../headers/error-codes.hpp"

using namespace DataStructures;


UnionFind::UnionFind(int key){
    this->key = key;
    this->size = 1;
    this->parent = this;
}

UnionFind::~UnionFind(){

}

UnionFind& UnionFind::Union(UnionFind& x){
    if(this->size > x.size){
        x.parent = this;
        this->size += x.size;
        return *this;
    }

    this->parent = &x;
    x.size += this->size;

    return x;
}

UnionFind* UnionFind::Find(){
    UnionFind* travel = this;
    UnionFind* parent = this->parent;

    while(parent != travel){
        travel = parent;
        parent = travel->parent;
    }

    return parent;
}
