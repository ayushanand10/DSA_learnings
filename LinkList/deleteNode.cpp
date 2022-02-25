#include<iostream>
#include "Linklist.h"
using namespace std;

int deletePos(node *&head, int pos){
    node *p = head, *q;
    int d;
    if(pos == 1){
        head = head->next;
        p->next = NULL;
    }
    else{
        for (int i = 1; i < pos && p != NULL; i++){
            q = p;
            p = p->next;
        }
        if(p==NULL){
            cout << "\n   INVALID   POSITION\n";
            return -1;
        }
        q->next = p->next;
    }
    d = p->data;
    p->next = NULL;
    delete p;
    return d;
}

int main(){
    int A[] = {10, 20, 30, 40, 50, 60}, n = 6;
    node *head = input(A, n);
    display(head);
    int d;

    d = deletePos(head, 5);
    if( d != -1){
        cout << "\nDeleted Data = " << d <<endl;
    }
    display(head);

    d = deletePos(head, 1);
    if( d != -1){
        cout << "\nDeleted Data = " << d <<endl;
    }
    display(head);

    return 0;
}