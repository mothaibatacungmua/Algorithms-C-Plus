#include "../../../headers/data-structures.hpp"
#include "../../../headers/algorithms.hpp"

using namespace DataStructures;


namespace Algorithms{
    namespace GraphF{
        /* Topological ordering */
        bool TopologicalOrdering(SGraph& DAG, Vector<int>& result){
            SGraph A = DAG;
            result.Clear();

            while(A.GetNumVertices() != 0){
                int i = A.FindNoIncomingVertex();

                if(i == -1){
                    return false;
                }

                result.Insert(i);

                A.DeleteVertex(i);
            }

            return true;
        }
    }
}
