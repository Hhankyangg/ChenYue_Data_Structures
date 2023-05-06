Given a tree, you are supposed to list all the leaves in the order of top down, and left to right.

### Input Specification:

Each input file contains one test case. For each case, the first line gives a positive integer *N* (≤10) which is the total number of nodes in the tree -- and hence the nodes are numbered from 0 to *N*−1. Then *N* lines follow, each corresponds to a node, and gives the indices of the left and right children of the node. If the child does not exist, a "-" will be put at the position. Any pair of children are separated by a space.

### Output Specification:

For each test case, print in one line all the leaves' indices in the order of top down, and left to right. There must be exactly one space between any adjacent numbers, and no extra space at the end of the line.

### Sample Input:

```in
8
1 -
- -
0 -
2 7
- -
- -
5 -
4 6
```

### Sample Output:

```out
4 1 5
```



````c
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 10
#define Null -1

typedef struct {
	int data;
	int left;
	int right;
} TreeNode;
TreeNode bt[MAXSIZE];	// global variable

int ReadTree(TreeNode* bt);
int LevelTraversalLeaves(int bt_root, int* res);

int main() {
	int i;
	int bt_root = ReadTree(bt);
	int res[MAXSIZE];
	int cnt = LevelTraversalLeaves(bt_root, res);
	for (i=0; i<cnt-1; i++) {
		printf("%d ", res[i]);
	}
	printf("%d", res[i]);
	
	return 0;
}

int ReadTree(TreeNode* bt) {
	int root = Null;
	int n, i;
	char c_left, c_right;
	scanf("%d", &n);
	int* check = (int*)malloc(n*sizeof(int));	// to check which is root
	for (i=0; i<n; i++) {
		check[i] = 0;
	}
	if (n) {
		for (i=0; i<n; i++) {
			bt[i].data = i;
			scanf("\n%c %c", &c_left, &c_right);
			// left
			if (c_left != '-') {
				bt[i].left = c_left-'0';
				check[c_left-'0'] = 1;
			}
			else {
				bt[i].left = Null;
			}
			// right
			if (c_right != '-') {
				bt[i].right = c_right-'0';
				check[c_right-'0'] = 1;
			}
			else {
				bt[i].right = Null;
			}
		}
		for (i=0; i<n; i++) {
			if(check[i] == 0) {
				root = i;
				break;
			}
		}
	}
	free(check);
	return root;
}

int LevelTraversalLeaves(int bt_root, int* res) {
	int cnt = 0;	// num of leaves
	int queue[MAXSIZE+1];	// create a queue for level_order_traversal
	int front = 0, rear = 0;
	if (bt_root == Null) {
		return cnt;
	}
	queue[front] = bt[bt_root].data;
	rear = 1;
	while (front != rear) {
		// queue delete
		if (bt[queue[front]].left==Null && bt[queue[front]].right==Null) {
			res[cnt] = queue[front];
			cnt ++;
		}
		// add if exits
		if (bt[queue[front]].left != Null) {
			queue[rear] = bt[bt[queue[front]].left].data;
			rear ++;
		}
		if (bt[queue[front]].right != Null) {
			queue[rear] = bt[bt[queue[front]].right].data;
			rear ++;
		}
		front ++;
	}
	return cnt;
}

````

