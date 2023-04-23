// 素数对猜想
// 分数 20
// 作者 陈越
// 单位 浙江大学
// “素数对猜想”认为“存在无穷多对相邻且差为2的素数”。

// 现给定任意正整数N(<10^5)
// 请计算不超过N的满足猜想的素数对的个数。

// 输入格式:
// 输入在一行给出正整数N。

// 输出格式:
// 在一行中输出不超过N的满足猜想的素数对的个数。

// 输入样例:
// 20
// 输出样例:
// 4
// 代码长度限制
// 16 KB
// 时间限制
// 400 ms
// 内存限制
// 64 MB


#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int isPrime(int a) {
    int isprime = 1;
    int i;
    for (i=2; i<sqrt(a)+1; i++) {
        if (a%i == 0) {
            isprime = 0;
            break;
        }
    }
    return isprime;
}

int main() {
    //input the upper
    int upper;
    scanf("%d", &upper);
    // create primelist
    int *primelist = (int*)malloc(upper*sizeof(int));
    int cnt = 0, i;
    for (i=2; i<=upper; i++) {
        if (isPrime(i)) {
            primelist[cnt] = i;
            cnt ++;
        }
    }
    cnt ++;
    // judge the primes
    int cnt_final = 0;
    for(i=0; i<cnt-1; i++) {
        if(primelist[i+1]-primelist[i] == 2) {
            cnt_final ++;
        }
    }
    //printf
    printf("%d", cnt_final);
    
    return 0;
}