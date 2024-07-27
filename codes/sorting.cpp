#include "sorting.h"
// 插入排序
std::vector<int> & insertion_sort(std::vector<int> & s){
    int i = 0, key;
    for(int j = 1; j < s.size(); ++j){
        i = j - 1;
        key = s[j];
        while(i >= 0 && key < s[i]){
            s[i + 1] = s[i];
            i = i - 1;
        }
        s[i + 1] = key;
    }
    return s;
}
//插入排序逆序版，来自习题2.1-2
std::vector<int> & re_insertion_sort(std::vector<int> & s){
    int i = 0, key;
    for(int j = 1; j < s.size(); ++j){
        key = s[j];
        i = j - 1;
        while(i >= 0 && s[i] < key){
            s[i + 1] = s[i];
            i = i - 1;
        }
        s[i + 1] = key;
    }
    return s;
}