/*
 * Prim.cpp
 *
 *  Created on: May 16, 2016
 *      Author: asm
 */

#include <stdio.h>
#include "../../../headers/data-structures.hpp"
#include "../../../headers/algorithms.hpp"

using namespace std;
using namespace DataStructures;

namespace Algorithms{
    namespace GraphF{
        bool Prim(SGraph& graph, SGraph& result){
            /**
             * TODO
             */

            SGraph t_g = graph;
            int num_v = graph.GetNumVertices();

            result.Clear();
            if(!graph.IsConnected()){
                return false;
            }

            Vector<SGraph::Edge> unroll_edges;
            graph.UnrollEdges(unroll_edges);
            Algorithms::Sorting::HeapSort(unroll_edges, unroll_edges);

            PriorityQueue<SGraph::Edge> adjacencies;
            Vector<int> v_adjac;

            SGraph::Edge e = unroll_edges[0];
            SGraph::Edge t(0,0);

            t_g.DeleteEdge(e);
            result.AddEdge(e);

            while(result.GetNumVertices() != num_v){
                t_g.FindAdjacencyVertices(e.head, v_adjac);

                for(int i = 0; i < v_adjac.Size(); i++){
                    if(!result.HasVertex(v_adjac[i])) continue;
                    t.head = e.head;
                    t.tail = v_adjac[i];
                    t.weight = t_g.GetEdgeW(t.head, t.tail);
                    adjacencies.Push(t);
                }

                t_g.FindAdjacencyVertices(e.tail, v_adjac);
                for(int i = 0; i < v_adjac.Size(); i++){
                    if(!result.HasVertex(v_adjac[i])) continue;
                    t.head = e.tail;
                    t.tail = v_adjac[i];
                    t.weight = t_g.GetEdgeW(t.head, t.tail);
                    adjacencies.Push(t);
                }

                e = adjacencies.Head();
                adjacencies.Pop();
            }

            return true;
        }
    }
}



