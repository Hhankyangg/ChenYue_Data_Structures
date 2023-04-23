// 数组元素循环右移问题
// 分数 20
// 作者 DS课程组
// 单位 浙江大学
// 一个数组A中存有N（>0）个整数，在不允许使用另外数组的前提下，将每个整数循环向右移M（≥0）个位置（最后M个数循环移至最前面的M个位置）。
// 如果需要考虑程序移动数据的次数尽量少，要如何设计移动的方法？

// 输入格式:
// 每个输入包含一个测试用例，第1行输入N（1≤N≤100）和M（≥0）；第2行输入N个整数，之间用空格分隔。

// 输出格式:
// 在一行中输出循环右移M位以后的整数序列，之间用空格分隔，序列结尾不能有多余空格。

// 输入样例:
// 6 2
// 1 2 3 4 5 6
// 输出样例:
// 5 6 1 2 3 4
// 代码长度限制
// 16 KB
// 时间限制
// 400 ms
// 内存限制
// 64 MB


#include <stdio.h>
#include <stdlib.h>

// 2023/4/23 碎碎念: 当时好像不知道 linked list 呃呃(其实也就10天前吧呃呃)

int main() {
    // create and initialize the array
    int n, m;
    scanf("%d %d", &n, &m);
    int *arr = (int*)malloc(n*sizeof(int));
    int i;
    for (i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }
    // move for m steps
    int j;
    for (i=0; i<m; i++) {
        int tmp = arr[n-1];
        for (j=n-1; j>0; j--) {
            arr[j] = arr[j-1]; 
        }
        arr[0] = tmp;
    }
    // printf
    for (i=0; i<n-1; i++) {
        printf("%d ", arr[i]);
    }
    printf("%d", arr[i]);
    

return 0;
}