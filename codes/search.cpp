#include "search.h"
//线性查找
int linear_search(std::vector<int> & s, int v){
    int i = 0;
    while(i < s.size() && s[i++] != v){}
    return i == s.size() ? NIL : i-1;
}
