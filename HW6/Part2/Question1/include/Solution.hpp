//Solution.hpp
#include <Solution.h>

std::string GenRandomString(const int &len) {
    static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
    std::string tmp_s;
    tmp_s.reserve(len);

    for (int i = 0; i < len; ++i) {
        tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];
    }

    return tmp_s;
}

template <class T>
void PrintArray(T *a, const int n, const std::string &name, const int shift_not_used){
    for(int i=0+shift_not_used;i<n+shift_not_used;++i){
        if(i==0+shift_not_used){
            std::cout<<name<<" = ["<<a[i]<<" ";
        }else if(i==n-1+shift_not_used){
            std::cout<<a[i]<<"]"<<std::endl;
        }else{
            std::cout<<a[i]<<" ";
        }
    }
}

template <class T>
void InsertionSort(T *a, const int n){
    for(int j=2; j<=n; ++j){
        a[0] = a[j];

        int i = j-1;
        for(; a[i]>a[0]; --i){
            a[i+1] = a[i];
        }
        a[i+1] = a[0];
    }
}


