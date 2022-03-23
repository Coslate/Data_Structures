//solution.hpp
#include <solution.h>
#include <cstdlib>

template <typename T>
void SparseMatrix<T>::SetMatrixTermArray(const MatrixTerm<T>* const &in_sm_array, const int &in_terms);
    if(terms != in_terms){
        throw std::runtime_error(std::string("Error: the size of in_sm_array does not match with the sm_array inside the SparseMatrix."));
    }
    for(int i=0;i<terms;++i){
        sm_array[i] = in_sm_array[i];
    }
}


template <typename T>
void SparseMatrix<T>::ChangeArraySize(const int &new_size){
    if(new_size <= 0) throw std::runtime_error(std::string("Error: The new size of the array storing terms in SparseMatrix must > 0."));

    int number          = std::min(terms, new_size);

    MatrixTerm<T> *temp = new MatrixTerm<T>[new_size];
    std::copy(sm_array, sm_array+number, temp);
    sm_array = temp;
    temp     = nullptr;
    terms    = number;
    capacity = new_size;
}

template <typename T>
void SparseMatrix<T>::NewMatrixTerm(const int &row_pos, const int &col_pos, const T &value){
    if(terms == capacity){
        capacity *= 2;
        Term<CoefType, ExpType> *temp = new Term<CoefType, ExpType> [capacity];
        std::copy(sm_array, sm_array+terms, temp);
        delete [] sm_array;
        sm_array = temp;
        temp = nullptr;
    }

    sm_array[terms].coef = in_coef;
    sm_array[terms].exp  = in_exp;
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

    MatrixTerm<T> *temp = new MatrixTerm<T>[new_size];
    for(int i=0;i<terms;++i){
        temp[i] = other.sm_array[i];
    }

    sm_array = temp;
    temp = nullptr;
}

template <typename T>
SparseMatrix<T> SparseMatrix<T>::Add(SparseMatrix b){
    SparseMatrix<CoefType, ExpType> c(rows, cols, 0, 0, "temp_result");

    if(terms == 0 && b.terms == 0){
        return c;
    }
    //to-do
    return c;
}

/*
template <typename CoefType, typename ExpType>
bool SparseMatrix<CoefType, ExpType>::SortFunction(const Term<CoefType, ExpType> &a, const Term<CoefType, ExpType> &b){
    return (a.exp > b.exp);
}
*/

template <typename CoefType, typename ExpType>
SparseMatrix<CoefType, ExpType> SparseMatrix<CoefType, ExpType>::Mul(SparseMatrix b){
    SparseMatrix<CoefType, ExpType> c(rows, cols, 0, 0, "temp_result");

    if(terms == 0 && b.terms == 0){
        return c;
    }
    //to-do
    return c;
}

