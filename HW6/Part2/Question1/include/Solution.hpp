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
void Swap(T &i, T &j){
    T tmp = i;
    i = j;
    j = tmp;
}

template <class T>
void QuickSortMedianOfThree(T *a, const int n){
    int left = 1;
    int right = n;
    QuickSortMedianOfThree(a, left, right);
}

template <class T>
T& MedianOfThree(T *a, const int left, const int right){
    int change_pos = 1;
    int mid        = int((left+right)/2);
    T left_val  = a[left];
    T right_val = a[right];
    T mid_val   = a[mid];

    T max_val = std::max({left_val, right_val, mid_val});
    T min_val = std::min({left_val, right_val, mid_val});

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
            do i++; while(a[i] <= pivot && i<right);

            if(i < j) Swap(a[i], a[j]);
        } while(i < j);
        Swap(pivot, a[j]);
        QuickSortMedianOfThree(a, left, j-1);
        QuickSortMedianOfThree(a, j+1, right);
    }
}

template <class T>
void Merge(T *a, T *b, const int k, const int m, const int n){
    int i1=k, i2=m+1, i3=k;

    for(; i1<=m && i2<=n; i3++){
        if(a[i1] <= a[i2]){
            b[i3] = a[i1];
            i1++;
        }else{
            b[i3] = a[i2];
            i2++;
        }
    }

    if(i2 > n) std::copy(a+i1, a+m+1, b+i3);
    if(i1 > m) std::copy(a+i2, a+n+1, b+i3);
}

template <class T>
void MergePass(T *a, T *b, const int n, const int s){
    int i=1;
    for(; i<=n-(2*s)+1; i+=2*s){
        Merge(a, b, i, i+s-1, i+(2*s)-1);
    }

    //merge the remaining lists of size < 2*s
    if((i+s-1) < n){//one full and one partial lists
        Merge(a, b, i, i+s-1, n);
    }else{//only one partial lists remained
        std::copy(a+i, a+n+1, b+i);
    }
}

template <class T>
void IterativeMergeSort(T *a, const int n){
    T *tmp_list = new T[n+1];

    for(int s=1; s<n; s*=2){
        MergePass(a, tmp_list, n, s);
        s*=2;
        MergePass(tmp_list, a, n, s);
    }

    delete [] tmp_list;
}

template <class T>
void RecursiveMergeSort(T *a, const int n){
    int *link  = new int [n+1](); //store index of a[] in order
    T   *a_tmp = new T [n+1](); //store index of a[] in order
    int left = 1;
    int right = n;
    int curr_link = 0;
    int curr_pos  = 1;

    RecursiveMergeSort(a, link, left, right);

    //re-arrange a[] according to link
    std::copy(a, a+n+1, a_tmp);

    while(1){
        a[curr_pos] = a_tmp[link[curr_link]];
        curr_link = link[curr_link];
        curr_pos++;

        if(link[curr_link] == 0) break;
    }
}

template <class T>
int RecursiveMergeSort(T *a, int *link, const int left, const int right){
    if(left >= right) return left; //base case
    int mid = (left + right)/2;
    return ListMerge(a, link, RecursiveMergeSort(a, link, left, mid), RecursiveMergeSort(a, link, mid+1, right));
}

template <class T>
int ListMerge(T *a, int *link, const int start1, const int start2){
    int i_result = 0;//the last record of the resulted link
    int i1 = start1, i2 = start2;

    for(; i1 && i2 ;){
        if(a[i1] <= a[i2]){
            link[i_result] = i1;
            i_result = i1;
            i1 = link[i1];
        }else{
            link[i_result] = i2;
            i_result = i2;
            i2 = link[i2];
        }
    }

    if(i1 == 0){
        link[i_result] = i2;
    }else{
        link[i_result] = i1;
    }

    return link[0];
}

template <class T>
void Adjust(T *a, const int root, const int n){//heap down from root to n
    T e = a[root];

    int j = 2*root;
    for(; j<=n; j*=2){
        if((j<n) && (a[j]<a[j+1])){ //compare between j & j+1
            j++; //make j the max child
        }

        if(e >= a[j]) break; //find the destination

        a[j/2] = a[j]; //move jth record up the path
    }
    a[j/2] = e;
}

template <class T>
void HeapSort(T *a, const int n){
    for(int i=n/2; i>=1; i--){//heap initialization
        Adjust(a, i, n); //heapify begin from i to n
    }

    for(int i=n-1; i>=1; i--){
        Swap(a[1], a[i+1]);//remove from the root
        Adjust(a, 1, i);//heapify after removing max from the heap
    }
}








