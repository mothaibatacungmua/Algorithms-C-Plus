/*
 * reverse-delete.cpp
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
        bool ReverseDelete(SGraph& graph, SGraph& result){
            result = graph;
            int num_v = graph.GetNumVertices();

            if(!graph.IsConnected()){
                return false;
            }

            Vector<int>adjac_v;
            Vector<SGraph::Edge> unroll_edges;
            graph.UnrollEdges(unroll_edges);
            Algorithms::Sorting::HeapSort(unroll_edges, unroll_edges);

            int l = unroll_edges.Size();
            result.DeleteEdge(unroll_edges[l-1]);

            while(result.GetNumEdges() > (num_v - 1)){
                int head_adjac_count = 1;
                int tail_adjac_count = 1;

                while(head_adjac_count == 1 && tail_adjac_count == 1){
                    l -= 1;
                    result.FindAdjacencyVertices(unroll_edges[l-1].head, adjac_v);
                    head_adjac_count = adjac_v.Size();
                    result.FindAdjacencyVertices(unroll_edges[l-1].tail, adjac_v);
                    tail_adjac_count = adjac_v.Size();
                }

                result.DeleteEdge(unroll_edges[l-1]);

            }

            return true;
        }
    }
}


