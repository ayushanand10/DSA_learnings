#include<iostream>
#include"Linklist.h"
using namespace std;

node *merge(node *head1, node *head2){
    node *last = NULL, *first = head1, *second = head2, *final = NULL;

    if (first->data < second->data){
        final = first;
        last = first;
        first = first->next;
        last->next = NULL;
    }
    else{
        final = second;
        last = second;
        second = second->next;
        last->next = NULL;
    }

    while(first && second){
        if (first->data < second->data){
            last->next = first;
            last = first;
            first = first->next;
            last->next = NULL;
        }
        else{
            last->next = second;
            last = second;
            second = second->next;
            last->next = NULL;
        }
    }

    if(first){
        last->next = first;
    }
    if(second){
        last->next = second;
    }

    return final;
}

int main(){
    int A[] = {4, 7, 10}, n = 3;
    int B[] = {2, 5, 6, 11, 13}, m = 5;
    
    node *h1 = input(A, n);
    cout << "l1 : ";
    display(h1);

    node *h2 = input(B, m);
    cout << "l2 : ";
    display(h2);

    node *h3 = merge(h1, h2);
    cout << "After merging : ";
    display(h3);

    return 0;
}