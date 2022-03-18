#ifndef _SOLUTION_H_
#define _SOLUTION_H_

#include <vector>
#include <string>
#include <iostream>

template <typename T>
class Complex_Matrix;//forward declaration

template <typename T>
class Matrix{
    private:
        T** value_;
        int cols_;
        int rows_;
        std::string name_;

        void NewSize(){
            value_ = new T* [rows_];
            for(int i=0;i<rows_;++i){
                value_[i] = new T [cols_]();
            }
        }
    public:
        Matrix() : value_(nullptr), cols_(0), rows_(0), name_("NullMatrix") {}
        Matrix(const std::string &name) : value_(nullptr), cols_(0), rows_(0), name_(name) {}
        Matrix(const int &rows, const int &cols, const std::string &name="Null") : cols_(cols), rows_(rows), name_(name) {
            value_ = new T* [rows_];
            for(int i=0;i<rows_;++i){
                value_[i] = new T [cols_]();
            }
        }
        Matrix(const int &rows, const int &cols, const std::string &name, T** const &input) : cols_(cols), rows_(rows), name_(name) {
            /*
            value_ = new T* [rows_];
            for(int i=0;i<rows_;++i){
                value_[i] = new T [cols_]();
            }
            */
            NewSize();

            for(int i=0;i<rows_;++i){
                for(int j=0;j<cols_;++j){
                    value_[i][j] = input[i][j];
                }
            }
        }
        Matrix(const Matrix &p){
            rows_ = p.GetRows();
            cols_ = p.GetCols();
            name_ = p.GetName();

            NewSize();
            /*
            value_ = new T* [rows_];
            for(int i=0;i<rows_;++i){
                value_[i] = new T [cols_]();
            }
            */
            for(int i=0;i<rows_;++i){
                for(int j=0;j<cols_;++j){
                    value_[i][j] = p.GetValues(i, j);
                }
            }
        }
        ~Matrix(){
            for(int i=0;i<rows_;++i){
                delete [] value_[i];
            }

            delete value_;
        }

        int           GetRows() const {return rows_;}
        int           GetCols() const {return cols_;}
        std::string   GetName() const {return name_;}
        T             GetValues (const int &i, const int &j) const {return value_[i][j];}


        void  SetRows(const int &input){ rows_ = input; }
        void  SetCols(const int &input){ cols_ = input; }
        void  SetValues(const int &i, const int &j, const T &input){ value_[i][j] = input; }

        void  Print() const {
              std::cout<<"Matrix "<<name_<<" = "<<std::endl;
              for(int i=0;i<rows_;++i){
                for(int j=0;j<cols_;++j){
                    if(i==0){
                        if(j==cols_-1){
                            std::cout<<value_[i][j]<<std::endl;
                        }else if(j==0){
                            std::cout<<"[ "<<value_[i][j]<<" ";
                        }else{
                            std::cout<<value_[i][j]<<" ";
                        }
                    }else if(i==rows_-1){
                        if(j==cols_-1){
                            std::cout<<value_[i][j]<<" ]"<<std::endl;
                        }else if(j==0){
                            std::cout<<"  "<<value_[i][j]<<" ";
                        }else{
                            std::cout<<value_[i][j]<<" ";
                        }
                    }else{
                        if(j==cols_-1){
                            std::cout<<value_[i][j]<<std::endl;
                        }else if(j==0){
                            std::cout<<"  "<<value_[i][j]<<" ";
                        }else{
                            std::cout<<value_[i][j]<<" ";
                        }
                    }
                }
              }
        }

        Matrix<T> MatrixMul   (const Matrix &input_matrix); //A*B
        Matrix<T> MatrixScalar(const T &scalar);         //A*c
        Matrix<T> MatrixAdd   (const Matrix &input_matrix); //A+B
        void operator=(const Matrix &other);
//        void operator=(Matrix<T>& other);

        friend class Complex_Matrix<T>;

};

template <typename T>
class Complex_Matrix{
    private:
        Matrix<T> complex_value[2];//0:real, 1:imag
        std::string comp_name_;
    public:
        Complex_Matrix(const std::string &name):comp_name_(name){}
        Complex_Matrix(const Matrix<T> &real, const Matrix<T> &imag, const std::string &name){
            comp_name_ = name;
            //Real part construction
            complex_value[0].rows_ = real.GetRows();
            complex_value[0].cols_ = real.GetCols();
            complex_value[0].name_ = real.GetName();
            complex_value[0].NewSize();

            //Imag part construction
            complex_value[1].rows_ = imag.GetRows();
            complex_value[1].cols_ = imag.GetCols();
            complex_value[1].name_ = imag.GetName();
            complex_value[1].NewSize();

            //Real value_ initialization
            for(int i=0;i<complex_value[0].rows_;++i){
                for(int j=0;j<complex_value[0].cols_;++j){
                    complex_value[0].value_[i][j] = real.GetValues(i, j);
                }
            }

            //Image value_ initialization
            for(int i=0;i<complex_value[1].rows_;++i){
                for(int j=0;j<complex_value[1].cols_;++j){
                    complex_value[1].value_[i][j] = imag.GetValues(i, j);
                }
            }
        }

        Matrix<T>      GetReal() const {return complex_value[0];}
        Matrix<T>      GetImag() const {return complex_value[1];}
        void           SetReal(const int &i, const int &j, const T &input_value){complex_value[0].value_[i][j] = input_value;}
        void           SetImag(const int &i, const int &j, const T &input_value){complex_value[1].value_[i][j] = input_value;}

        void  Print() const {
            std::cout<<"Complex Matrix "<<comp_name_<<" = ("<<complex_value[0].name_<<" + "<<"i*"<<complex_value[1].name_<<"), with"<<std::endl;
            complex_value[0].Print();
            complex_value[1].Print();
            std::cout<<"---------------------------------"<<std::endl;
        }

        Complex_Matrix<T> Complex_MatrixMul(const Complex_Matrix &input_matrix);

};

#include <solution.hpp>
#endif
