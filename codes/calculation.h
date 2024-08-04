#ifndef CALCULATION_H
#define CALCULATION_H
#include <iostream>
#include <vector>

std::vector<int> addition(std::vector<int> &A, std::vector<int> &B, int n);
int horner(std::vector<int> &A, int x);
int naive_poly(std::vector<int> &A, int x);
int count_two_arrays(std::vector<int> &A, int p, int q, int r);
int count_reverse(std::vector<int> &A, int p, int r);
void find_max_subarray(std::vector<int> & a, int & sum_ans,
                       int & p, int & q, int low, int high);
void find_max_crossing_array(std::vector<int> & a, int & sum_ans,
                             int & p, int & q, int low, int high);
void find_max_subarray_v(std::vector<int> & a, int & sum_ans, int & p, int & q);
void find_max_subarray_i(std::vector<int> & a, int & sum_ans, int & p, int & q);
#endif
