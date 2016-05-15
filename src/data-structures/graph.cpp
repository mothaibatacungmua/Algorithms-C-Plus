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

Graph::Graph(int n_vertex):Matrix<double>(n_vertex, n_vertex){

}


Graph::Graph(Vector<double>* vectors, int nvec):Matrix<double>(vectors, nvec, false){

}

Graph::~Graph(){

}
