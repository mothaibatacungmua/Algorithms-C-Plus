/*
 * algorithms.hpp
 *
 *  Created on: May 3, 2016
 *      Author: asm
 */

#ifndef ALGORITHMS_HPP_
#define ALGORITHMS_HPP_

#include <stdio.h>
#include "data-structures.hpp"

using namespace std;
using namespace DataStructures;

namespace Algorithms{
    namespace Hash{
        unsigned int JenkinsHash(char* key, size_t len);
    }

    namespace GraphF{
        /* Topological ordering */
        bool TopologicalOrdering(Graph& DAG, Vector<int>& result);

        /* Dijkstra */
        bool Dijkstra(Graph& DAG, int start, int goal, Vector<int>& path);

        /**
         * Minimum spanning tree algorithms
         */
        bool Prim(Graph & graph, Graph& result);

        bool Kruskal(Graph& graph, Graph& result);

        bool ReverseDelete(Graph& graph, Graph& result);
    }

}



#endif /* ALGORITHMS_HPP_ */
