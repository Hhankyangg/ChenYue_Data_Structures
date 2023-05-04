// 设计函数分别求两个一元多项式的乘积与和。

// 输入格式:
// 输入分2行，每行分别先给出多项式非零项的个数，再以指数递降方式输入一个多项式非零项系数和指数（绝对值均为不超过1000的整数）。数字间以空格分隔。

// 输出格式:
// 输出分2行，分别以指数递降方式输出乘积多项式以及和多项式非零项的系数和指数。数字间以空格分隔，但结尾不能有多余空格。零多项式应输出0 0。

// 输入样例:
// 4 3 4 -5 2  6 1  -2 0
// 3 5 20  -7 4  3 1
// 输出样例:
// 15 24 -25 22 30 21 -10 20 -21 8 35 6 -33 5 14 4 -15 3 18 2 -6 1
// 5 20 -4 4 -5 2 9 1 -2 0

#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
    int cof;
    int exp;
    struct _Node* next;
} PolyNode;
typedef struct {
    PolyNode* head;
    PolyNode* tail;
} Polynomial;

void read(Polynomial* p);
void plus(Polynomial* p1, Polynomial* p2, Polynomial* p_plus);
void mult(Polynomial* p1, Polynomial* p2, Polynomial* p_mult);
void PrintL(Polynomial* p);
int cmp(PolyNode* p1, PolyNode* p2);
void attach(Polynomial* p, int cof, int exp);

int main() {
    Polynomial p1, p2, p_plus, p_mult;
    read(&p1); read(&p2);
    plus(&p1, &p2, &p_plus);
    mult(&p1, &p2, &p_mult);
    PrintL(&p_mult);
    printf("\n");    
    PrintL(&p_plus);
    return 0;
}

void read(Polynomial* p) {
    p->head = p->tail = '\0';
    int n;
    int cof, exp;
    scanf("%d", &n);
    while (n--) {
        scanf("%d %d", &cof, &exp);
        attach(p, cof, exp);
    }
}

void plus(Polynomial* p1, Polynomial* p2, Polynomial* p_plus) {
    p_plus->head = p_plus->tail = '\0';
    PolyNode* p_p1 = p1->head;
    PolyNode* p_p2 = p2->head;
    while (p_p1 && p_p2) {
        switch (cmp(p_p1, p_p2)) {
            case  1:
                attach(p_plus, p_p1->cof, p_p1->exp);
                p_p1 = p_p1->next;
                break;
            case  0:
                if ((p_p1->cof)+(p_p2->cof) != 0) { // if == 0, it will affect the mult part
                    attach(p_plus, (p_p1->cof)+(p_p2->cof), p_p1->exp);
                }
                p_p1 = p_p1->next;
                p_p2 = p_p2->next;
                break;
            case -1:
                attach(p_plus, p_p2->cof, p_p2->exp);
                p_p2 = p_p2->next;
                break;
        }
    }
    for (; p_p1; p_p1=p_p1->next) {
        attach(p_plus, p_p1->cof, p_p1->exp);
    }
    for (; p_p2; p_p2=p_p2->next) {
        attach(p_plus, p_p2->cof, p_p2->exp);
    }
}

void mult(Polynomial* p1, Polynomial* p2, Polynomial* p_mult) {
    p_mult->head = p_mult->tail = '\0';
    Polynomial p_mult_mirror = {'\0', '\0'};
    PolyNode* p_p1 = p1->head;
    Polynomial p_empty = {'\0', '\0'};
    for (; p_p1; p_p1=p_p1->next) {
        Polynomial mult_p_tmp = {'\0', '\0'};
        PolyNode* p_p2 = p2->head;
        for(; p_p2; p_p2=p_p2->next) {
            attach(&mult_p_tmp, (p_p1->cof)*(p_p2->cof), (p_p1->exp)+(p_p2->exp));
        }   // the 1st, 2nd... elem of p1 times every elems in p2
        plus(&mult_p_tmp, &p_mult_mirror, p_mult);
        plus(p_mult, &p_empty, &p_mult_mirror); // copy p_mult to p_mult_mirror
    }
}

void PrintL(Polynomial* p) {
    PolyNode* p_tmp = p->head;
    int tag = 0;    // judge if the poly is 0
    for(; p_tmp; p_tmp=p_tmp->next) {
        if (p_tmp->next == '\0') {
            if (p_tmp->cof != 0) {
            printf("%d %d", p_tmp->cof, p_tmp->exp);
            tag ++;
            }
        }
        else {
            if (p_tmp->cof != 0) {
            printf("%d %d ", p_tmp->cof, p_tmp->exp);
            tag ++;
            }
        }
    }
    if (tag == 0) {
        printf("0 0");
    }
}

void attach(Polynomial* p, int cof, int exp) {
    PolyNode* tmp_p;
    tmp_p = (PolyNode*)malloc(sizeof(PolyNode));
    tmp_p->cof = cof;
    tmp_p->exp = exp;
    tmp_p->next = '\0';
    if (p->head) {
        p->tail->next = tmp_p;
        p->tail = p->tail->next;
    }
    else {
        p->head = tmp_p;
        p->tail = p->head;
    }
}

int cmp(PolyNode* p1, PolyNode* p2) {
    if (p1->exp > p2->exp) {
        return 1;
    }
    else if (p1->exp == p2->exp) {
        return 0;
    }
    else {
        return -1;
    }
}