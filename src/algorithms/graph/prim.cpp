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
        bool Prim(Graph& graph, Graph& result){
            /**
             * TODO
             */

            if(result.GetNumVertices() != graph.GetNumVertices()){
                return false;
            }

            PriorityQueue<Graph::Edge> adjacencies;

            return true;
        }
    }
}



