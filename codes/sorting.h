#ifndef SORTING_H
#define SORTING_H
#include <iostream>
#include <vector>
#define INF 100000
std::vector<int> & insertion_sort(std::vector<int> & s);
std::vector<int> & re_insertion_sort(std::vector<int> & s);
std::vector<int> & selection_sort(std::vector<int> &s);
std::vector<int> & merge(std::vector<int> & a, int p, int q, int r);
std::vector<int> & merge_(std::vector<int> & a, int p, int q, int r);
std::vector<int> & merge_sort(std::vector<int> &a, int p, int r);
std::vector<int> & bubble_sort(std::vector<int> & s);
#endif
