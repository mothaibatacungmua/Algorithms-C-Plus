/*
 * type-parse.cpp
 *
 *  Created on: Apr 17, 2016
 *      Author: asm
 */
#include "../../headers/type-parse.hpp"
#include "../../headers/data-structures.hpp"
#include <stdio.h>

using namespace DataStructures;
using namespace std;

REGISTER_PARSE_TYPE(unsigned int);
REGISTER_PARSE_TYPE(int);
REGISTER_PARSE_TYPE(double);
REGISTER_PARSE_TYPE(char*);
REGISTER_PARSE_TYPE(string);
REGISTER_PARSE_TYPE(char);
REGISTER_PARSE_TYPE(MGraph::Edge);
REGISTER_PARSE_TYPE(SGraph::Path);
REGISTER_PARSE_TYPE(SGraph::WeightedVertex);
REGISTER_PARSE_TYPE(SGraph::MinEdge);

namespace Utils{
    template<typename T>
    string ToString(T a){
        char buffer[16];
        if(COMPARE_TYPE(T,"int") || COMPARE_TYPE(T,"unsigned int")){
            int cast_int = *(reinterpret_cast<int*>(&a));
            sprintf ( buffer, "%d", cast_int );
            return buffer;
        }

        if(COMPARE_TYPE(T,"double")){
            double cast_double = *(reinterpret_cast<double*>(&a));
            sprintf( buffer, "%0.2f", cast_double);
            return buffer;
        }

        if(COMPARE_TYPE(T,"char")){
            char cast_char = *(reinterpret_cast<char*>(&a));
            sprintf ( buffer, "%c", cast_char);
            return buffer;
        }

        if(COMPARE_TYPE(T,"char*")){
            return *(reinterpret_cast<char**>(&a));
        }

        if(COMPARE_TYPE(T,"string")){
            return *(reinterpret_cast<string*>(&a));
        }
        return "NOT IMPLEMENTED YET";
    }

    template <typename T>
    unsigned int DoHash(T obj, unsigned int (*hash_func)(char*, size_t)){
        if(COMPARE_TYPE(T,"int") || COMPARE_TYPE(T,"unsigned int")){
            return hash_func(reinterpret_cast<char*>(&obj), sizeof(int));
        }

        if(COMPARE_TYPE(T,"double")){
            return hash_func(reinterpret_cast<char*>(&obj), sizeof(double));
        }

        if(COMPARE_TYPE(T,"char")){
            return hash_func(reinterpret_cast<char*>(&obj), sizeof(char));
        }

        if(COMPARE_TYPE(T,"string")){
            string cast_string = *(reinterpret_cast<string*>(&obj));
            return hash_func((char*)cast_string.c_str(), cast_string.size());
        }

        return -1;
    }
}

template string Utils::ToString<unsigned int>(unsigned int);
template string Utils::ToString<int>(int);
template string Utils::ToString<double>(double);
template string Utils::ToString<string>(string);
template string Utils::ToString<char>(char);
template string Utils::ToString<MGraph::Edge>(MGraph::Edge);
template string Utils::ToString<SGraph::Path>(SGraph::Path);
template string Utils::ToString<SGraph::WeightedVertex>(SGraph::WeightedVertex);
template string Utils::ToString<SGraph::MinEdge>(SGraph::MinEdge);

template unsigned int Utils::DoHash<int>(int, unsigned int (*hash_func)(char*, size_t));
template unsigned int Utils::DoHash<string>(string, unsigned int (*hash_func)(char*, size_t));
template unsigned int Utils::DoHash<double>(double, unsigned int (*hash_func)(char*, size_t));
template unsigned int Utils::DoHash<char>(char, unsigned int (*hash_func)(char*, size_t));
