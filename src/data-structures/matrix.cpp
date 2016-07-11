/*
 * matrix.cpp
 *
 *  Created on: May 15, 2016
 *      Author: asm
 */

#include <string>
#include <iostream>
#include <set>

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
    if(col > (this->ncol - 1)) return false;

    for(int i=0; i < this->nrow; i++){
        this->matrix[i].Delete(col);
    }

    this->ncol--;

    return true;
}

template <typename V>
bool Matrix<V>::DeleteColumn(Vector<int> col){
    if(col.Size() == 0) return false;

    std::set<int> filter;
    std::set<int>::iterator it;
    //filter valid columns
    for(int i = 0; i < col.Size(); i++){
        if(col[i] <= (this->ncol - 1)) filter.insert(col[i]);
    }

    int prev = *filter.begin();
    int delta = 0;

    for(it = filter.begin(); it != filter.end(); it++){
        delta = (*it <= prev)? 0 : -1;
        this->DeleteColumn(*it+delta);
        prev = *it;
    }

    this->ncol -= filter.size();

    return true;
}

template <typename V>
bool Matrix<V>::DeleteRow(int row){
    if(row > (this->nrow - 1)) return false;

    Vector<V>* new_mat = new Vector<V>[this->nrow-1];

    if(new_mat == NULL){
        delete [] new_mat;
        return false;
    }

    int k = 0;
    for(int i = 0; i < this->nrow; i++){
        if(i == row) continue;

        new_mat[k++] = this->matrix[i];
    }

    delete [] this->matrix;
    this->matrix = new_mat;

    this->nrow--;

    return true;
}

template <typename V>
bool Matrix<V>::DeleteRow(Vector<int> row){
    std::set<int> filter;

    //filter valid rows
    for(int i = 0; i < row.Size(); i++){
        if(row[i] <= this->nrow - 1) filter.insert(row[i]);
    }

    if(filter.size() == 0) return false;

    Vector<V>* new_mat = new Vector<V>[this->nrow - filter.size()];

    int k = 0;
    for(int i = 0; i < this->nrow; i++){
        if(filter.find(i) != filter.end()) continue;

        new_mat[k++] = this->matrix[i];
    }

    delete [] this->matrix;
    this->matrix = new_mat;

    this->nrow -= filter.size();
    return true;
}

template <typename V>
bool Matrix<V>::BindColumns(Matrix<V>& m){
    int add_nrow = 0;
    int add_ncol = 0;

    m.Size(add_nrow, add_ncol);

    if(add_nrow != this->nrow){
        return false;
    }

    Matrix<V> new_mat(this->nrow, this->ncol + add_ncol);

    for(int i = 0; i < this->nrow; i++){
        for(int j=0; j < (this->ncol + add_ncol); j++){
            new_mat[i][j] = (j < this->ncol)? (*this)[i][j]:m[i][j-this->ncol];
        }
    }

    this->SetStorage(new_mat);


    return true;
}

template <typename V>
bool Matrix<V>::BindColumns(Vector<V>* columns, int numcol){
    Matrix<V> append_mat(columns, numcol);

    return this->BindColumns(append_mat);
}

template <typename V>
bool Matrix<V>::BindRows(Matrix<V>& m){
    int add_nrow = 0;
    int add_ncol = 0;

    m.Size(add_nrow, add_ncol);

    if(add_ncol != this->ncol){
        return false;
    }

    Matrix<V> new_mat(this->nrow + add_nrow, this->ncol);

    for(int i = 0; i < (this->nrow + add_nrow); i++){
        for(int j=0; j < this->ncol; j++){
            new_mat[i][j] = (i < this->nrow)? (*this)[i][j]:m[i][j-this->ncol];
        }
    }

    this->SetStorage(new_mat);

    return true;
}

template <typename V>
bool Matrix<V>::BindRows(Vector<V>* rows, int numrow){
    Matrix<V> append_mat(rows, numrow, true);

    return this->BindRows(append_mat);
}

template <typename V>
std::string Matrix<V>::ToString(){
    std::string ret;
    for(int i = 0; i < this->nrow; i++){
        ret.append(" ");
        ret.append(this->matrix[i].ToString());
        ret.append(" \n");
    }

    return ret;
}

template class Matrix<int>;
template class Matrix<double>;
template class Matrix<std::string>;
