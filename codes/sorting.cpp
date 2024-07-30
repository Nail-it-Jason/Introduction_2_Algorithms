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
//选择排序
std::vector<int> & selection_sort(std::vector<int> &s){
    int i = 0, j = 0, min = 0;
    for(i = 0; i < s.size() - 1; ++i){
        min = i;
        for(j = i + 1; j < s.size(); ++j){
            if(s[j] < s[min]) min = j;
        }
        std::swap(s[i], s[min]);
    }
    return s;
}
//归并排序
std::vector<int> & merge(std::vector<int> & a, int p, int q, int r){
    //分为p到q，q+1到r
    int n1 = q - p + 1;
    int n2 = r - q;
    //开两个数组然后拷贝
    std::vector<int> al(n1 + 1);
    std::vector<int> ar(n2 + 1);
    for(int i = 0; i < n1; ++i)
        al[i] = a[p + i];
    for(int j = 0; j < n2; ++j)
        ar[j] = a[q + 1 + j];
    al[n1] = INF;
    ar[n2] = INF;
    //按顺序排到原位
    int i = 0, j = 0;
    for(int k = p; k <= r; ++k){
        if(al[i] <= ar[j]) {
            a[k] = al[i];
            ++i;
        }
        else{
            a[k] = ar[j];
            ++j;
        }
    }
    return a;
}
std::vector<int> & merge_sort(std::vector<int> &a, int p, int r){
    if(p < r){
        int q = (p + r) / 2;
        merge_sort(a, p, q);
        merge_sort(a, q + 1, r);
        merge(a, p, q, r);
    }
    return a;
}
//归并排序，但是不使用哨兵，来自练习2.3-2
std::vector<int> & merge_(std::vector<int> & a, int p, int q, int r){
    int n1 = q - p + 1;
    int n2 = r - q;
    std::vector<int> al(n1);
    std::vector<int> ar(n2);
    for(int i = 0; i < n1; ++i)
        al[i] = a[p + i];
    for(int j = 0; j < n2; ++j)
        ar[j] = a[q + 1 + j];
    int i = 0, j = 0, k = p;
    while(i < al.size() && j < ar.size()){
        a[k++] = (al[i] <= ar[j] ? al[i++] : ar[j++]);
    }
    while(i < al.size())
        a[k++] = al[i++];
    while(j < ar.size())
        a[k++] = ar[j++];
    return a;
}