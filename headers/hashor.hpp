/*
 * hashor.hpp
 *
 *  Created on: May 3, 2016
 *      Author: asm
 */

#include <stdio.h>

namespace Utils{
    struct JenkinsHash{
        int operator() (char*, size_t);
    };
}


