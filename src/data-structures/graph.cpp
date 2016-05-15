/*
 * graph.cpp
 *
 *  Created on: May 15, 2016
 *      Author: asm
 */

#include <string>

#include "../../headers/type-parse.hpp"
#include "../../headers/data-structures.hpp"
#include "../../headers/error-codes.hpp"

using namespace DataStructures;

template <typename V>
Graph<V>::Graph(int n_vertex):Matrix<V>(n_vertex, n_vertex){

}

template <typename V>
Graph<V>::Graph(Vector<V>* vectors, int nvec):Matrix<V>(vectors, nvec, false){

}

