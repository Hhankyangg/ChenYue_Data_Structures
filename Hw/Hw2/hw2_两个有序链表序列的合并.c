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