/*
 * comparator.cpp
 *
 *  Created on: May 3, 2016
 *      Author: asm
 */

#include "../../headers/comparator.hpp"

namespace Utils{
    template <typename T>
    struct Comparator{
        int operator()(const T& A, const T& B){
            if(A > B) return 1;
            if(A == B) return 0;

            return -1;
        }
    };
}


