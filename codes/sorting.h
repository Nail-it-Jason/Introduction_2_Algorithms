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

inline int lchild(int i) { return 2 * i + 1; }
inline int rchild(int i) { return 2 * i + 2; }
inline int parent(int i) { return (i - 1) / 2; }
void max_heapify(std::vector<int> & A, int i, int n);
void min_heapify(std::vector<int> & A, int i, int n);
void max_heapify_loop(std::vector<int> & A, int i, int n);
void build_max_heap(std::vector<int> & A);
void heap_sort(std::vector<int> & A);

int partition(std::vector<int> & A, int p, int r);
void quick_sort(std::vector<int> & A, int p, int r);
#endif
