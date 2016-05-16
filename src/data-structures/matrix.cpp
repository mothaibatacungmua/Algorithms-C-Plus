/*
 * matrix.cpp
 *
 *  Created on: May 15, 2016
 *      Author: asm
 */

#include <string>
#include <iostream>

#include "../../headers/type-parse.hpp"
#include "../../headers/data-structures.hpp"
#include "../../headers/error-codes.hpp"

using namespace DataStructures;

template <typename V>
Matrix<V>::Matrix(int n, int m){
    this->matrix = new Vector<V>[n];

    if(this->matrix == NULL) throw ErrorCodes::ALLOC_MEM_ERROR;

    this->nrow = n;
    this->ncol = m;

    for(int i = 0; i < this->nrow; i++){
        this->matrix[i].Resize(this->ncol);
    }
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

template <typename V>
Vector<V>* Matrix<V>::GetStorage(){
    return this->matrix;
}

template <typename V>
void Matrix<V>::SetStorage(Matrix<V>& x){
    delete [] this->matrix;

    int n = 0;
    int m = 0;

    x.Size(n, m);

    this->matrix = new Vector<V>[n];
    Vector<V>* x_storage = x.GetStorage();

    for(int i = 0; i < m; i++){
        this->matrix[i] = x_storage[i];
    }

    this->nrow = n;
    this->ncol = m;
}

template <typename V>
void Matrix<V>::Size(int& n, int& m){
    n = this->nrow;
    m = this->ncol;
}

template <typename V>
Matrix<V>& Matrix<V>::operator =(Matrix<V>& x){
    this->SetStorage(x);

    return *this;
}

template <typename V>
Vector<V>& Matrix<V>::operator[](int index){
    if(index >= this->nrow) throw ErrorCodes::OUT_OF_INDEX;

    return this->matrix[index];
}

template <typename V>
bool Matrix<V>::DeleteColumn(int col){
    return true;
}

template <typename V>
bool Matrix<V>::DeleteColumn(const Vector<int> col){
    return true;
}

template <typename V>
bool Matrix<V>::DeleteRow(int row){
    return true;
}

template <typename V>
bool Matrix<V>::DeleteRow(Vector<int> row){
    return true;
}

template <typename V>
string Matrix<V>::ToString(){
    string ret;
    for(int i = 0; i < this->nrow; i++){
        ret.append(" ");
        ret.append(this->matrix[i].ToString());
        ret.append(" \n");
    }

    return ret;
}




template class Matrix<int>;
template class Matrix<double>;
template class Matrix<string>;
