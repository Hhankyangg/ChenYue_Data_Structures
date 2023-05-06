Given a constant *K* and a singly linked list *L*, you are supposed to reverse the links of every *K* elements on *L*. For example, given *L* being 1→2→3→4→5→6, if *K*=3, then you must output 3→2→1→6→5→4; if *K*=4, you must output 4→3→2→1→5→6.

### Input Specification:

Each input file contains one test case. For each case, the first line contains the address of the first node, a positive *N* (≤105) which is the total number of nodes, and a positive *K* (≤*N*) which is the length of the sublist to be reversed. The address of a node is a 5-digit nonnegative integer, and NULL is represented by -1.

Then *N* lines follow, each describes a node in the format:

```
Address Data Next
```

where `Address` is the position of the node, `Data` is an integer, and `Next` is the position of the next node.

### Output Specification:

For each case, output the resulting ordered linked list. Each node occupies a line, and is printed in the same format as in the input.

### Sample Input:

```in
00100 6 4
00000 4 99999
00100 1 12309
68237 6 -1
33218 3 00000
99999 5 68237
12309 2 33218
```

### Sample Output:

```out
00000 4 33218
33218 3 12309
12309 2 00100
00100 1 99999
99999 5 68237
68237 6 -1
```



````c
#include <stdio.h>
#include <stdlib.h>
// 将数组的下标看作 “地址” 

typedef struct {    
    int value;
    int next;
} Node;

int main() {
    Node addr[100000];
    // scan the basic info
    int head, n, k;
    scanf("%d %d %d", &head, &n, &k);
    // scan the data
    int i = n;
    while (i--) {
        int tmp;
        scanf("%d", &tmp);
        scanf("%d %d", &addr[tmp].value, &addr[tmp].next);
    }
    // reverse
    int tail = head, cnt = 1;
    int* last_section = &head;
    for (; tail!=-1; cnt++, tail = addr[tail].next) {
        if (cnt % k == 0) { // it's time to reverse
            int beg = *last_section;

            int backward, forward;
            for (i=beg, backward=addr[tail].next; backward!=tail; i=forward) {
                forward = addr[i].next;
                addr[i].next = backward;
                backward = i;
            }
    
            *last_section = tail;
            tail = beg;
            last_section = &addr[beg].next;
        }
    }
    // print
    for (i=head; i!=-1; i=addr[i].next) {
        printf("%05d %d ", i, addr[i].value);
        printf(addr[i].next==-1 ? "%d\n" : "%05d\n", addr[i].next);
    }
}
````