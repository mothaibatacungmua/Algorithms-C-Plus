/*
 * sgraph.cpp
 *
 *  Created on: Jun 28, 2016
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

SGraph::SGraph(bool undirected, SetEdge& edges, SetVertex& vertices){
    this->undirected = undirected;
    this->edges = edges;
    this->vertices = vertices;
}

SGraph::SGraph(bool undirected){
    this->undirected = undirected;
}

SGraph::~SGraph(){

}

double SGraph::GetEdgeW(int head_v, int tail_v){
    SetEdge::iterator it;
    Edge e(head_v, tail_v);

    it = this->edges.find(e);
    if(it != this->edges.end()){
        return (*it).weight;
    }

    if(this->undirected){
        e.head = tail_v;
        e.tail = head_v;
        it = this->edges.find(e);
        if(it != this->edges.end()){
            return (*it).weight;
        }
    }

    return std::numeric_limits<double>::max();
}

bool SGraph::IsConnected(){
    return true;
}

bool SGraph::IsTree(){
    return true;
}

bool SGraph::DeleteEdge(Edge edge){
    return true;
}

bool SGraph::DeleteEdge(Vector<Edge> edge){
    return true;
}

bool SGraph::DeleteVertex(int vertex){
    return true;
}

bool SGraph::DeleteVertex(Vector<int> vertices){
    return true;
}

bool SGraph::AddEdge(Edge edge){
    return true;
}

bool SGraph::AddVertex(int vertex){
    return true;
}

void SGraph::FindAdjacencyVertices(int vertex, Vector<int>& ret){
    return;
}

void SGraph::ConvertToMGraph(MGraph& x){
    return;
}

int SGraph::FindNoIncomingVertex(){
    return 0;
}

string SGraph::ToString(){
    return "NOT YET IMPLEMENTED";
}

