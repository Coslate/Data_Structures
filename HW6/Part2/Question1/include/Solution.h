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

std::string GenRandomString(const int &len);

template <class T>
void PrintArray(T *a, const int n, const std::string &name, const int shift_not_used);

template <class T>
void InsertionSort(T *a, const int n);

#include <Solution.hpp>
#endif

