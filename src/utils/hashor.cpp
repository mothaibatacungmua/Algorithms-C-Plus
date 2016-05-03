/*
 * hash-algor.cpp
 *
 *  Created on: May 3, 2016
 *      Author: asm
 */
#include "../../headers/algorithms.hpp"
#include "../../headers/hashor.hpp"

namespace Utils{
    struct JenkinsHash{
        int operator() (char* key, size_t length){
            return Algorithms::Hash::JenkinsHash(key, length);
        }
    };
}


