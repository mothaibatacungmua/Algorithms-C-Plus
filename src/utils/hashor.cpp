/*
 * hash-algor.cpp
 *
 *  Created on: May 3, 2016
 *      Author: asm
 */
#include "../../headers/algorithms.hpp"
#include "../../headers/hashor.hpp"
#include "../../headers/type-parse.hpp"

using namespace std;

namespace Utils{
    template <typename T, typename R>
    R DoHash(T obj, R (*hash_func)(char*, size_t)){
        if(COMPARE_TYPE(T,"int")){
            return hash_func((char*)&obj, sizeof(int));
        }

        if(COMPARE_TYPE(T,"double")){
            return hash_func((char*)&obj, sizeof(double));
        }

        if(COMPARE_TYPE(T,"char")){
            return hash_func((char*)&obj, sizeof(char));
        }

        if(COMPARE_TYPE(T,"string")){
            string cast = *(reinterpret_cast<string*>(&obj));
            return hash_func(cast.c_str(), cast.size());
        }
    }

    template <typename T>
    int JenkinsHash<T>::operator() (T obj){
        return Utils::DoHash<T, int>(obj, Algorithms::Hash::JenkinsHash);
    }
}
