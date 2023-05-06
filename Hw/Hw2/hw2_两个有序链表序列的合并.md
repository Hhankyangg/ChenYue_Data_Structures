本题要求实现一个函数，将两个链表表示的递增整数序列合并为一个非递减的整数序列。

### 函数接口定义：

```c++
List Merge( List L1, List L2 );
```

其中`List`结构定义如下：

```c++
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data; /* 存储结点数据 */
    PtrToNode   Next; /* 指向下一个结点的指针 */
};
typedef PtrToNode List; /* 定义单链表类型 */
```

`L1`和`L2`是给定的带头结点的单链表，其结点存储的数据是递增有序的；函数`Merge`要将`L1`和`L2`合并为一个非递减的整数序列。应直接使用原序列中的结点，返回归并后的带头结点的链表头指针。

### 裁判测试程序样例：

```c++
#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

List Read(); /* 细节在此不表 */
void Print( List L ); /* 细节在此不表；空链表将输出NULL */

List Merge( List L1, List L2 );

int main()
{
    List L1, L2, L;
    L1 = Read();
    L2 = Read();
    L = Merge(L1, L2);
    Print(L);
    Print(L1);
    Print(L2);
    return 0;
}

/* 你的代码将被嵌在这里 */
```

### 输入样例：

```in
3
1 3 5
5
2 4 6 8 10
```

### 输出样例：

```out
1 2 3 4 5 6 8 10 
NULL
NULL
```



````c
typedef int ElementType;
typedef struct Node* PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

List Merge( List L1, List L2 ) {
    List head = (List)malloc(sizeof(struct Node)); //empty head node
    head->Next = '\0';
    List tail = head;    // head node
    List p_tmp;
    List tmp_1=L1, tmp_2=L2;
    L1 = L1->Next; L2 = L2->Next;
    tmp_1->Next = '\0'; tmp_2->Next = '\0';
    while (L1!='\0' && L2!='\0') {
        if (L1->Data <= L2->Data) {
            p_tmp = L1;
            L1 = L1->Next;    // L1 point to the next node
            p_tmp->Next = '\0';
            tail->Next = p_tmp;
            tail = p_tmp;    // Connect the node of L1 to L
        }
        else {            
            p_tmp = L2;
            L2 = L2->Next;    // L2 point to the next node
            p_tmp->Next = '\0';
            tail->Next = p_tmp;
            tail = p_tmp;    // Connect the node of L2 to L            
        }
    }
    

    if (L1!='\0') {   // connect the remainder of L1 to L
        tail->Next = L1;
        L1 = '\0';
    }
    else if (L2!='\0') {  // connect the remainder of L2 to L
        tail->Next = L2;
        L2 = '\0';  
    }
    return head;

}
````



