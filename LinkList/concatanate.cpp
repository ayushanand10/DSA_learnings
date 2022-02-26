#include<iostream>
#include"Linklist.h"
using namespace std;

node* concatenate(node *h1, node*h2){
    node *temp = h1;
    while (temp->next != NULL){
        temp = temp->next;
    }
    temp->next = h2;
    return h1;
}

int main(){
    int A[] = {1, 2, 3, 4, 5, 6, 7, 8, 9}, n = 9;
    int B[] = {11, 12, 13, 14, 15, 16, 17, 18, 19}, m = 9;
    node *h1 = input(A, n);
    node *h2 = input(B, m);

    node *h3 = concatenate(h1, h2);
    cout << "Concatenated List is as : ";
    display(h3);

    return 0;
}