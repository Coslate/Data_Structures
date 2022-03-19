//solution.hpp
#include <solution.h>

template <typename T>
Matrix<T> Matrix<T>::MatrixMul(const Matrix &input_matrix){
    if(cols_ != input_matrix.GetRows()){
        throw std::runtime_error(std::string("Error in MatrixMul: dimension of *this.cols != input_matrix.rows. Cannot do the multiplication."));
        exit(0);
    }

    Matrix<T> result(rows_, input_matrix.GetCols());

    for(int i=0;i<rows_;++i){
        for(int j=0;j<input_matrix.GetCols();++j){
            T temp = 0;
            for(int k=0;k<cols_;++k){
                temp += value_[i][k]*input_matrix.GetValues(k, j);
            }
            result.SetValues(i, j, temp);
        }
    }
    return result;
}

template <typename T>
Matrix<T> Matrix<T>::MatrixScalar(const T &scalar){         //A*c
    if(rows_==0 || cols_ ==0){
        throw std::runtime_error(std::string("Error in MatrixScalar: The caller Matrix has rows_==0 or cols_==0."));
        exit(0);
    }

    Matrix<T> result(rows_, cols_);

    for(int i=0;i<result.GetRows();++i){
        for(int j=0;j<result.GetCols();++j){
            result.SetValues(i, j, value_[i][j]*scalar);
        }
    }

    return result;
}

template <typename T>
Matrix<T> Matrix<T>::MatrixAdd(const Matrix &input_matrix){ //A+B
    if(rows_!=input_matrix.GetRows() || cols_ !=input_matrix.GetCols()){
        throw std::runtime_error(std::string("Error in MatrixAdd: The dimension of *this matrix does not match with the input_matrix."));
        exit(0);
    }
    Matrix<T> result(rows_, cols_);

    for(int i=0;i<result.GetRows();++i){
        for(int j=0;j<result.GetCols();++j){
            result.SetValues(i, j, (value_[i][j] + input_matrix.GetValues(i, j)));
        }
    }

    return result;
}

template <typename T>
void Matrix<T>::operator=(const Matrix &other){
    if(value_ != nullptr){
        for(int i=0;i<rows_;++i){
            delete [] value_[i];
        }

        delete value_;
    }

    this->rows_ = other.GetRows();
    this->cols_ = other.GetCols();

    NewSize();
    for(int i=0;i<rows_;++i){
        for(int j=0;j<cols_;++j){
            value_[i][j] = other.GetValues(i, j);
        }
    }
}

template <typename T>
void Complex_Matrix<T>::operator=(const Complex_Matrix &input_matrix){
    complex_value[0] = input_matrix.GetReal();
    complex_value[1] = input_matrix.GetImag();
}

template <typename T>
Complex_Matrix<T> Complex_Matrix<T>::Complex_MatrixMul(const Complex_Matrix &input_comp_matrix){
    Matrix<T> real_mul_result("real_mul_result");
    Matrix<T> imag_mul_result("imag_mul_result");
    Complex_Matrix<T> result("result");

    real_mul_result = complex_value[1].MatrixMul(input_comp_matrix.GetImag());//B*D
    real_mul_result = real_mul_result.MatrixScalar(-1);//-B*D
    real_mul_result = real_mul_result.MatrixAdd(complex_value[0].MatrixMul(input_comp_matrix.GetReal()));//(A*C)-(B*D)

    imag_mul_result = complex_value[0].MatrixMul(input_comp_matrix.GetImag());//A*D
    imag_mul_result = imag_mul_result.MatrixAdd(complex_value[1].MatrixMul(input_comp_matrix.GetReal()));//(A*D)+(B*C)

    result.SetReal(real_mul_result);
    result.SetImag(imag_mul_result);

    return result;
}

