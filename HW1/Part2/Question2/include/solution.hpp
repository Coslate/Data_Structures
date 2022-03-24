//solution.hpp
#include <solution.h>
#include <cstdlib>

template <typename T>
void SparseMatrix<T>::SetMatrixTermArray(const MatrixTerm<T>* const &in_sm_array, const int &in_terms){
    if(capacity < in_terms){
        throw std::runtime_error(std::string("Error: the capacity is not sufficient for copying in_sm_array."));
    }
    for(int i=0;i<terms;++i){
        sm_array[i] = in_sm_array[i];
    }
}


template <typename T>
void SparseMatrix<T>::ChangeArraySize(const int &new_size){
    if(new_size <= 0) throw std::runtime_error(std::string("Error: The new size of the array storing terms in SparseMatrix must > 0."));

    int number          = new_size;
    capacity            = 2*new_size;

    MatrixTerm<T> *temp = new MatrixTerm<T>[capacity];
    std::copy(sm_array, sm_array+number, temp);
    sm_array = temp;
    temp     = nullptr;
    terms    = number;
}

template <typename T>
void SparseMatrix<T>::NewMatrixTerm(const int &row_pos, const int &col_pos, const T &value){
    if(terms == capacity){
        capacity *= 2;
        MatrixTerm<T> *temp = new MatrixTerm<T> [capacity];
        std::copy(sm_array, sm_array+terms, temp);
        delete [] sm_array;
        sm_array = temp;
        temp = nullptr;
    }

    sm_array[terms].row = row_pos;
    sm_array[terms].col = col_pos;
    sm_array[terms].value = value;
    terms++;
}

template <typename T>
void SparseMatrix<T>::operator=(const SparseMatrix &other){
    if(capacity > 0){
        delete [] sm_array;
    }

    rows     = other.rows;
    cols     = other.cols;
    terms    = other.terms;
    capacity = other.capacity;

    MatrixTerm<T> *temp = new MatrixTerm<T>[terms];
    for(int i=0;i<terms;++i){
        temp[i] = other.sm_array[i];
    }

    sm_array = temp;
    temp = nullptr;
}

template <typename T>
bool SparseMatrix<T>::CheckSameItemAlreadyExisted(const int &row, const int &col, int &found_index){
    bool has_found = false;
    for(int i=0;i<terms;++i){
        if(sm_array[i].row == row && sm_array[i].col==col){
            found_index = i;
            has_found = true;
        }
    }

    return has_found;
}

template <typename T>
SparseMatrix<T> SparseMatrix<T>::Add(SparseMatrix b){
    SparseMatrix<T> c(rows, cols, 0, 0, "temp_result");

    if(terms == 0 && b.terms == 0){
        return c;
    }
    //to-do
    return c;
}

/*
template <T>
bool SparseMatrix<T>::SortFunction(const MatrixTerm<T> &a, const MatrixTerm<T> &b){
    return (a.exp > b.exp);
}
*/


template <typename T>
SparseMatrix<T> SparseMatrix<T>::Transpose(){
    SparseMatrix b(cols, rows, 0, 10, "tmp_b_result");

    if(terms > 0){
        int *row_size  = new int[cols]();
        int *row_start = new int[cols]();

        //allocate array in b
        b.ChangeArraySize(terms);
        b.SetMatrixTermArray(sm_array, terms);

        //calculate the row size of the new matrix
        for(int i=0;i<terms;++i){
            row_size[sm_array[i].col]++;
        }

        //calculate the starting index of each row in the new matrix
        for(int i=1;i<cols;++i){
            row_start[i] = row_start[i-1]+row_size[i-1];
        }

        //start moving data
        for(int i=0;i<terms;++i){
            int j=row_start[sm_array[i].col];
            b.sm_array[j].row   = sm_array[i].col;
            b.sm_array[j].col   = sm_array[i].row;
            b.sm_array[j].value = sm_array[i].value;
            row_start[sm_array[i].col]++;
        }

        delete [] row_size;
        delete [] row_start;
    }

    return b;
}

template <typename T>
SparseMatrix<T> SparseMatrix<T>::Multiply(SparseMatrix b){
    SparseMatrix<T> c(rows, cols, 0, 0, "temp_result");

    if(terms == 0 && b.terms == 0){
        return c;
    }
    //to-do
    return c;
}

