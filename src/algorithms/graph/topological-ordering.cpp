#include "../../../headers/data-structures.hpp"
#include "../../../headers/algorithms.hpp"

using namespace DataStructures;



namespace Algorithms{
    namespace GraphF{
        /* Topological ordering */
        bool TopologicalOrdering(MGraph& DAG, Vector<int>& result){
            MGraph A = DAG;
            int num_ver = A.GetNumVertices();
            result.Resize(num_ver);

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
