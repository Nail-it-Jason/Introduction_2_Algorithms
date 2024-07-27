#include "calculation.h"
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