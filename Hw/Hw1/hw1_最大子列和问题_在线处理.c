#include <stdio.h>
#include <stdlib.h>

int MaxSubseqSum4(int List[], int len) {
    int max_sum=0, sum=0;
    int i;

    for (i=0; i<len; i++) {
        sum += List[i];     // accumulate to the right
        if (sum > max_sum) {
            max_sum = sum;  // update the max_sum
        }
        if (sum < 0) {      // if the sum < 0 at this time, 
            sum = 0;        // then it will have no benefit to increase the sum then 
        }                   // therefore, turn the sum to zero
    }
    return max_sum;
}

int main() {
    int n;  // size of the array
    int i;
    scanf("%d", &n);
    int* p_list = (int*)malloc(sizeof(int)*n);
    for (i=0; i<n; i++) {
        scanf("%d", &p_list[i]);
    }
    printf("%d", MaxSubseqSum4(p_list, n));
    return 0;
}