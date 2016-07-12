/*
 * comparator.cpp
 *
 *  Created on: May 3, 2016
 *      Author: asm
 */

#include "../../headers/comparator.hpp"
#include "../../headers/data-structures.hpp"

namespace Utils{
    template <typename T>
    int Comparator<T>::operator()(T& A, T& B){
        if(A > B) return 1;
        if(A == B) return 0;

        return -1;
    }
}


template struct Utils::Comparator<int>;
template struct Utils::Comparator<double>;
template struct Utils::Comparator<DataStructures::SGraph::Path>;
template struct Utils::Comparator<DataStructures::SGraph::WeightedVertex>;
template struct Utils::Comparator<DataStructures::SGraph::Edge>;
template struct Utils::Comparator<DataStructures::SGraph::MinEdge>;
