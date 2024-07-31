#include "calculation.h"
#include "sorting.h"
//n位二进制数A和B相加，结果用n+1位二进制数C表示
std::vector<int> addition(std::vector<int> &A, std::vector<int> &B, int n){
    std::vector<int> C(n + 1, 0);
    int c = 0;
    for(int i = C.size() - 1; i >= 1; --i){
        C[i] = (c + A[i-1] + B[i-1]) % 2;
        c = (c + A[i-1] + B[i-1]) / 2;
    }
    C[0] = c;
    return C;
}
//秦九韶算法(Horner's)，方便起见都使用整系数x和a_i
int horner(std::vector<int> &A, int x){
    int y = 0;
    for(auto &i : A){
        y = i + x * y;
    }
    return y;
}
//朴素的多项式求值，来自思考题2-3
int naive_poly(std::vector<int> &A, int x){
    int y = 0;
    for(int i = 0; i < A.size(); ++i){
        int temp = 1;
        for(int j = 0; j < i; ++j)
            temp *= x;
        y += (A[i] * temp);
    }
    return y;
}
//参考归并排序的思想，确定一个序列的逆序对的个数，来自思考题2-4
int count_two_arrays(std::vector<int> &A, int p, int q, int r){
    //从p到q是第一部分，从q+1到r是第二部分
    //拷贝
    int n1 = q - p + 1, n2 = r - q;
    std::vector<int> al(n1 + 1);
    std::vector<int> ar(n2 + 1);
    for(int i = 0; i < n1; ++i){
        al[i] = A[p + i];
    }
    for(int j = 0; j < n2; ++j){
        ar[j] = A[q + 1 + j];
    }
    al[n1] = INF;
    ar[n2] = INF;
    //找到所有左边大于右边的, 其中左边和右边是各自已经排好序的，那么只要右边上去了，
    // 就证明右边这个数小于左边现存的所有数，即n1-i+1，
    int count = 0, i = 0, j = 0;
    for(int k = p; k <= r; ++k){
        if(al[i] <= ar[j]){
            A[k] = al[i];
            ++i;
        } else {
            A[k] = ar[j];
            ++j;
            count = count + (n1 - i);
        }
    }
    return count;
}
int count_reverse(std::vector<int> &A, int p, int r){
    if(p < r){
        int q = (p + r) / 2;
        return
        count_reverse(A, p, q) +
        count_reverse(A, q+1, r) +
        count_two_arrays(A, p, q, r);
    }
    return 0;
}
