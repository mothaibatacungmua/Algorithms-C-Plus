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

namespace Algorithms{
    namespace Hash{
        unsigned int JenkinsHash(char* key, size_t len);
    }

    namespace Graph{
        /* Topological ordering */
        bool TopologicalOrdering(Graph& DAG);

        /* Dijkstra */
        vector<int>& Dijkstra(Graph& DAG, int start, int goal);

        /**
         * Minimum spanning tree algorithms
         */
        vector<int>& Prim(Graph& graph);

        vector<int>& Kruskal(Graph& graph);

        vector<int>& ReverseDelete(Graph& graph);
    }

}



#endif /* ALGORITHMS_HPP_ */
