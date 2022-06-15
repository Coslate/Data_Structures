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

std::string GenRandomString(const int len);

template <class T>
void PrintArray(T *a, const int n, const std::string name, const int shift_not_used);

template <class T>
void InsertionSort(T *a, const int n);

template <class T>
void QuickSortMedianOfThree(T *a, const int n);

template <class T>
void QuickSortMedianOfThree(T *a, const int left, const int right);

template <class T>
void Swap(T &i, T &j);

template <class T>
T& MedianOfThree(T *a, const int left, const int right);

template <class T>
void IterativeMergeSort(T *a, const int n);

template <class T>
void MergePass(T *a, T *b, const int n, const int s);

template <class T>
void Merge(T *a, T *b, const int k, const int m, const int n);

template <class T>
void RecursiveMergeSort(T *a, const int n);

template <class T>
int RecursiveMergeSort(T *a, int *link, const int left, const int right);

template <class T>
int ListMerge(T *a, int *link, const int left, const int right);

template <class T>
void Adjust(T *a, const int root, const int n);

template <class T>
void HeapSort(T *a, const int n);

#include <Solution.hpp>
#endif

