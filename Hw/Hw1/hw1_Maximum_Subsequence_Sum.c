// Given a sequence of K integers{N1 , N2 , ..., NK}.A continuous subsequence is defined to be{Ni, Ni+1, ..., Nj }.
// where 1≤i≤j≤K. The Maximum Subsequence is the continuous subsequence which has the largest sum of its elements. 
// For example, given sequence { -2, 11, -4, 13, -5, -2 }, its maximum subsequence is { 11, -4, 13 } with the largest sum being 20.

// Now you are supposed to find the largest sum, together with the first and the last numbers of the maximum subsequence.

// Input Specification:
// Each input file contains one test case. Each case occupies two lines. The first line contains a positive integer K (≤10000). 
// The second line contains K numbers, separated by a space.

// Output Specification:
// For each test case, output in one line the largest sum, together with the first and the last numbers of the maximum subsequence. 
// The numbers must be separated by one space, but there must be no extra space at the end of a line. 
// In case that the maximum subsequence is not unique, output the one with the smallest indices i and j (as shown by the sample case). 
//If all the K numbers are negative, then its maximum sum is defined to be 0, and you are supposed to output the first and the last numbers of the whole sequence.

// Sample Input:
// 10
// -10 1 2 3 4 -5 -23 3 7 -21
// Sample Output:
// 10 1 4


#include <stdio.h>
#include <stdlib.h>

int main() {
	int n;	// size of the array
	int i;
	int this_sum = 0, max_sum = -1;	// define max_sum = 1 in case that the data is full of 0 and neg
	int cnt_neg = 0;				// to judge if all nums are neg
	// create the array
	scanf("%d", &n);
	int* p_list = (int*)malloc(sizeof(int)*n);
	// find
	int beg, end;
	int tmp = 0;
	for (i=0; i<n; i++) {
		scanf("%d", &p_list[i]);	// input elements
		if (p_list[i] < 0) {
			cnt_neg ++;
		}
		this_sum += p_list[i];
		if (this_sum > max_sum) {	// judge while inputting
			max_sum = this_sum;
			end = i;				// smallest end index can be found easily
			beg = tmp;				
		}
		else if (this_sum < 0) {
			this_sum = 0;
			tmp = i + 1;			// next one may be the true beg	
		}
	}
	// printf
    if (cnt_neg == n) {
        printf("0 %d %d", p_list[0], p_list[n-1]);
    }
	else {
        printf("%d %d %d", max_sum, p_list[beg], p_list[end]);
    }
    return 0;
}