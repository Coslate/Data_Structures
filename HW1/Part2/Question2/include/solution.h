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
        MatrixTerm() : coef(0), exp(0), value(0){}
        MatrixTerm(const int &row, const int &col, const T &value) : row(row), col(col), value(value){}

        //Copy consturctor
        MatrixTerm(const MatrixTerm &p){
            row  = p.row;
            col  = p.col;
            value = p.vlaue;
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

        SparseMatrix                       Transpose           (SparseMatrix b){};
        SparseMatrix                       Add                 (SparseMatrix b){};
        SparseMatrix                       Multiply            (SparseMatrix b){};
        void operator=(const SparseMatrix &polynomial);

        friend std::ostream & operator<<(std::ostream &os, const SparseMatrix<CoefType, ExpType> &out_sparse_matrix){
            if(out_sparse_matrix.terms == 0){
                throw std::runtime_error(std::string("Error: Not available. The SparseMatrix is empty."));
                return os;
            }
            for(int i=0;i<out_sparse_matrix.terms;++i){
                if(i==out_sparse_matrix.terms-1){
                    if(i==0){
                        if(out_sparse_matrix.sm_array[i].GetExp()!=0){
                            os<<out_sparse_matrix.sm_array[i].GetCoef()<<"X^"<<out_sparse_matrix.sm_array[i].GetExp()<<std::endl;
                        }else{
                            os<<out_sparse_matrix.sm_array[i].GetCoef()<<std::endl;
                        }
                    }else{
                        if(out_sparse_matrix.sm_array[i].GetExp()!=0){
                            os<<abs(out_sparse_matrix.sm_array[i].GetCoef())<<"X^"<<out_sparse_matrix.sm_array[i].GetExp()<<std::endl;
                        }else{
                            os<<abs(out_sparse_matrix.sm_array[i].GetCoef())<<std::endl;
                        }
                    }
                }else{
                    if(i==0){
                        if(out_sparse_matrix.sm_array[i+1].GetCoef() > 0){
                            if(out_sparse_matrix.sm_array[i].GetExp()!=0){
                                os<<out_sparse_matrix.sm_array[i].GetCoef()<<"X^"<<out_sparse_matrix.sm_array[i].GetExp()<<"+";
                            }else{
                                os<<out_sparse_matrix.sm_array[i].GetCoef()<<"+";
                            }
                        }else{
                            if(out_sparse_matrix.sm_array[i].GetExp()!=0){
                                os<<out_sparse_matrix.sm_array[i].GetCoef()<<"X^"<<out_sparse_matrix.sm_array[i].GetExp()<<"-";
                            }else{
                                os<<out_sparse_matrix.sm_array[i].GetCoef()<<"-";
                            }
                        }
                    }else{
                        if(out_sparse_matrix.sm_array[i+1].GetCoef() > 0){
                            if(out_sparse_matrix.sm_array[i].GetExp()!=0){
                                os<<abs(out_sparse_matrix.sm_array[i].GetCoef())<<"X^"<<out_sparse_matrix.sm_array[i].GetExp()<<"+";
                            }else{
                                os<<abs(out_sparse_matrix.sm_array[i].GetCoef())<<"+";
                            }
                        }else{
                            if(out_sparse_matrix.sm_array[i].GetExp()!=0){
                                os<<abs(out_sparse_matrix.sm_array[i].GetCoef())<<"X^"<<out_sparse_matrix.sm_array[i].GetExp()<<"-";
                            }else{
                                os<<abs(out_sparse_matrix.sm_array[i].GetCoef())<<"-";
                            }
                        }
                    }
                }
            }

            return os;
        }
        friend std::istream & operator>>(std::istream &in, SparseMatrix<CoefType, ExpType> &in_sparse_matrix){
            CoefType temp_coef;
            ExpType  temp_exp;

            std::cout<<"Please enter the coefficient for "<<in_sparse_matrix.name<<" : ";
            in>> temp_coef;
            std::cout<<"Please enter the exponential for "<<in_sparse_matrix.name<<" : ";
            in>> temp_exp;

            if(temp_coef == 0){
                std::cout<<"Warning: The coefficient you just entered is 0, which will not be taken into the SparseMatrix."<<std::endl;
                return in;
            }

            if((temp_exp > in_sparse_matrix.max_exp) && (in_sparse_matrix.input_at_least_once)){
                std::cout<<"Warning: You just entered an exponential that is bigger than the largest one you entered before : "<<in_sparse_matrix.max_exp<<". Please enter in decreasing order of exponential. This one will be neglected."<<std::endl;
                return in;
            }

            if(!in_sparse_matrix.input_at_least_once){
                in_sparse_matrix.max_exp = temp_exp;
                in_sparse_matrix.input_at_least_once = true;
                if(in_sparse_matrix.terms > 0){
                    in_sparse_matrix.terms = 0;
                    delete [] in_sparse_matrix.sm_array;
                    MatrixTerm<CoefType, ExpType> *temp = new MatrixTerm<CoefType, ExpType> [in_sparse_matrix.capacity];
                    in_sparse_matrix.sm_array = temp;
                    temp = nullptr;
                }
            }

            in_sparse_matrix.NewMatrixTerm(temp_coef, temp_exp);
            return in;
        }
};

#include <solution.hpp>
#endif

