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
    int DoCompare(T A, T B, int(*compar)(const T, const T)){
        if(compar != NULL) return compar(A, B);

        if(A > B) return 1;
        if(A == B) return 0;

        return -1;
    }

    template <typename T>
    void Swap(T& A, T& B){
        T C = A;

        A = B;
        B = C;

        return;
    }
}



template int Utils::DoCompare<int>(int A, int B, int(*compar)(const int, const int));
template int Utils::DoCompare<double>(double A, double B, int(*compar)(const double, const double));

template void Utils::Swap<int>(int& A, int& B);
template void Utils::Swap<double>(double& A, double& B);
