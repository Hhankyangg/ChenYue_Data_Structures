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