/*
 * dijkstra.cpp
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
        bool Dijkstra(SGraph& graph, int start, int goal, Vector<int>& path){
            /**
             * TODO
             */

            SGraph::SetEdge edges;
            SGraph::SetEdge::iterator it;
            graph.GetEdges(edges);

            //check negative edge, quit if exist one
            for(it = edges.begin(); it != edges.end(); ++it){
                if((*it).weight < 0){
                    return false;
                }
            }

            Vector<int> adjac_v;
            PriorityQueue<SGraph::Path> queue;

            SGraph::Path travel_path;
            travel_path.total_weight = 0.0;
            travel_path.vertices.Insert(start);

            queue.Push(travel_path);

            while(queue.Size() != 0){
                travel_path = queue.Head();
                queue.Pop();

                if(travel_path.vertices[travel_path.vertices.Size() - 1] == goal){
                    path = travel_path;
                    return true;
                }

                graph.FindAdjacencyVertices(travel_path.vertices[travel_path.vertices.Size() - 1], adjac_v);
                for(int i = 0; i < adjac_v.Size(); i++){
                    SGraph::Path new_path = travel_path;
                    new_path.vertices.Insert(adjac_v[i]);
                    new_path.total_weight += graph.GetEdgeW(travel_path.vertices[travel_path.vertices.Size() - 1], adjac_v[i]);
                    queue.Push(new_path)
                }
            }

            return false;
        }
    }
}


