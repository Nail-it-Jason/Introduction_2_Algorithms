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

// 找到和最大的子数组
void find_max_crossing_array(std::vector<int> & a, int & sum_ans,
                             int & p, int & q, int low, int high){
    int mid = (high + low) / 2;
    int left_sum = -INF;
    int sum = 0;
    for(int i = mid; i >= low; --i){
        sum += a[i];
        if(sum > left_sum){
            left_sum = sum;
            p = i;
        }
    }

    int right_sum = -INF;
    sum = 0;
    for(int j = mid + 1; j <= high; ++j){
        sum += a[j];
        if(sum > right_sum){
            right_sum = sum;
            q = j;
        }
    }
    sum_ans = right_sum + left_sum;
}

void find_max_subarray(std::vector<int> & a, int & sum_ans,
                       int & p, int & q, int low, int high){
    if(low == high){
        sum_ans = a[low];
        p = low;
        q = high;
    }
    else{
        int mid = (high + low) / 2;
        int left_low, left_high, left_sum,
        right_low, right_high, right_sum,
        cross_low, cross_high, cross_sum;
        find_max_crossing_array(a, cross_sum, cross_low, cross_high, low, high);
        find_max_subarray(a, left_sum, left_low, left_high, low, mid);
        find_max_subarray(a, right_sum, right_low, right_high, mid + 1, high);
        if(left_sum >= right_sum && left_sum >= cross_sum){
            sum_ans = left_sum;
            p = left_low;
            q = left_high;
        }
        else if(right_sum >= left_sum && right_sum >= cross_sum){
            sum_ans = right_sum;
            p = right_low;
            q = right_high;
        }
        else{
            sum_ans = cross_sum;
            p = cross_low;
            q = cross_high;
        }
    }
}

// 找和最大的子数组，但是暴力求解，来自习题4.1-2
void find_max_subarray_v(std::vector<int> & a, int & sum_ans, int & p, int & q){
    int sum = 0, max_sum = -INF, all_max_sum = -INF, temp = 0;
    for(int i = 0; i < a.size(); ++i){
        sum = 0;
        for(int j = i; j < a.size(); ++j){
            sum += a[j];
            if(sum > max_sum){
                max_sum = sum;
                temp = j;
            }
        }
        if(max_sum > all_max_sum){
            all_max_sum = max_sum;
            p = i;
            q = temp;
        }
    }
    sum_ans = all_max_sum;
}

//非递归的线性算法
void find_max_subarray_i(std::vector<int> & a, int & sum_ans, int & p, int & q) {
    int max_sum = -INF, sum = -INF, currentHigh = 0, currentLow = 0,
    High = 0, Low = 0;
    for(int j = 0; j < a.size(); ++j){
        currentHigh = j;
        if(sum > 0)
            sum += a[j];
        else{
            currentLow = j;
            sum = a[j];
        }
        if(sum > max_sum){
            max_sum = sum;
            Low = currentLow;
            High = currentHigh;
        }
    }
    sum_ans = max_sum;
    p = Low;
    q = High;
}