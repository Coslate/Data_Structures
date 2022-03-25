#ifndef _SOLUTION_H_
#define _SOLUTION_H_

#include <vector>
#include <string>
#include <cfloat>
#include <climits>
#include <math.h>
#include <unordered_map>
#include <algorithm>
#include <iostream>

template <typename T>
class SparseMatrix;//forward declaration

template <typename T>
class MatrixTerm{
    private:
        int row, col;
        T value;

    public:
        MatrixTerm() : row(0), col(0), value(0){}
        MatrixTerm(const int &row, const int &col, const T &value) : row(row), col(col), value(value){}

        //Copy consturctor
        MatrixTerm(const MatrixTerm &p){
            row  = p.row;
            col  = p.col;
            value = p.value;
        }

        void SetRow(const int &in_row){row = in_row;}
        void SetCol(const int &in_col){col = in_col;}
        void SetValue(const T &in_value){value = in_value;}
        int GetRow() const {return row;}
        int GetCol() const {return col;}
        T   GetValue() const {return value;}
        void operator=(const MatrixTerm &in_term){
            row   = in_term.row;
            col   = in_term.col;
            value = in_term.value;
        }

        //Destructor
        ~MatrixTerm(){}
        friend class SparseMatrix<T>;

};

template <typename T>
class SparseMatrix{
    private:
        int         rows;
        int         cols;
        int         terms;    //the number of non-zero terms
        int         capacity; //the max-size of sm_array
        std::string name;
        MatrixTerm<T>* sm_array;
    public:
        SparseMatrix(const int &rows=3, const int &cols=3, const int &terms = 0, const int capacity=10, const std::string &name="NULL"):rows(rows), cols(cols), terms(terms), capacity(capacity), name(name){
            if(capacity > 0){
                sm_array = new MatrixTerm<T> [capacity];
            }else{
                sm_array = nullptr;
            }
        }

        //Copy consturctor
        SparseMatrix(const SparseMatrix &p){
            rows     = p.rows;
            cols     = p.cols;
            terms    = p.terms;
            capacity = p.capacity;
            name     = p.name;
            sm_array = new MatrixTerm<T> [capacity];

            for(int i=0;i<terms;++i){
                sm_array[i] = p.sm_array[i];
            }
        }

        //Destructor
        ~SparseMatrix(){
            delete [] sm_array;
            sm_array = nullptr;
        }

        //Support Functions
        int                                GetRows             () const {return rows;}
        int                                GetCols             () const {return cols;}
        int                                GetMatrixTerms      () const {return terms;}
        int                                GetCapacity         () const {return capacity;}
        std::string                        GetName             () const {return name;}
        MatrixTerm<T>*                     GetMatrixTermArray  () const {return sm_array;}

        void                               SetRows             (const int &in_rows)        {rows     = in_rows;}
        void                               SetCols             (const int &in_cols)        {cols     = in_cols;}
        void                               SetMatrixTerms      (const int &in_terms)       {terms    = in_terms;}
        void                               SetCapacity         (const int &in_capacity)    {capacity = in_capacity;}
        void                               SetName             (const std::string &in_name){name     = in_name;}
        void                               SetMatrixTermArray  (const MatrixTerm<T>* const &in_sm_array, const int &in_terms);
        void                               NewMatrixTerm       (const int &row_pos, const int &col_pos, const T &value);
        void                               ChangeArraySize(const int &new_size);
        bool                               CheckSameItemAlreadyExisted(const int &row, const int &col, int &found_index);

        void                               SortAccordingToRow  ();
        void                               SortAll             (){std::sort(sm_array, sm_array+terms, SortFunction);}
        static bool                        SortFunction        (const MatrixTerm<T> &a, const MatrixTerm<T> &b);
        SparseMatrix                       Transpose           ();
        SparseMatrix                       Add                 (SparseMatrix b);
        SparseMatrix                       Multiply            (SparseMatrix b);
        void operator=(const SparseMatrix &polynomial);

        friend std::ostream & operator<<(std::ostream &os, const SparseMatrix<T> &out_sparse_matrix){
            if(out_sparse_matrix.terms == 0){
                throw std::runtime_error(std::string("Warning: The SparseMatrix is empty."));
            }

            os<<std::endl<<out_sparse_matrix.name<<"is a "<<out_sparse_matrix.rows<<"X"<<out_sparse_matrix.cols<<" matrix: "<<std::endl;
            for(int i=0;i<out_sparse_matrix.terms;++i){
                os<<"("<<out_sparse_matrix.sm_array[i].GetRow()<<", "<<out_sparse_matrix.sm_array[i].GetCol()<<", "<<out_sparse_matrix.sm_array[i].GetValue()<<")"<<std::endl;
            }

            return os;
        }

        friend std::istream & operator>>(std::istream &in, SparseMatrix<T> &in_sparse_matrix){
            int row, col;
            T value;
            int found_index = 0;
            std::cout<<"Please enter the row of the "<<in_sparse_matrix.terms<<"th item in"<<in_sparse_matrix.name<<" : ";

            while(in>> row){
                try{
                    if(row > (in_sparse_matrix.rows-1) || row<0){
                        throw std::runtime_error(std::string("Error: You just entered an invalid row, which should be <="+std::to_string(in_sparse_matrix.rows-1)+" or >=0. Please enter again : "));
                    }
                }catch(std::runtime_error &e){
                    std::cerr<<e.what()<<std::endl;
                }
                if(row <= (in_sparse_matrix.rows-1) && row >=0) break;
            }
            std::cout<<"Please enter the col of the "<<in_sparse_matrix.terms<<"th item in"<<in_sparse_matrix.name<<" : ";
            while(in>> col){
                try{
                    if(col > (in_sparse_matrix.cols-1) || col<0){
                        throw std::runtime_error(std::string("Error: You just entered an invalid col, which should be <="+std::to_string(in_sparse_matrix.cols-1)+" or >=0. Please enter again : "));
                    }
                }catch(std::runtime_error &e){
                    std::cerr<<e.what()<<std::endl;
                }
                if(col <= (in_sparse_matrix.cols-1) && col >=0) break;
            }

            std::cout<<"Please enter the value of the "<<in_sparse_matrix.terms<<"th item in"<<in_sparse_matrix.name<<" : ";
            in>> value;
            if(value == 0){
                std::cout<<"Since you just entered 0 for the value, it will not be taken into this sparse matrix representation. It is neglected."<<std::endl;
                return in;
            }

            if(in_sparse_matrix.CheckSameItemAlreadyExisted(row, col, found_index)){
                in_sparse_matrix.sm_array[found_index].SetValue(value);
            }else{
                in_sparse_matrix.NewMatrixTerm(row, col, value);
            }
            return in;
        }
};

#include <solution.hpp>
#endif

