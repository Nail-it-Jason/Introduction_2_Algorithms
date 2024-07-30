#include <iostream>
#include <vector>
#include "sorting.h"
#include "search.h"
#include "calculation.h"
int main() {
    std::vector<int> A = {1, 5, 2, 6, 3, 12, 7, 8, 4};
    merge_sort(A, 0, A.size()-1);
    for(auto &i : A) {
        std::cout << i << " ";
    }
    return 0;
}
