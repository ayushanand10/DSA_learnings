#include<iostream>
#include<limits.h>
#include "Linklist.h"
using namespace std;

bool checkSorted(node *head){
    int m = INT_MIN;
    node *t = head;
    while(t){
        if(t->data < m)
            return false;
        m = t->data;
        t = t->next;
    }
    return true;
}

int main(){
    int A[] = {1, 2, 3, 4, 5, 6}, n = 6;
    node *head = input(A, n);

    bool flag = checkSorted(head);
    if(flag)
        cout << "\nSorted Linklist\n";
    else
        cout << "\nUnSorted Linklist\n";

    return 0;
}