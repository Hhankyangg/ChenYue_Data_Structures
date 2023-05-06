给定*K*个整数组成的序列{ *N*1, *N*2, ..., *N**K* }，“连续子列”被定义为{ *N**i*, *N**i*+1, ..., *N**j* }，其中 1≤*i*≤*j*≤*K*。“最大子列和”则被定义为所有连续子列元素的和中最大者。例如给定序列{ -2, 11, -4, 13, -5, -2 }，其连续子列{ 11, -4, 13 }有最大的和20。现要求你编写程序，计算给定整数序列的最大子列和。

本题旨在测试各种不同的算法在各种数据情况下的表现。各组测试数据特点如下：

- 数据1：与样例等价，测试基本正确性；
- 数据2：102个随机整数；
- 数据3：103个随机整数；
- 数据4：104个随机整数；
- 数据5：105个随机整数；

### 输入格式:

输入第1行给出正整数*K* (≤100000)；第2行给出*K*个整数，其间以空格分隔。

### 输出格式:

在一行中输出最大子列和。如果序列中所有整数皆为负数，则输出0。

### 输入样例:

```in
6
-2 11 -4 13 -5 -2
```

### 输出样例:

```out
20
```



````c
#include <stdio.h>
#include <stdlib.h>

int Max3( int A, int B, int C );
int DivideAndConquer(int List[], int left, int right);
int MaxSubseqSum3(int List[], int N);

int main() {
    int n;  // size of the array
    int i;
    scanf("%d", &n);
    int* p_list = (int*)malloc(sizeof(int)*n);
    for (i=0; i<n; i++) {
        scanf("%d", &p_list[i]);
    }
    printf("%d", MaxSubseqSum3(p_list, n));
    return 0;
}

int Max3( int A, int B, int C ) {       // return the max_num of 3 nums
    return A > B ? (A > C ? A : C) : (B > C ? B : C);
}

int DivideAndConquer(int List[], int left, int right) {   // use Divide and Conquer
    int max_sum_left, max_sum_right ;    // store the max_sum of left nums and the max_num of right nums
    int sum_left, sum_right;             // store the sum of left and right nums
    int max_border_sum_left, max_border_sum_right, max_border_sum;  
    // store the max_sum out_of_border   // it must be divided into the left part and the right part
    int border_sum;                      // store the sum out_of_border
    int i, center;
    
    if (left == right) {                // divide until it has only one element between left and right
        if (List[left] > 0) {
            return List[left];
        }
        else {
            return 0;
        }
    }
    center = (right+left) / 2;
    max_sum_left = DivideAndConquer(List, left, center);
    max_sum_right = DivideAndConquer(List, center+1, right);

    // calculate the sum out_of_border
    max_border_sum_left = 0;
    border_sum = 0;
    for (i=center; i>=left; i--) {      // scan from center to left
        border_sum += List[i];
        if (border_sum > max_border_sum_left) {
            max_border_sum_left = border_sum;
        }
    }
    border_sum = 0;     // must be reset to 0
    max_border_sum_right = 0;
    for (i=center+1; i<=right; i++) {   // scan from center to right
        border_sum += List[i];
        if (border_sum > max_border_sum_right) {
            max_border_sum_right = border_sum;
        }
    }
    max_border_sum = max_border_sum_left + max_border_sum_right;

    return Max3(max_sum_right, max_sum_left, max_border_sum);
}

int MaxSubseqSum3(int List[], int N) {
    return DivideAndConquer(List, 0, N-1);
}
````

