#include "misc.h"
#include "search.h"
//来自习题2.3-7 n个整数集合S，整数x，找出两个数，他们的和为x
void find_two_num(std::vector<int> S, int x, int & a, int & b){
    for(int i = 0; i < S.size(); ++i){
        a = i;
        if((b = binary_search_iterate(S, x - S[a])) >= 0) return;
    }
    a = -1;
    b = -1;
    return;
}