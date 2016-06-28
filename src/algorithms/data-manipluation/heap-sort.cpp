/*
 * heap-sort.cpp
 *
 *  Created on: Jun 28, 2016
 *      Author: asm
 */

#include <stdio.h>
#include "../../../headers/algorithms.hpp"

using namespace DataStructures;

namespace Algorithms{
    namespace Sorting{
        template <typename V>
        void HeapSort(Vector<V>& input, Vector<V>& output){
            PriorityQueue<V> queue;
            output.Resize(0);

            for(int i = 0; i < input.Size(); i++){
                queue.Push(input[i]);
            }

            for(int i = 0; i < input.Size(); i++){
                output.Insert(queue.Head());
                output.Pop();
            }
        }
    }
}
