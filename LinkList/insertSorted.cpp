#include<iostream>
#include "Linklist.h"
using namespace std;

node* S_insert(node* head, int data){
    node *p1, *p2;
    p1 = head;
    if(p1->data>data){
        node *newNode = new node(data);
        newNode->next = p1;
        head = newNode;
    }
    else{
        while ( p1 != NULL && p1->data < data ){
            p2 = p1;
            p1 = p1->next;
        }
        node *newNode = new node(data);
        newNode->next = p1;
        p2->next = newNode;
    }
    return head;
}


int main(){
    int A[] = {10, 20, 30, 40, 50, 60}, n = 6;
    node *head = input(A, n);
    display(head);
    head = S_insert(head, 35);
    display(head);
    head = S_insert(head, 5);
    display(head);
    head = S_insert(head, 55);
    display(head);
    head = S_insert(head, 75);
    display(head);

    return 0;
}