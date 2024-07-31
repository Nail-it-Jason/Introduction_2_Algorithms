#ifndef CALCULATION_H
#define CALCULATION_H
#include <iostream>
#include <vector>

std::vector<int> addition(std::vector<int> &A, std::vector<int> &B, int n);
int horner(std::vector<int> &A, int x);
int naive_poly(std::vector<int> &A, int x);
int count_two_arrays(std::vector<int> &A, int p, int q, int r);
int count_reverse(std::vector<int> &A, int p, int r);
#endif
