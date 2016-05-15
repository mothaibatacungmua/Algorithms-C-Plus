/*
 * matrix.cpp
 *
 *  Created on: May 15, 2016
 *      Author: asm
 */

#include <string>

#include "../../headers/type-parse.hpp"
#include "../../headers/data-structures.hpp"
#include "../../headers/error-codes.hpp"

using namespace DataStructures;

template <typename V>
Matrix<V>::Matrix(int n, int m){
    this->matrix = new Vector<V>[n](m);

    if(this->matrix == NULL) throw ErrorCodes::ALLOC_MEM_ERROR;

    this->nrow = n;
    this->ncol = m;
}

template <typename V>
Matrix<V>::Matrix(Vector<V>* vectors, int nvec, bool with_col, bool check_square){
    Vector<V> temp_vec;
    if(nvec == 0) throw ErrorCodes::INPUT_PARAMETERS_ERROR;

    if(with_col){
        this->ncol = nvec;
        this->nrow = vectors[0].Size();

        if(check_square && (this->ncol != this->nrow)) throw ErrorCodes::INPUT_PARAMETERS_ERROR;
        this->matrix = new Vector<V>[this->nrow];
        if(this->matrix == NULL) throw ErrorCodes::ALLOC_MEM_ERROR;


        temp_vec.Resize(this->ncol);

        for(int i = 0; i < this->nrow; i++){
            for(int j = 0; j < this->ncol;j++){
                if(vectors[j].Size() != this->nrow) throw ErrorCodes::INPUT_PARAMETERS_ERROR;
                temp_vec[j] = vectors[j][i];
            }

            this->matrix[i] = temp_vec;
        }

        return;
    }

    this->ncol = vectors[0].Size();
    this->nrow = nvec;

    if(check_square && (this->ncol != this->nrow)) throw ErrorCodes::INPUT_PARAMETERS_ERROR;

    this->matrix = new Vector<V>[this->nrow];

    if(this->matrix == NULL) throw ErrorCodes::ALLOC_MEM_ERROR;

    for(int i=0; i < this->nrow; i++){
        this->matrix[i] = vectors[i];
    }
}

template <typename V>
Matrix<V>::~Matrix(){
    delete [] this->matrix;
}
