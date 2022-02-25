//      Removing Duplicate Element from a sorted Linklist

#include <iostream>
#include "Linklist.h"
using namespace std;

void removeDuplicate(node *head){
    node *p = head->next, *q = head;
    while(p){
        if(p->data == q->data){
            q->next = p->next;
            p->next = NULL;
            delete p;
            p = q->next;
        }
        else{
            q = p;
            p = p->next;
        }
    }
}

int main(){
    int A[] = {10, 10, 20, 20, 40, 66}, n = 6;
    node *head = input(A, n);
    display(head);
    removeDuplicate(head);
    display(head);

    return 0;
}