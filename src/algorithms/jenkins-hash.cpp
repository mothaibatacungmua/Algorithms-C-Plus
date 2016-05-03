/*
 * jenkins-hash.cpp
 *
 *  Created on: May 2, 2016
 *      Author: asm
 */

#include <stdio.h>
#include "../../headers/algorithms.hpp"

namespace Algorithms{
    namespace Hash{
        unsigned int JenkinsHash(char* key, size_t length){
            unsigned int hash, i;
            for(hash = i = 0; i < length; ++i){
                hash += key[i];
                hash += (hash << 10);
                hash ^= (hash >> 6);
            }

            hash += (hash << 3);
            hash ^= (hash >> 11);
            hash += (hash << 15);

            return hash;
        }
    }
}

