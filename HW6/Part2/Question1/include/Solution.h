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

#include <Solution.hpp>
#endif

