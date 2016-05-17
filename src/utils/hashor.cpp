/*
 * hash-algor.cpp
 *
 *  Created on: May 3, 2016
 *      Author: asm
 */
#include "../../headers/algorithms.hpp"
#include "../../headers/type-parse.hpp"
#include "../../headers/hashor.hpp"

using namespace std;

namespace Utils{
    template <typename T>
    unsigned int JenkinsHash<T>::operator() (T obj){
        return Utils::DoHash(obj, Algorithms::Hash::JenkinsHash);
    }
}

template class Utils::JenkinsHash<int>;
template class Utils::JenkinsHash<string>;
template class Utils::JenkinsHash<char>;
template class Utils::JenkinsHash<double>;
