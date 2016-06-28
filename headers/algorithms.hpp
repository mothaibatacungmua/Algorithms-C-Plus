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

    namespace Sorting{
        template <typename V>
        void HeapSort(Vector<V>& input, Vector<V>& output);
    }

    namespace GraphF{
        /* Topological ordering */
        bool TopologicalOrdering(SGraph& DAG, Vector<int>& result);

        /* Dijkstra */
        bool Dijkstra(SGraph& DAG, int start, int goal, Vector<int>& path);

        /**
         * Minimum spanning tree algorithms
         */
        bool Prim(SGraph & graph, SGraph& result);

        bool Kruskal(SGraph& graph, SGraph& result);

        bool ReverseDelete(SGraph& graph, SGraph& result);
    }

}



#endif /* ALGORITHMS_HPP_ */
