/*
 * comparator.hpp
 *
 *  Created on: May 3, 2016
 *      Author: asm
 */

#ifndef COMPARATOR_HPP_
#define COMPARATOR_HPP_

namespace Utils{
    template <typename T>
    struct Comparator{
        int operator()(const T&, const T&);
    };
}

#endif /* COMPARATOR_HPP_ */
