#ifndef SEARCH_H
#define SEARCH_H
#include <iostream>
#include <vector>
#define NIL -1 //找不到返回的下标
int linear_search(std::vector<int> & s, int v);
int binary_search_iterate(std::vector<int> & s, int v);
int binary_search_recursive(std::vector<int> & s, int v, int p, int r);

#endif
