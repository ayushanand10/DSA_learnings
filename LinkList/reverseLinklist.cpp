#include <iostream>
#include "Linklist.h"
using namespace std;

void reverse(node *&head){
    node *p = head, *q = NULL, *r = NULL;
    while(p!=NULL){
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    head = q;
}

void recursiveReverse(node* q, node *p, node *&head){
    if(p==NULL){
        head = q;
    }
    else{
        recursiveReverse(p, p->next, head);
        p->next = q;
    }
}

int main(){
    int A[] = {1, 2, 3, 4, 5, 6, 33, 77}, n = 8;
    node *head = input(A, n);
    display(head);
    reverse(head);
    display(head);
    recursiveReverse(NULL,head ,head);
    display(head);
    return 0;
}