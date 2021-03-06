/*
 * Kruskal.cpp
 *
 *  Created on: May 16, 2016
 *      Author: asm
 */

#include <stdio.h>
#include <iostream>
#include "../../../headers/data-structures.hpp"
#include "../../../headers/algorithms.hpp"

using namespace std;
using namespace DataStructures;

namespace Algorithms{
    namespace GraphF{
        bool Kruskal(SGraph& graph, SGraph& result){
            SGraph t_g = graph;
            SGraph::SetVertex::iterator it;
            SGraph::SetVertex vertices;
            graph.GetVertices(vertices);

            int num_v = graph.GetNumVertices();
            int i = 0;

            result.Clear();
            if(!graph.IsConnected()){
                return false;
            }

            Vector<SGraph::Edge> unroll_edges;
            graph.UnrollEdges(unroll_edges);

            Algorithms::Sorting::HeapSort(unroll_edges, unroll_edges);

            Hashmap<int, UnionFind> map;
            UnionFind* u = NULL;
            Vector<unsigned int>save_pointer;

            for(it = vertices.begin(); it != vertices.end(); ++it){
                u = new UnionFind(*it);
                save_pointer.Insert((unsigned int)u);
                map.Set(*it, *u);
            }

            i = 0;
            SGraph::Edge e = unroll_edges[i];
            UnionFind* u_head = NULL;
            UnionFind* u_tail = NULL;

            while(result.GetNumEdges() < (num_v - 1)){
                result.AddEdge(e);
                while(u_head == u_tail){
                    i += 1;
                    e = unroll_edges[i];
                    u_head = (map[e.head]).Find();
                    u_tail = (map[e.tail]).Find();
                }

                u_head->Union(*u_tail);
                u_head = u_tail = NULL;
            }

            for(i = 0; i < save_pointer.Size(); i++){
                delete (UnionFind*)save_pointer[i];
            }

            return true;
        }

    }
}




