/*
 * hashor.hpp
 *
 *  Created on: May 3, 2016
 *      Author: asm
 */

#include <stdio.h>

namespace Utils{
    template <typename T>
    struct JenkinsHash{
        unsigned int operator() (T obj);
    };
}


