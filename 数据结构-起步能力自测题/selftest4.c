// Have Fun with Numbers
// 分数 20
// 作者 陈越
// 单位 浙江大学
// Notice that the number 123456789 is a 9-digit number consisting exactly the numbers from 1 to 9, with no duplication. 
// Double it we will obtain 246913578, which happens to be another 9-digit number consisting exactly the numbers from 1 to 9, only in a different permutation. 
// Check to see the result if we double it again!

// Now you are suppose to check if there are more numbers with this property. 
// That is, double a given number with k digits, you are to tell if the resulting number consists of only a permutation of the digits in the original number.

// Input Specification:
// Each input contains one test case. Each case contains one positive integer with no more than 20 digits.

// Output Specification:
// For each test case, first print in a line "Yes" if doubling the input number gives a number that consists of only a permutation of the digits in the original number, or "No" if not. 
// Then in the next line, print the doubled number.

// Sample Input:
// 1234567899
// Sample Output:
// Yes
// 2469135798
// 代码长度限制
// 16 KB
// 时间限制
// 400 ms
// 内存限制
// 64 MB


#include <stdio.h>
#include <string.h>

int main() {
    // scanf the num
    char num[21];
    scanf("%s", &num);
    // store each digits in the array digits
    int len = strlen(num);
    // create an array to store the freq of each digit
    int freq[9] = {0};
    int i;
    for (i=0; i<len; i++) {
        switch (num[i]) {
            case '0':
                freq[0] ++;
                break;
            case '1':
                freq[1] ++;
                break;
            case '2':
                freq[2] ++;
                break;
            case '3':
                freq[3] ++;
                break;
            case '4':
                freq[4] ++;
                break;
            case '5':
                freq[5] ++;
                break;
            case '6':
                freq[6] ++;
                break;
            case '7':
                freq[7] ++;
                break;
            case '8':
                freq[8] ++;
                break;            
            default:
                freq[9] ++;
                break;
        }
    }
    // double the num
    int carry = 0;
    char double_num[22];
        // initialize the double_num
    for (i=0; i<21; i++) {
        double_num[i] = '0';
    }
    double_num[21] = '\0';
    for (i=len-1; i>=0; i--) {
        double_num[i+1] += (num[i]-'0')*2 % 10;
        double_num[i] += (num[i]-'0')*2 / 10;
        if (i == 0) {
            if (double_num[0] != '0') {
                carry = 1;
            }
        }
    }
    // check
    if (carry == 1) {
        len = strlen(num)+1;
        printf("No\n");
        for (i=0; i<len; i++) {
            printf("%c", double_num[i]);
        }
    }
    else {
        for (i=1; i<len+1; i++) {
            switch (double_num[i]) {
                case '0':
                    freq[0] --;
                    break;
                case '1':
                    freq[1] --;
                    break;
                case '2':
                    freq[2] --;
                    break;
                case '3':
                    freq[3] --;
                    break;
                case '4':
                    freq[4] --;
                    break;
                case '5':
                    freq[5] --;
                    break;
                case '6':
                    freq[6] --;
                    break;
                case '7':
                    freq[7] --;
                    break;
                case '8':
                    freq[8] --;
                    break;            
                case '9':
                    freq[9] --;
                    break;
            }
        }
    // judge
        int res = 1;
        for (i=0; i<10; i++) {
            if (freq[i] != 0) {
                res = 0;
                break;
            }
        }
    // print
        if (res == 1) {
            printf("Yes\n");
        }
        else {
            printf("No\n");
        }
        for (i=1; i<len+1; i++) {
            printf("%c", double_num[i]);
        }
    }
    
    return 0;
}