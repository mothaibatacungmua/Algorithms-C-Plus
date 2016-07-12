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
            SGraph::MinEdge wv;
            ExtendedPriorityQueue<SGraph::MinEdge> queue;
            Hashmap<int, SGraph::Edge> store_min_edges;
            edges.clear();

            wv.v.vertex = start;
            wv.v.weight = 0;
            wv.e.head = start;
            wv.e.tail = -1;

            int index = queue.Push(wv);

            while(queue.Size() != 0){
                wv = queue.Head();
                queue.Pop();

                vertices.insert(wv.v.vertex);
                store_min_edges.Set(wv.v.vertex, wv.e);
                edges.insert(wv.e);

                if(wv.v.vertex == goal){
                    break;
                }

                graph.FindAdjacencyVertices(wv.v.vertex, adjac_v);

                for(int i = 0; i < adjac_v.Size(); i++){
                    if(vertices.find(adjac_v[i]) == vertices.end()){
                        //has key then update
                        SGraph::MinEdge tv;
                        index = queue.GetIndexByKey(adjac_v[i]);

                        if(index != -1){
                            double min_v = MIN(queue[index].v.weight, wv.v.weight + graph.GetEdgeW(wv.v.vertex,adjac_v[i]));
                            if(min_v < queue[index].v.weight){
                                tv = queue[index];
                                tv.v.weight = min_v;
                                tv.e.tail = wv.v.vertex;
                                tv.e.head = adjac_v[i];
                                queue.ChangeValue(tv, index);
                            }

                        }else{ //if not then add new
                            tv.v.vertex = adjac_v[i];
                            tv.v.weight = wv.v.weight + graph.GetEdgeW(wv.v.vertex,adjac_v[i]);
                            tv.e.tail = wv.v.vertex;
                            tv.e.head = adjac_v[i];
                            queue.Push(tv);
                        }
                    }
                }
            }


            //std::cout<<"\n";
            //for(it=edges.begin(); it!=edges.end();++it){
            //    std::cout<<"("<<(*it).tail<<","<<(*it).head<<") ";
            //}

            int start_v = goal;
            SGraph::Edge travel;

            while(start_v != -1){
                path.Insert(start_v);
                store_min_edges.Get(start_v, travel);
                start_v = travel.tail;
            }

            return true;
        }
    }
}


