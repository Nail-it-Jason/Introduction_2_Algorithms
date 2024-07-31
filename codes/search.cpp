#include "search.h"
//线性查找
int linear_search(std::vector<int> & s, int v){
    int i = 0;
    while(i < s.size() && s[i++] != v){}
    return i == s.size() ? NIL : i-1;
}
//二分查找迭代
int binary_search_iterate(std::vector<int> & s, int v){
    int p = 0, r = s.size() - 1, q;
    while(p <= r){
        q = (p + r) / 2;
        if(s[q] == v)
            return q;
        else if (s[q] > v)
            r = q - 1;
        else
            p = q + 1;
    }
    return -1;
}
//二分查找递归
int binary_search_recursive(std::vector<int> & s, int v, int p, int r){
    if(p <= r) {
        int q = (p + r) / 2;
        if (s[q] == v)
            return q;
        else if (s[q] > v)
            return binary_search_recursive(s, v, p, q - 1);
        else
            return binary_search_recursive(s, v, q + 1, r);
    }
    else
        return -1;
}
