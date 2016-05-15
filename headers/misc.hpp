/*
 * misc.hpp
 *
 *  Created on: Apr 25, 2016
 *      Author: asm
 */

#ifndef MISC_HPP_
#define MISC_HPP_

#define MAX(a, b) ((a >= b)? a: b)
#define MIN(a, b) ((a <= b)? a: b)
namespace Utils{
    template <typename T>
    void Swap(T& A, T& B);
}



#endif /* MISC_HPP_ */
