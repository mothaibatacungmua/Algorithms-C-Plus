/*
 * misc.cpp
 *
 *  Created on: Apr 25, 2016
 *      Author: asm
 */
#include "../../headers/misc.hpp"
#include <stdio.h>

namespace Utils{
    template <typename T>
    void Swap(T& A, T& B){
        T C = A;

        A = B;
        B = C;

        return;
    }
}

template void Utils::Swap<int>(int& A, int& B);
template void Utils::Swap<double>(double& A, double& B);
