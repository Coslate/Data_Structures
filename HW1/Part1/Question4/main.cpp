//main.cpp
#include <iostream>
#include <solution.h>

const int rows = 3;
const int cols = 3;

template <typename T>
T** Initialization(T (&array_a)[rows][cols]){
    int** arr_a = new int* [rows];
    for(int i=0;i<rows;++i){
        arr_a[i] = new int[cols]();
    }
    for(int i=0;i<rows;++i){
        for(int j=0;j<cols;++j){
            arr_a[i][j] = array_a[i][j];
        }
    }
    return arr_a;
}

int main(){
    int   arr_a_data [rows][cols] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int   arr_b_data [rows][cols] = {
        {11, 12, 13},
        {14, 15, 16},
        {17, 18, 19}
    };
    int** arr_a = Initialization(arr_a_data);
    int** arr_b = Initialization(arr_b_data);


    Matrix<int> matrix_a(rows, cols, "matrix_a", arr_a);
    Matrix<int> matrix_b(rows, cols, "matrix_b", arr_b);

    matrix_a.Print();
    matrix_b.Print();

    Matrix<int> matrix_c("matrix_c");
    Matrix<int> matrix_d("matrix_d");
    Matrix<int> matrix_e("matrix_e");

    matrix_c = matrix_a.MatrixMul(matrix_b);
    matrix_d = matrix_a.MatrixAdd(matrix_b);
    matrix_e = matrix_d.MatrixScalar(3);

    matrix_c.Print();
    matrix_d.Print();
    matrix_e.Print();

    std::cout<<"---------------------"<<std::endl;
    Complex_Matrix<int> comp_matrix1(matrix_a, matrix_b, "comp_matrix1");
    comp_matrix1.Print();

    return EXIT_SUCCESS;
}
