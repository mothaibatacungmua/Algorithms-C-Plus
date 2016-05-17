/*
 * hashor_.hpp
 *
 *  Created on: May 17, 2016
 *      Author: asm
 */

#ifndef HASHOR_HPP_
#define HASHOR_HPP_

#include <stdio.h>

namespace Utils{
    template <typename T>
    struct JenkinsHash{
        unsigned int operator() (T obj);
    };
}



#endif /* HASHOR_HPP_ */
