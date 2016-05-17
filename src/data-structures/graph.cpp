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

Graph::Graph(int n_vertex){
    this->nver = n_vertex;
    /* 100 vertex */
    this->adjac = new Hashmap<int, Vector<double> >(n_vertex+1);
}


Graph::Graph(Vector<double>* vectors, int nvec){
    this->nver = nvec;
    this->adjac = new Hashmap<int, Vector<double> >(nvec+1);

    for(int i=0; i < nvec; i++){
        this->adjac->Set(i, vectors[i]);
    }
}

Graph::~Graph(){
    delete this->adjac;
}

bool Graph::IsConnected(){
    Stack<int> travel_vertex;
    set<int> closed;
    int current_vertex = 0;
    travel_vertex.Push(0);

    while(travel_vertex.Size() != 0){
        current_vertex = travel_vertex.Head();
        travel_vertex.Pop();
        closed.insert(current_vertex);

        for(int i=0; i < this->nver; i++){
            if((*this->adjac)[current_vertex][i] != 0 &&
               closed.find(i) == closed.end()){
                travel_vertex.Push(i);
            }
        }
    }

    if(closed.size() == (size_t)this->nver) return true;

    return false;
}


bool Graph::IsTree(){
    Stack<int> travel_vertex;
    set<int> closed;
    set<int>::iterator it;
    int current_vertex = 0;
    travel_vertex.Push(0);

    while(travel_vertex.Size() != 0){
        current_vertex = travel_vertex.Head();
        travel_vertex.Pop();
        closed.insert(current_vertex);

        for(int i=0; i < this->nver; i++){
            if((*this->adjac)[current_vertex][i] != 0 &&
               closed.find(i) == closed.end()){

                for(it=closed.begin(); it != closed.end(); ++it){
                    if((*this->adjac)[i][*it] != 0) return false;
                }
                travel_vertex.Push(i);
            }
        }
    }

    return true;
}

Vector<double>& Graph::operator[](int index){
    if(index >= this->nver) throw ErrorCodes::OUT_OF_INDEX;

    return (*this->adjac)[index];
}

bool Graph::DeleteEdge(Graph::Edge edge, bool undirected){
    if(edge.head >= this->nver || edge.tail >= this->nver)
        return false;

    (*this->adjac)[edge.head][edge.tail] = 0;
    if(undirected){
        (*this->adjac)[edge.tail][edge.head] = 0;
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

    this->nver--;
    return true;
}

bool Graph::DeleteVertex(Vector<int> vertex){
    return true;
}
