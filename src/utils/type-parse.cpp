/*
 * type-parse.cpp
 *
 *  Created on: Apr 17, 2016
 *      Author: asm
 */
#include "../../headers/type-parse.hpp"

namespace Utils{
    template<typename T>
    std::string ToString(T a){
        if(COMPARE_TYPE(T,"int")){
            return "YES";
        }

        return "NOT IMPLEMENTED YET";
    }
}

template std::string Utils::ToString<int>(int);
template std::string Utils::ToString<double>(double);

REGISTER_PARSE_TYPE(int);
REGISTER_PARSE_TYPE(double);
