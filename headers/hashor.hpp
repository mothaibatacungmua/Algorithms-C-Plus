/*
 * hashor.hpp
 *
 *  Created on: May 3, 2016
 *      Author: asm
 */

#include <stdio.h>

namespace Utils{
    template <typename T, typename R>
    R DoHash(T obj, R (*hash_func)(char*, size_t));

    template <typename T>
    struct JenkinsHash{
        int operator() (T obj);
    };
}


