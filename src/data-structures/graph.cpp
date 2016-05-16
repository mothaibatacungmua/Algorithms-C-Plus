/*
 * graph.cpp
 *
 *  Created on: May 15, 2016
 *      Author: asm
 */

#include <string>

/* FIXME: Use a hand-written Set structure */
#include <set>
/*******************************************/

#include "../../headers/type-parse.hpp"
#include "../../headers/data-structures.hpp"
#include "../../headers/error-codes.hpp"

using namespace DataStructures;

Graph::Graph(int n_vertex):Matrix<double>(n_vertex, n_vertex){
    this->nver = n_vertex;
}


Graph::Graph(Vector<double>* vectors, int nvec):Matrix<double>(vectors, nvec, false, true){
    this->nver = nvec;
}

Graph::~Graph(){

}

bool Graph::IsConnected(){
    Stack<int> travel_vertex;
    set<int> closed;
    int current_vertex = 0;
    travel_vertex.Push(0);

    while(travel_vertex.Size() != 0){
        current_vertex = travel_vertex.Pop();
        closed.insert(current_vertex);

        for(int i=0; i < this->nver; i++){
            if(this->matrix[current_vertex][i] != 0 &&
               closed.find(i) == closed.end()){
                travel_vertex.Push(i);
            }
        }
    }

    if(closed.size() == this->nver) return true;

    return false;
}


bool Graph::IsTree(){
    Stack<int> travel_vertex;
    set<int> closed;
    set<int>::iterator it;
    int current_vertex = 0;
    travel_vertex.Push(0);

    while(travel_vertex.Size() != 0){
        current_vertex = travel_vertex.Pop();
        closed.insert(current_vertex);

        for(int i=0; i < this->nver; i++){
            if(this->matrix[current_vertex][i] != 0 &&
               closed.find(i) == closed.end()){

                for(it=closed.begin; it != closed.end(); ++it){
                    if(this->matrix[i][*it] != 0) return false;
                }
                travel_vertex.Push(i);
            }
        }
    }

    return true;
}

bool Graph::DeleteEdge(Graph::Edge edge, bool undirected){
    if(edge.head >= this->nver || edge.tail >= this->nver)
        return false;

    this->matrix[edge.head][edge.tail] = 0;
    if(undirected){
        this->matrix[edge.tail][edge.head] = 0;
    }
    return true;
}

bool Graph::DeleteEdge(Vector<Graph::Edge> edge, bool undirected){
    if(edge.Size() == 0) return false;

    for(int i = 0; i < edge.Size(); i++){
        this->DeleteEdge(edge[i], undirected);
    }

    return true;
}

bool Graph::DeleteVertex(int vertex){

    if(!this->DeleteColumn(vertex) || !this->DeleteColumn(vertex))
        return false;

    this->nver--;
    return true;
}

bool Graph::DeleteVertex(Vector<int> vertex){
    return true;
}
