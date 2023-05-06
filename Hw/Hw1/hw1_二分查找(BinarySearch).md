````c
Position BinarySearch( List L, ElementType X ) {
    int leftnum = 1;
    int rightnum = L->Last;
    while(leftnum <= rightnum) {
        if (X < L->Data[(leftnum+rightnum)/2]) {
            rightnum = (leftnum+rightnum)/2 - 1;
        }
        else if (X > L->Data[(leftnum+rightnum)/2]) {
            leftnum = (leftnum+rightnum)/2 + 1;
        }
        else if (X == L->Data[(leftnum+rightnum)/2]) {
            return (leftnum+rightnum)/2;
        }
    } 
    return NotFound;
}
````

