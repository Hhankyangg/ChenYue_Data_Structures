让我们定义*d**n*为：*d**n*=*p**n*+1−*p**n*，其中*p**i*是第*i*个素数。显然有*d*1=1，且对于*n*>1有*d**n*是偶数。“素数对猜想”认为“存在无穷多对相邻且差为2的素数”。

现给定任意正整数`N`(<105)，请计算不超过`N`的满足猜想的素数对的个数。

### 输入格式:

输入在一行给出正整数`N`。

### 输出格式:

在一行中输出不超过`N`的满足猜想的素数对的个数。

### 输入样例:

```in
20
```

### 输出样例:

```out
4
```



````c
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
````



