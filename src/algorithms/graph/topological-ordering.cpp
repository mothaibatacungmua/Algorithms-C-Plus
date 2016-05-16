#include "../../../headers/data-structures.hpp"
#include "../../../headers/algorithms.hpp"

using namespace DataStructures;

int FindNoIncomingVertex(Graph DAG){
    int i = 0;

    for(i = 0; i < DAG.nver; i++){
        for(int j = 0; j < DAG.nver; j++){
            if(Graph[j][i] != 0) break;
        }
    }

    if(i == DAG.nver) return -1;

    return i;
}

namespace Algorithms{
    namespace Graph{
        /* Topological ordering */
        bool TopologicalOrdering(Graph& DAG){
            return true;
        }
    }
}
