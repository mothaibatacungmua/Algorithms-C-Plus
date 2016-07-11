/*
 * dijkstra.cpp
 *
 *  Created on: May 16, 2016
 *      Author: asm
 */

#include <stdio.h>
#include "../../../headers/data-structures.hpp"
#include "../../../headers/algorithms.hpp"
#include "../../../headers/misc.hpp"

using namespace std;
using namespace DataStructures;

namespace Algorithms{
    namespace GraphF{
        bool Dijkstra(SGraph& graph, int start, int goal, Vector<int>& path){
            SGraph::SetEdge edges;
            SGraph::SetEdge::iterator it;
            SGraph::SetVertex vertices;
            path.Clear();
            graph.GetEdges(edges);

            //check negative edge, quit if exist one
            for(it = edges.begin(); it != edges.end(); ++it){
                if((*it).weight < 0){
                    return false;
                }
            }

            Vector<int> adjac_v;
            SGraph::WeightedVertex wv;
            PriorityQueue<SGraph::WeightedVertex> queue;
            Hashmap<int, int>map_key;

            wv.vertex = start;
            wv.weight = 0;
            int index = queue.Push(wv);
            map_key.Set(start, index);

            while(queue.Size() != 0){
                wv = queue.Head();
                queue.Pop();

                map_key.Set(wv.vertex, -1);
                vertices.insert(wv.vertex);
                path.Insert(wv.vertex);

                if(wv.vertex == goal){
                    return true;
                }

                graph.FindAdjacencyVertices(wv.vertex, adjac_v);

                for(int i = 0; i < adjac_v.Size(); i++){
                    if(vertices.find(adjac_v[i]) == vertices.end()){
                        //has key then update
                        SGraph::WeightedVertex tv;
                        if(map_key.Get(adjac_v[i], index)){
                            double min_v = MIN(queue[i].weight, wv.weight + graph.GetEdgeW(wv.vertex,adjac_v[i]));
                            tv.vertex = queue[index].vertex;
                            tv.weight = min_v;
                            index = queue.ChangeValue(tv,index);
                            map_key.Set(adjac_v[i], index);
                        }else{
                            tv.vertex = adjac_v[i];
                            tv.weight = wv.weight + graph.GetEdgeW(wv.vertex,adjac_v[i]);
                            index = queue.Push(tv);
                            map_key.Set(adjac_v[i], index);
                        }
                    }
                }
            }

            return false;
        }
    }
}


