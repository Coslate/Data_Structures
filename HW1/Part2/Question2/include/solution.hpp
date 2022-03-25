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
void SparseMatrix<T>::SortAccordingToRow(){
    if(terms<=0){
        std::cout<<"Warning: Empty sparse matrix. Cannot apply SortAccordingToRow().";
        return;
    }

    MatrixTerm<T> *temp = new MatrixTerm<T>[capacity];
    int *row_size  = new int[cols]();
    int *row_start = new int[cols]();

    //calculate the row size of the new matrix
    for(int i=0;i<terms;++i){
        row_size[sm_array[i].row]++;
    }

    //calculate the starting index of each row in the new matrix
    for(int i=1;i<cols;++i){
        row_start[i] = row_start[i-1]+row_size[i-1];
    }

    //start moving data
    for(int i=0;i<terms;++i){
        int j=row_start[sm_array[i].row];
        temp[j].row   = sm_array[i].row;
        temp[j].col   = sm_array[i].col;
        temp[j].value = sm_array[i].value;
        row_start[sm_array[i].row]++;
    }

    delete [] row_size;
    delete [] row_start;

    if(capacity>0){
        delete [] sm_array;
    }
    sm_array = temp;
    temp = nullptr;
}

template <typename T>
SparseMatrix<T> SparseMatrix<T>::Add(SparseMatrix b){
    if(b.rows != rows || b.cols !=cols){
        throw std::runtime_error(std::string("Error: the rows or cols of "+b.name+" does not match with "+name+". Thus, the Add() cannot be applied."));
    }

    SparseMatrix<T> c(rows, cols, 0, 10, "temp_result");

    if(terms>0 && b.terms>0){
        int aPos=0;
        int bPos=0;
        int current_row_a = sm_array[aPos].row;
        int current_row_b = b.sm_array[bPos].row;

        SortAll();
        b.SortAll();

        while(aPos<terms && bPos<b.terms){
            if(sm_array[aPos].row==b.sm_array[bPos].row){
                if(sm_array[aPos].col==b.sm_array[bPos].col){
                    c.NewMatrixTerm(sm_array[aPos].row, sm_array[aPos].col, (sm_array[aPos].value+b.sm_array[bPos].value));
                    aPos++;
                    bPos++;
                }else if(sm_array[aPos].col < b.sm_array[bPos].col){
                    c.NewMatrixTerm(sm_array[aPos].row, sm_array[aPos].col, sm_array[aPos].value);
                    aPos++;
                }else{
                    c.NewMatrixTerm(b.sm_array[bPos].row, b.sm_array[bPos].col, b.sm_array[bPos].value);
                    bPos++;
                }
            }else if(sm_array[aPos].row < b.sm_array[bPos].row){
                while(sm_array[aPos].row == current_row_a){
                    c.NewMatrixTerm(sm_array[aPos].row, sm_array[aPos].col, sm_array[aPos].value);
                    aPos++;
                }
                current_row_a = sm_array[aPos].row;
            }else{
                while(b.sm_array[bPos].row == current_row_b){
                    c.NewMatrixTerm(b.sm_array[bPos].row, b.sm_array[bPos].col, b.sm_array[bPos].value);
                    bPos++;
                }
                current_row_b = b.sm_array[bPos].row;
            }
        }

        for(int i=aPos;i<terms;++i){
            c.NewMatrixTerm(sm_array[i].row, sm_array[i].col, sm_array[i].value);
        }

        for(int i=bPos;i<b.terms;++i){
            c.NewMatrixTerm(b.sm_array[i].row, b.sm_array[i].col, b.sm_array[i].value);
        }
    }else if(terms==0 && b.terms>0){
        return b;
    }else if(b.terms==0 && terms>0){
        return *this;
    }

    return c;
}

template <typename T>
bool SparseMatrix<T>::SortFunction(const MatrixTerm<T> &a, const MatrixTerm<T> &b){
    return (((a.row<b.row) && (a.col<b.col)) ? true : (a.row<b.row ? true : (a.row==b.row ? a.col<b.col : false)));
}

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
void SparseMatrix<T>::DeleteOneLastElement(){
    if(terms>0){
        MatrixTerm<T> *temp = new MatrixTerm<T>[capacity];
        std::copy(sm_array, sm_array+terms-1, temp);
        delete [] sm_array;
        sm_array = temp;
        temp = nullptr;
        terms--;
    }
}

template <typename T>
SparseMatrix<T> SparseMatrix<T>::Multiply(SparseMatrix b){
    if(terms == 0){
        throw std::runtime_error(std::string("Warning: "+name+"is an empty matrix. Thus, the Multiply() cannot be applied."));
    }

    if(b.terms == 0){
        throw std::runtime_error(std::string("Warning: "+b.name+"is an empty matrix. Thus, the Multiply() cannot be applied."));
    }

    if(cols != b.rows){
        throw std::runtime_error(std::string("Error: the cols of matrix of "+name+" does not match with the rows of matrix of "+b.name+". Thus, the Multiply() cannot be applied."));
    }
    SparseMatrix<T> c(rows, b.cols, 0, 10, "temp_result");
    SparseMatrix<T> b_transpose = b.Transpose();

    SortAll();
    b_transpose.SortAll();

    int curr_row_index = 0;
    int curr_row_begin = 0;
    int curr_rowa      = sm_array[0].row;

    NewMatrixTerm(rows, cols, -1); //Add one temp term to *this, will be deleted later.
    b_transpose.NewMatrixTerm(b.cols, -1, -1);

    T sum = 0;
    while(curr_row_index < terms){
        int curr_colb = b_transpose.sm_array[0].row;
        int curr_col_index = 0;

        while(curr_col_index <= b_transpose.terms){
            if(sm_array[curr_row_index].row != curr_rowa){//rowa end
                if(sum != 0){
                    c.NewMatrixTerm(curr_rowa, curr_colb, sum);
                    sum = 0;
                }
                curr_row_index = curr_row_begin;//rewind to the beginning of rowa

                while(b_transpose.sm_array[curr_col_index].row == curr_colb){
                    curr_col_index++;//skip the remaining terms in b_transpose
                }

                curr_colb = b_transpose.sm_array[curr_col_index].row;
            }else if(b_transpose.sm_array[curr_col_index].row != curr_colb){//colb end
                if(sum != 0){
                    c.NewMatrixTerm(curr_rowa, curr_colb, sum);
                    sum = 0;
                }
                curr_row_index = curr_row_begin;//rewind to the beginning of rowa
                curr_colb = b_transpose.sm_array[curr_col_index].row;
            }else{
                if(sm_array[curr_row_index].col < b_transpose.sm_array[curr_col_index].col){
                    curr_row_index++;
                }else if(sm_array[curr_row_index].col == b_transpose.sm_array[curr_col_index].col){
                    sum += sm_array[curr_row_index].value*b_transpose.sm_array[curr_col_index].value;
                    curr_row_index++;
                    curr_col_index++;
                }else{
                    curr_col_index++;
                }
            }
        }
        //Go to next rowa
        while(sm_array[curr_row_index].row == curr_rowa){
            curr_row_index++;
        }
        curr_row_begin = curr_row_index;
        curr_rowa = sm_array[curr_row_index].row;
    }

    DeleteOneLastElement();
    return c;
}

