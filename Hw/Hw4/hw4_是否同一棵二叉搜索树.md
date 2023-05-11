给定一个插入序列就可以唯一确定一棵二叉搜索树。然而，一棵给定的二叉搜索树却可以由多种不同的插入序列得到。例如分别按照序列{2, 1, 3}和{2, 3, 1}插入初始为空的二叉搜索树，都得到一样的结果。于是对于输入的各种插入序列，你需要判断它们是否能生成一样的二叉搜索树。

### 输入格式:

输入包含若干组测试数据。每组数据的第1行给出两个正整数*N* (≤10)和*L*，分别是每个序列插入元素的个数和需要检查的序列个数。第2行给出*N*个以空格分隔的正整数，作为初始插入序列。随后*L*行，每行给出*N*个插入的元素，属于*L*个需要检查的序列。

简单起见，我们保证每个插入序列都是1到*N*的一个排列。当读到*N*为0时，标志输入结束，这组数据不要处理。

### 输出格式:

对每一组需要检查的序列，如果其生成的二叉搜索树跟对应的初始序列生成的一样，输出“Yes”，否则输出“No”。

### 输入样例:

```in
4 2
3 1 4 2
3 4 1 2
3 2 4 1
2 1
2 1
1 2
0
```

### 输出样例:

```out
Yes
No
No
```



````c
// 第一版代码, 丑陋繁琐
#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
    int data;
    struct _Node* left; 
    struct _Node* right;
} TreeNode;
typedef TreeNode* BinTree;
typedef struct {
    TreeNode* queue;
    int front;
    int rear;
} Queue;

BinTree insert( BinTree BST, int X );
int solve( BinTree origin_tree, BinTree judge_tree, int n );
void add_q( Queue* q, TreeNode x );
int is_empty( Queue* q );
TreeNode del_q( Queue* q );

int main() {
    int n, l, i, val;
    scanf("%d", &n);
    while ( n ) {
        BinTree origin_tree = 0;
        scanf("%d", &l);
        for ( i=0; i<n; i++ ) { // create origin tree
            scanf("%d", &val);
            origin_tree = insert( origin_tree, val );
        }
        while ( l-- ) {         // judge
            BinTree judge_tree = 0;
            for ( i=0; i<n; i++ ) {
                scanf("%d", &val);
                judge_tree = insert( judge_tree, val );
            }
            solve( origin_tree, judge_tree, n ) ? printf("Yes\n") : printf("No\n");
        }
        scanf("%d", &n);
    }
    return 0;
}

BinTree insert( BinTree BST, int X ) {
    BinTree tmp;
    if ( !BST ) {
        tmp = (BinTree)malloc(sizeof(TreeNode));
        tmp->data = X;
        tmp->left = tmp->right = 0;
        return tmp;
    }
    else {
        if ( X > BST->data ) {
            BST->right = insert( BST->right, X );
        }
        else if ( X < BST->data ) {
            BST->left = insert( BST->left, X );
        }
    }
    return BST;
}

int solve( BinTree origin_tree, BinTree judge_tree, int n ) {
    int res = 1;
    Queue queue1, queue2;
    queue1.queue = (BinTree)malloc(n * sizeof(TreeNode));
    queue2.queue = (BinTree)malloc(n * sizeof(TreeNode));
    queue1.front = queue1.rear = queue2.front = queue2.rear = -1;
    if ( !origin_tree && !judge_tree ) {    // both are empty
        res = 1;
    }
    else if ( (!origin_tree && judge_tree) || (origin_tree && !judge_tree) ) {
        res = 0;    // one is empty and the other is not
    }
    else {
        add_q( &queue1, *origin_tree );
        add_q( &queue2, *judge_tree );
        while ( !is_empty(&queue1) || !is_empty(&queue2) ) {
            TreeNode t1, t2;
            t1 = del_q(&queue1);
            t2 = del_q(&queue2);
            if ( t1.data != t2.data ) {
                res = 0;
                break;
            }
            if ( t1.left ) {
                add_q( &queue1, *(t1.left) );
            }
            if ( t2.left ) {
                add_q( &queue2, *(t2.left) );
            }     
            if ( t1.right ) {
                add_q( &queue1, *(t1.right) );
            }      
            if ( t2.right ) {
                add_q( &queue2, *(t2.right) );
            }
        }
    }
    return res;
}

void add_q( Queue* q, TreeNode x ) {
    q->rear ++;
    q->queue[q->rear] = x;
}

int is_empty( Queue* q ) {
    int res = 0;
    if ( q->front == q->rear ) {
        res = 1;
    }
    return res;
}

TreeNode del_q( Queue* q ) {
    TreeNode error;
    error.data = -1;
    if (!is_empty( q )) {
        q->front ++;
        return q->queue[q->front];
    }
    return error;
}
````



````c
// 第二版代码, 利用递归比较
#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
    int data;
    struct _Node* left; 
    struct _Node* right;
} TreeNode;
typedef TreeNode* BinTree;

BinTree insert( BinTree BST, int X );
int solve( BinTree origin_tree, BinTree judge_tree );

int main() {
    int n, l, i, val;
    scanf("%d", &n);
    while ( n ) {
        BinTree origin_tree = 0;
        scanf("%d", &l);
        for ( i=0; i<n; i++ ) { // create origin tree
            scanf("%d", &val);
            origin_tree = insert( origin_tree, val );
        }
        while ( l-- ) {         // judge
            BinTree judge_tree = 0;
            for ( i=0; i<n; i++ ) {
                scanf("%d", &val);
                judge_tree = insert( judge_tree, val );
            }
            solve( origin_tree, judge_tree ) ? printf("Yes\n") : printf("No\n");
        }
        scanf("%d", &n);
    }
    return 0;
}

BinTree insert( BinTree BST, int X ) {
    BinTree tmp;
    if ( !BST ) {
        tmp = (BinTree)malloc(sizeof(TreeNode));
        tmp->data = X;
        tmp->left = tmp->right = 0;
        return tmp;
    }
    else {
        if ( X > BST->data ) {
            BST->right = insert( BST->right, X );
        }
        else if ( X < BST->data ) {
            BST->left = insert( BST->left, X );
        }
    }
    return BST;
}

int solve( BinTree origin_tree, BinTree judge_tree ) {
    if ( !origin_tree && !judge_tree ) {    // both are empty
        return 1;
    }
    else if ( (!origin_tree && judge_tree) || (origin_tree && !judge_tree) ) {
        return 0;   // one is empty and the other is not
    }
    else if ( origin_tree->data == origin_tree->data ) {    // neither is empty
        return (solve(origin_tree->left, judge_tree->left) && solve(origin_tree->right, judge_tree->right));
    }
    else {  //unequal
        return 0;
    }
}        
````



