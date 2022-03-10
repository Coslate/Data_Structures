#ifndef _SOLUTION_H_
#define _SOLUTION_H_

#include <vector>
#include <string>
#include <iostream>

template <typename T>
class Matrix{
    private:
        T** value_;
        int rows_;
        int cols_;
        std::string name_;
    public:
        Matrix() : value_(nullptr), cols_(0), rows_(0), name_("NullMatrix") {}
        Matrix(const int &rows, const int &cols, const std::string &name) : rows_(rows), cols_(cols), name_(name) {
            value_ = new T* [rows_];
            for(int i=0;i<rows_;++i){
                value_[i] = new T [cols_]();
            }
        }
        Matrix(const int &rows, const int &cols, const std::string &name, T** const &input) : rows_(rows), cols_(cols), name_(name) {
            value_ = new T* [rows_];
            for(int i=0;i<rows_;++i){
                value_[i] = new T [cols_]();
            }
            for(int i=0;i<rows_;++i){
                for(int j=0;j<cols_;++j){
                    value_[i][j] = input[i][j];
                }
            }
        }
        ~Matrix(){
            for(int i=0;i<rows_;++i){
                delete [] value_[i];
            }

            delete value_;
        }
        int   GetRows()    {return rows_;}
        int   GetCols()    {return cols_;}
        T     GetValues(const int &row, const int &col){return value_[row][col];}
        void  SetRows(const int &input){ rows_ = input; }
        void  SetCols(const int &input){ cols_ = input; }
        void  SetValues(const int &row, const int &col, const T &input){ value_[row][col] = input; }
        void  Print(){
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

};

#endif
