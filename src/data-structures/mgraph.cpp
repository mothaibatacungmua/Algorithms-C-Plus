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
#include <limits>

using namespace DataStructures;

MGraph::MGraph(int n_vertex, bool undirected):Matrix<double>(n_vertex, n_vertex){
    for(int i=0; i< n_vertex; i++){
        vertices.Insert(i);
    }

    for(int i = 0; i < n_vertex; i++){
        for(int j = 0; j < n_vertex; j++){
            (*this)[i][j] = std::numeric_limits<double>::max();
        }
    }

    this->undirected = undirected;
}


MGraph::MGraph(Vector<double>* vectors, int nvec):Matrix<double>(vectors, nvec, false, true){
    for(int i=0; i< nvec; i++){
        vertices.Insert(i);
    }

    this->undirected = false;
}

MGraph::~MGraph(){

}

bool MGraph::IsConnected(){
    Stack<int> travel_vertex;
    std::set<int> closed;
    int current_vertex = 0;
    travel_vertex.Push(0);

    while(travel_vertex.Size() != 0){
        current_vertex = travel_vertex.Head();
        travel_vertex.Pop();
        closed.insert(current_vertex);

        for(int i=0; i < this->vertices.Size(); i++){
            if(this->matrix[current_vertex][i] != 0 &&
               closed.find(i) == closed.end()){
                travel_vertex.Push(i);
            }
        }
    }

    if(closed.size() == (size_t)this->vertices.Size()) return true;

    return false;
}


bool MGraph::IsTree(){
    Stack<int> travel_vertex;
    std::set<int> closed;
    std::set<int>::iterator it;
    int current_vertex = 0;
    travel_vertex.Push(0);

    while(travel_vertex.Size() != 0){
        current_vertex = travel_vertex.Head();
        travel_vertex.Pop();
        closed.insert(current_vertex);

        for(int i=0; i < this->vertices.Size(); i++){
            if(this->matrix[current_vertex][i] != 0 &&
               closed.find(i) == closed.end()){

                for(it=closed.begin(); it != closed.end(); ++it){
                    if(this->matrix[i][*it] != 0) return false;
                }
                travel_vertex.Push(i);
            }
        }
    }

    return true;
}

bool MGraph::DeleteEdge(MGraph::Edge edge, bool undirected){
    if(edge.head >= this->vertices.Size() || edge.tail >= this->vertices.Size())
        return false;

    this->matrix[edge.head][edge.tail] = 0;
    if(undirected){
        this->matrix[edge.tail][edge.head] = 0;
    }
    return true;
}

bool MGraph::DeleteEdge(Vector<MGraph::Edge> edge, bool undirected){
    if(edge.Size() == 0) return false;

    for(int i = 0; i < edge.Size(); i++){
        this->DeleteEdge(edge[i], undirected);
    }

    return true;
}

int MGraph::HasVertex(int vertex){
    return this->vertices.FindOnce(vertex);
}

bool MGraph::DeleteVertex(int vertex){
    int index = this->HasVertex(vertex);

    if(index == -1) return false;

    if(!this->DeleteColumn(index) || !this->DeleteColumn(index))
        return false;

    this->vertices.RemoveOnce(vertex);
    return true;
}

bool MGraph::DeleteVertex(Vector<int> vertex){
    Vector<int> index;
    int t = 0;

    for(int i = 0; i < vertex.Size(); i++){
        t = this->HasVertex(vertex[i]);

        if(t != -1) index.Insert(t);
    }

    if(!this->DeleteColumn(index) || !this->DeleteColumn(index))
        return false;

    for(int i = 0; i < vertex.Size(); i++){
        this->vertices.RemoveOnce(vertex[i]);
    }

    return true;
}

int MGraph::GetNumVertices(){
    return this->vertices.Size();
}

MGraph& MGraph::operator=(MGraph& x){
    this->SetStorage(x);

    this->vertices = x.vertices;

    return *this;
}

int MGraph::FindNoIncomingVertex(){
    int i = 0;
    int num_ver = this->GetNumVertices();
    bool is_noincoming = true;

    for(i = 0; i < num_ver; i++){
        for(int j = 0; j < num_ver; j++){
            if((*this)[j][i] != 0) {
                is_noincoming = false;
                break;
            }
        }

        if(is_noincoming == true) return this->vertices[i];
    }

    return -1;
}

MGraph::Edge MGraph::FindSmallestEdge(){
    double min_v = (*this)[0][0];
    Edge ret_e(0, 0);
    int num_ver = this->GetNumVertices();

    for(int i = 0; i < num_ver; i++){
        for(int j = 0; j < num_ver; j++){
            if((*this)[i][j] < min_v){
                min_v = (*this)[i][j];
                ret_e.head = i;
                ret_e.tail = j;
                ret_e.weight = min_v;
            }
        }
    }

    return ret_e;
}

MGraph::Edge MGraph::FindBiggestEdge(){
    double max_v = std::numeric_limits<double>::min();
    Edge ret_e(0, 0);
    int num_ver = this->GetNumVertices();

    for(int i = 0; i < num_ver; i++){
        for(int j = 0; j < num_ver; j++){
            if((*this)[i][j] > max_v && (*this)[i][j] != std::numeric_limits<double>::max()){
                max_v = (*this)[i][j];
                ret_e.head = i;
                ret_e.tail = j;
                ret_e.weight = max_v;
            }
        }
    }

    return ret_e;
}

bool MGraph::AddEdge(MGraph::Edge edge){
    if(!this->AddVertex(edge.head)){
        return false;
    }

    if(!this->AddVertex(edge.tail)){
        return false;
    }

    int index_head = this->HasVertex(edge.head);
    int index_tail = this->HasVertex(edge.tail);

    (*this)[index_head][index_tail] = edge.weight;

    if(this->undirected){
        (*this)[index_tail][index_head] = edge.weight;
    }

    return true;
}

bool MGraph::AddVertex(int vertex){
    Vector<double> append_c(std::numeric_limits<double>::max(), this->ncol);
    Vector<double> append_r(std::numeric_limits<double>::max(), this->ncol+1);

    if(!this->HasVertex(vertex)){
        if(!this->BindColumns(&append_c, 1)){
            return false;
        }

        if(!this->BindRows(&append_r, 1)){
            this->DeleteColumn(this->ncol - 1);
            return false;
        }

        this->vertices.Insert(vertex);
    }

    return true;
}

double MGraph::GetEdgeW(int head, int tail){
    int i_h = this->HasVertex(head);
    int i_t = this->HasVertex(tail);

    if(i_h == -1 || i_t == -1){
        return std::numeric_limits<double>::max();
    }

    return (*this)[i_h][i_t];
}

void MGraph::FindAdjacencyVertices(int vertex, Vector<int>& ret){
    int index_v = this->HasVertex(vertex);
    if(index_v == -1) return;

    for(int i = 0; i < this->GetNumVertices(); i++){
        if((*this)[index_v][i] == std::numeric_limits<double>::max()){
            continue;
        }

        ret.Insert(this->vertices[i]);
    }
}
