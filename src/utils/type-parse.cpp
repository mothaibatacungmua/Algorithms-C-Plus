/*
 * type-parse.cpp
 *
 *  Created on: Apr 17, 2016
 *      Author: asm
 */
#include "../../headers/type-parse.hpp"
#include <stdio.h>

namespace Utils{
    template<typename T>
    std::string ToString(T a){
        if(COMPARE_TYPE(T,"int")){
            char buffer[16];
            sprintf ( buffer, "%d", a );
            return buffer;
        }

        return "NOT IMPLEMENTED YET";
    }
}

template std::string Utils::ToString<int>(int);
template std::string Utils::ToString<double>(double);

REGISTER_PARSE_TYPE(int);
REGISTER_PARSE_TYPE(double);
