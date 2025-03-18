struct segantTree{
    int sum;
    segantTree *left;
    segantTree *right;
    segantTree(int sum,segantTree *left,segantTree *right):sum(sum),left(left),right(right){}
};