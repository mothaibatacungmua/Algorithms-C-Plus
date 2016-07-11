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

SGraph::SGraph(SetEdge& edges, SetVertex& vertices, bool undirected){
    this->undirected = undirected;
    this->edges = edges;
    this->vertices = vertices;

    SetEdge::iterator it;

    for(it = this->edges.begin(); it != this->edges.end(); ++it){
        this->AddVertex((*it).head);
        this->AddVertex((*it).tail);
    }
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
    std::set<int> closed;
    Stack<int> travel_vertex;
    SetVertex::iterator it = this->vertices.begin();

    if(it == this->vertices.end()){
        return false;
    }

    int current_vertex = *it;
    Vector<int> adjac_vertices;
    travel_vertex.Push(current_vertex);

    int count = 0;

    while(travel_vertex.Size() != 0){
        current_vertex = travel_vertex.Head();
        travel_vertex.Pop();

        count += 1;

        closed.insert(current_vertex);

        this->FindAdjacencyVertices(current_vertex, adjac_vertices);
        for(int i = 0; i < adjac_vertices.Size(); i++){
            if(closed.find(adjac_vertices[i]) == closed.end()){
                travel_vertex.Push(adjac_vertices[i]);
            }
        }

    }

    if(closed.size() != this->vertices.size()) return false;

    return true;
}

bool SGraph::IsTree(){
    Stack<int> travel_vertex;
    std::set<int> closed;
    std::set<int>::iterator c_it;
    SetVertex::iterator it = this->vertices.begin();
    int current_vertex = *it;
    travel_vertex.Push(current_vertex);
    Vector<int> adjac_vertices;

    while(travel_vertex.Size() != 0){
        current_vertex = travel_vertex.Head();
        travel_vertex.Pop();
        closed.insert(current_vertex);

        this->FindAdjacencyVertices(current_vertex, adjac_vertices);

        for(int i = 0; i < adjac_vertices.Size(); i++){
            for(c_it = closed.begin(); c_it != closed.end(); ++c_it){
                if(this->GetEdgeW(adjac_vertices[i], *c_it) != std::numeric_limits<double>::max()){
                    return false;
                }
            }
        }
    }

    return true;
}
bool SGraph::DeleteEdge(int head, int tail){
    Edge e(head, tail);

    return this->DeleteEdge(e);
}

bool SGraph::DeleteEdge(Edge edge){
    SetEdge::iterator it = this->edges.find(edge);

    if(it == this->edges.end()){
        return false;
    }

    this->edges.erase(it);

    return true;
}

void SGraph::DeleteEdge(Vector<Edge> edges){
    SetEdge::iterator it;

    for(int i = 0; i < edges.Size(); i++){
        this->DeleteEdge(edges[i]);
    }

    return;
}

bool SGraph::DeleteVertex(int vertex){
    SetVertex::iterator v_it;
    Vector<int> adjac_vertices;

    this->FindAdjacencyVertices(vertex, adjac_vertices);

    Edge e(0,0);
    e.head = vertex;

    for(int i = 0; i < adjac_vertices.Size(); i++){
        e.tail = adjac_vertices[i];
        this->DeleteEdge(e);
    }

    v_it = this->vertices.find(vertex);
    this->vertices.erase(v_it);

    return true;
}

void SGraph::DeleteVertex(Vector<int> vertices){
    for(int i = 0; i < vertices.Size(); i++){
        this->DeleteVertex(vertices[i]);
    }

    return;
}

bool SGraph::AddEdge(Edge edge){
    this->AddVertex(edge.head);
    this->AddVertex(edge.tail);
    this->AddEdge(edge);

    return true;
}

bool SGraph::AddVertex(int vertex){

    this->vertices.insert(vertex);

    return true;
}

void SGraph::FindAdjacencyVertices(int vertex, Vector<int>& ret){
    ret.Resize(0);
    SetVertex::iterator it;

    for(it = this->vertices.begin(); it != this->vertices.end(); ++it){
        if(this->GetEdgeW(vertex, *it) != std::numeric_limits<double>::max()){
            ret.Insert(*it);
        }
    }

    return;
}

void SGraph::ConvertToMGraph(MGraph& x){
    return;
}

int SGraph::FindNoIncomingVertex(){
    SetVertex::iterator it_0;
    SetVertex::iterator it_1;
    bool is_noincoming = true;

    for(it_0 = this->vertices.begin(); it_0 != this->vertices.end(); ++it_0){
        for(it_1 = this->vertices.begin(); it_1 != this->vertices.end(); ++it_1){
            if(this->GetEdgeW(*it_1, *it_0) != std::numeric_limits<double>::max()){
                is_noincoming = false;
            }
        }

        if(is_noincoming) return *it_0;
    }

    return -1;
}

std::string SGraph::ToString(){
    std::string ret;
    SetVertex::iterator vit;
    SetEdge::iterator eit;

    ret.append("[vertices]\n");
    for(vit = this->vertices.begin(); vit != this->vertices.end(); ++vit){
        ret.append(Utils::ToString(*vit));
        ret.append(" ");
    }
    ret.append("\n");

    ret.append("[edges]\n");
    for(eit = this->edges.begin(); eit != this->edges.end(); ++eit){
        int head = (*eit).head;
        int tail = (*eit).tail;
        double weight = (*eit).weight;
        ret.append("(");
        ret.append(Utils::ToString(head));
        ret.append(",");
        ret.append(Utils::ToString(tail));
        ret.append(":");
        ret.append(Utils::ToString(weight));
        ret.append(") ");
    }
    ret.append("\n");

    return ret;
}

int SGraph::GetNumVertices(){
    return this->vertices.size();
}

int SGraph::GetNumEdges(){
    return this->edges.size();
}

void SGraph::UnrollEdges(Vector<Edge>& ret){
    SetEdge::iterator it;
    ret.Resize(0);

    for(it = this->edges.begin(); it != this->edges.end(); ++it){
        ret.Insert(*it);
    }

    return ;
}

void SGraph::Clear(){
    this->edges.clear();
    this->vertices.clear();
}

void SGraph::GetEdges(SGraph::SetEdge& ret){
    ret = this->edges;
}

void SGraph::GetVertices(SGraph::SetVertex& ret){
    ret = this->vertices;
}

SGraph& SGraph::operator= (SGraph& x){
    this->Clear();
    x.GetEdges(this->edges);
    x.GetVertices(this->vertices);
    this->undirected = x.undirected;
    return *this;
}

bool SGraph::HasVertex(int vertex){
    return (this->vertices.find(vertex) != this->vertices.end());
}

bool SGraph::HasEdge(SGraph::Edge edge){
    return (this->edges.find(edge) != this->edges.end());
}
