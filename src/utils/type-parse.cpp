/*
 * type-parse.cpp
 *
 *  Created on: Apr 17, 2016
 *      Author: asm
 */
#include "../../headers/type-parse.hpp"
#include <stdio.h>

using namespace std;

namespace Utils{
    template<typename T>
    string ToString(T a){
        char buffer[16];
        if(COMPARE_TYPE(T,"int")){
            sprintf ( buffer, "%d", a );
            return buffer;
        }

        if(COMPARE_TYPE(T,"double")){
            sprintf( buffer, "%0.2f", a);
            return buffer;
        }

        if(COMPARE_TYPE(T,"char*")){
            return a;
        }

        if(COMPARE_TYPE(T,"string")){
            return a;
        }
        return "NOT IMPLEMENTED YET";
    }
}

template string Utils::ToString<int>(int);
template string Utils::ToString<double>(double);

REGISTER_PARSE_TYPE(int);
REGISTER_PARSE_TYPE(double);
REGISTER_PARSE_TYPE(char*);
REGISTER_PARSE_TYPE(string);
