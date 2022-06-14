//Solution.hpp
#include <Solution.h>

std::string GenRandomString(const int len) {
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
void PrintArray(T *a, const int n, const std::string name, const int shift_not_used){
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

template <class T>
void QuickSortMedianOfThree(T *a, const int n){
    int left = 1;
    int right = n;
    QuickSortMedianOfThree(a, left, right);
}

template <class T>
void Swap(T &i, T &j){
    T tmp = i;
    i = j;
    j = tmp;
}

template <class T>
T& MedianOfThree(T *a, const int left, const int right){
    int change_pos = 1;
    int mid        = int((left+right)/2);
    T left_val  = a[left];
    T right_val = a[right];
    T mid_val   = a[mid];

    T max_val = std::max({left_val, right_val, mid_val});
    T min_val = std::max({left_val, right_val, mid_val});

    if(left_val != max_val && left_val != min_val){
        change_pos = left;
    }else if(right_val != max_val && right_val != min_val){
        change_pos = right;
    }else{
        change_pos = mid;
    }

    Swap(a[left], a[change_pos]);
    return a[left];
}

template <class T>
void QuickSortMedianOfThree(T *a, const int left, const int right){
    if(left < right){
        int i = left;
        int j = right + 1;

        //T &pivot = a[left];
        T &pivot = MedianOfThree(a, left, right);

        do {
            do j--; while(a[j] > pivot);
            do i++; while(a[i] <= pivot);

            if(i < j) Swap(a[i], a[j]);
        } while(i < j);
        Swap(pivot, a[j]);
        QuickSortMedianOfThree(a, left, j-1);
        QuickSortMedianOfThree(a, j+1, right);
    }
}
