//main.cpp
#include <iostream>
#include <time.h>
#include <cstdlib>
#include <unistd.h>
#include <Solution.h>

int main(){
    int num = 20;
    int shift_not_used = 1;
    char  *a_char                  = new char [num+1]();
    char  *a_char_org              = new char [num+1]();
    int   *a_int                   = new int [num+1]();
    int   *a_int_org               = new int [num+1]();
    float *a_float                 = new float [num+1]();
    float *a_float_org             = new float [num+1]();
    std::string *a_str             = new std::string [num+1]();
    std::string *a_str_org         = new std::string [num+1]();

    srand((unsigned)time(NULL) * getpid());

    std::cout<<std::endl;
    std::cout<<"========================================================================="<<std::endl;
    std::cout<<"===================  Randomly Generated Un-sorted Lists ================="<<std::endl;
    std::cout<<"========================================================================="<<std::endl;
    std::cout<<std::endl;
    std::cout<<"> Randomly generate a list of 20 chars as an input unsorted list."<<std::endl;;
    for (int i=0+shift_not_used; i<num+shift_not_used; i++){
        int r = std::rand() % 26;   // generate a random number
        a_char[i] = 'a' + r;            // Convert to a character from a-z
    }
    PrintArray(a_char, num, "---Randomly Generated---\na(char)", shift_not_used);

    std::cout<<std::endl;
    std::cout<<"> Randomly generate a list of 20 integers as an input unsorted list."<<std::endl;;
    for(int i = shift_not_used; i < num+shift_not_used; i++){
        a_int[i] = std::rand()%1001; //generate 0-1000
    }
    PrintArray(a_int, num, "---Randomly Generated---\na(int)", shift_not_used);

    std::cout<<std::endl;
    std::cout<<"> Randomly generate a list of 20 floats as an input unsorted list."<<std::endl;;
    for(int i = shift_not_used; i < num+shift_not_used; i++){
        float rand_tmp = static_cast<float>(std::rand());
        a_float[i] = rand_tmp / (static_cast <float> (RAND_MAX/1000));
    }
    PrintArray(a_float, num, "---Randomly Generated---\na(float)", shift_not_used);

    std::cout<<std::endl;
    std::cout<<"> Randomly generate a list of 20 strings as an input unsorted list."<<std::endl;;
    for(int i = shift_not_used; i < num+shift_not_used; i++){
        int length = std::rand()%30 + 1; //generate length 1-30
        a_str[i] = GenRandomString(length);
    }
    PrintArray(a_str, num, "---Randomly Generated---\na(string)", shift_not_used);

    std::cout<<std::endl;
    std::cout<<"====================================================="<<std::endl;
    std::cout<<"===================  Insertion Sort ================="<<std::endl;
    std::cout<<"====================================================="<<std::endl;

    std::cout<<std::endl;
    std::copy(a_char, a_char+num+1, a_char_org);
    PrintArray(a_char_org, num, "---Original---\na(char)", shift_not_used);
    InsertionSort(a_char_org, num);
    PrintArray(a_char_org, num, "---After Sorting---\na(char)", shift_not_used);

    std::cout<<std::endl;
    std::copy(a_int, a_int+num+1, a_int_org);
    PrintArray(a_int_org, num, "---Original---\na(int)", shift_not_used);
    InsertionSort(a_int_org, num);
    PrintArray(a_int_org, num, "---After Sorting---\na(int)", shift_not_used);

    std::cout<<std::endl;
    std::copy(a_float, a_float+num+1, a_float_org);
    PrintArray(a_float_org, num, "---Original---\na(float)", shift_not_used);
    InsertionSort(a_float_org, num);
    PrintArray(a_float_org, num, "---After Sorting---\na(float)", shift_not_used);

    std::cout<<std::endl;
    std::copy(a_str, a_str+num+1, a_str_org);
    PrintArray(a_str_org, num, "---Original---\na(string)", shift_not_used);
    InsertionSort(a_str_org, num);
    PrintArray(a_str_org, num, "---After Sorting---\na(string)", shift_not_used);

    std::cout<<std::endl;
    std::cout<<"================================================================"<<std::endl;
    std::cout<<"=================== Median-Of-Three Quick Sort ================="<<std::endl;
    std::cout<<"================================================================"<<std::endl;

    std::cout<<std::endl;
    std::copy(a_char, a_char+num+1, a_char_org);
    PrintArray(a_char_org, num, "---Original---\na(char)", shift_not_used);
    QuickSortMedianOfThree(a_char_org, num);
    PrintArray(a_char_org, num, "---After Sorting---\na(char)", shift_not_used);

    std::cout<<std::endl;
    std::copy(a_int, a_int+num+1, a_int_org);
    PrintArray(a_int_org, num, "---Original---\na(int)", shift_not_used);
    QuickSortMedianOfThree(a_int_org, num);
    PrintArray(a_int_org, num, "---After Sorting---\na(int)", shift_not_used);

    std::cout<<std::endl;
    std::copy(a_float, a_float+num+1, a_float_org);
    PrintArray(a_float_org, num, "---Original---\na(float)", shift_not_used);
    QuickSortMedianOfThree(a_float_org, num);
    PrintArray(a_float_org, num, "---After Sorting---\na(float)", shift_not_used);

    std::cout<<std::endl;
    std::copy(a_str, a_str+num+1, a_str_org);
    PrintArray(a_str_org, num, "---Original---\na(string)", shift_not_used);
    QuickSortMedianOfThree(a_str_org, num);
    PrintArray(a_str_org, num, "---After Sorting---\na(string)", shift_not_used);

    std::cout<<std::endl;
    std::cout<<"================================================================"<<std::endl;
    std::cout<<"====================== Iterative Merge Sort ===================="<<std::endl;
    std::cout<<"================================================================"<<std::endl;

    std::cout<<std::endl;
    std::copy(a_char, a_char+num+1, a_char_org);
    PrintArray(a_char_org, num, "---Original---\na(char)", shift_not_used);
    IterativeMergeSort(a_char_org, num);
    PrintArray(a_char_org, num, "---After Sorting---\na(char)", shift_not_used);

    std::cout<<std::endl;
    std::copy(a_int, a_int+num+1, a_int_org);
    PrintArray(a_int_org, num, "---Original---\na(int)", shift_not_used);
    IterativeMergeSort(a_int_org, num);
    PrintArray(a_int_org, num, "---After Sorting---\na(int)", shift_not_used);

    std::cout<<std::endl;
    std::copy(a_float, a_float+num+1, a_float_org);
    PrintArray(a_float_org, num, "---Original---\na(float)", shift_not_used);
    IterativeMergeSort(a_float_org, num);
    PrintArray(a_float_org, num, "---After Sorting---\na(float)", shift_not_used);

    std::cout<<std::endl;
    std::copy(a_str, a_str+num+1, a_str_org);
    PrintArray(a_str_org, num, "---Original---\na(string)", shift_not_used);
    IterativeMergeSort(a_str_org, num);
    PrintArray(a_str_org, num, "---After Sorting---\na(string)", shift_not_used);

    std::cout<<std::endl;
    std::cout<<"================================================================"<<std::endl;
    std::cout<<"====================== Recursive Merge Sort ===================="<<std::endl;
    std::cout<<"================================================================"<<std::endl;

    std::cout<<std::endl;
    std::copy(a_char, a_char+num+1, a_char_org);
    PrintArray(a_char_org, num, "---Original---\na(char)", shift_not_used);
    RecursiveMergeSort(a_char_org, num);
    PrintArray(a_char_org, num, "---After Sorting---\na(char)", shift_not_used);

    std::cout<<std::endl;
    std::copy(a_int, a_int+num+1, a_int_org);
    PrintArray(a_int_org, num, "---Original---\na(int)", shift_not_used);
    RecursiveMergeSort(a_int_org, num);
    PrintArray(a_int_org, num, "---After Sorting---\na(int)", shift_not_used);

    std::cout<<std::endl;
    std::copy(a_float, a_float+num+1, a_float_org);
    PrintArray(a_float_org, num, "---Original---\na(float)", shift_not_used);
    RecursiveMergeSort(a_float_org, num);
    PrintArray(a_float_org, num, "---After Sorting---\na(float)", shift_not_used);

    std::cout<<std::endl;
    std::copy(a_str, a_str+num+1, a_str_org);
    PrintArray(a_str_org, num, "---Original---\na(string)", shift_not_used);
    RecursiveMergeSort(a_str_org, num);
    PrintArray(a_str_org, num, "---After Sorting---\na(string)", shift_not_used);


    std::cout<<std::endl;
    std::cout<<"================================================================="<<std::endl;
    std::cout<<"============================ Heap Sort =========================="<<std::endl;
    std::cout<<"================================================================="<<std::endl;

    std::cout<<std::endl;
    std::copy(a_char, a_char+num+1, a_char_org);
    PrintArray(a_char_org, num, "---Original---\na(char)", shift_not_used);
    HeapSort(a_char_org, num);
    PrintArray(a_char_org, num, "---After Sorting---\na(char)", shift_not_used);

    std::cout<<std::endl;
    std::copy(a_int, a_int+num+1, a_int_org);
    PrintArray(a_int_org, num, "---Original---\na(int)", shift_not_used);
    HeapSort(a_int_org, num);
    PrintArray(a_int_org, num, "---After Sorting---\na(int)", shift_not_used);

    std::cout<<std::endl;
    std::copy(a_float, a_float+num+1, a_float_org);
    PrintArray(a_float_org, num, "---Original---\na(float)", shift_not_used);
    HeapSort(a_float_org, num);
    PrintArray(a_float_org, num, "---After Sorting---\na(float)", shift_not_used);

    std::cout<<std::endl;
    std::copy(a_str, a_str+num+1, a_str_org);
    PrintArray(a_str_org, num, "---Original---\na(string)", shift_not_used);
    HeapSort(a_str_org, num);
    PrintArray(a_str_org, num, "---After Sorting---\na(string)", shift_not_used);


    delete [] a_char            ;
    delete [] a_char_org        ;
    delete [] a_int             ;
    delete [] a_int_org         ;
    delete [] a_float           ;
    delete [] a_float_org       ;
    delete [] a_str             ;
    delete [] a_str_org         ;

    return EXIT_SUCCESS;
}
