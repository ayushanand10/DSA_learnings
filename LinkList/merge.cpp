#include<iostream>
#include"Linklist.h"
using namespace std;

node *merge(node *h1, node *h2, int n, int m){
    int A[n + m], i = 0;
    while(h1 && h2){
        if(h1->data < h2->data){
            A[i++] = h1->data;
            h1 = h1->next;
        }
        else{
            A[i++] = h2->data;
            h2 = h2->next;
        }
    }
    while(h1){
        A[i++] = h1->data;
        h1 = h1->next;
    }
    while(h2){
        A[i++] = h2->data;
        h2 = h2->next;
    }

    node *h3 = input(A, n + m);
    return h3;
}

int main(){
    int A[] = {1, 4, 7, 8, 10}, n = 5;
    int B[] = {0, 2, 5, 6, 11}, m = 5;
    node *h1 = input(A, n);
    node *h2 = input(B, m);
    node *h3 = merge(h1, h2, n, m);
    display(h3);
    Delete(h1);
    Delete(h2);
    Delete(h3);
    display(h3);
    return 0;
}