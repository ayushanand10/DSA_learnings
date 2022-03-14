/*  WE NEED TO FIND THE MIDDLE NODE OF A LINKLIST   */

#include<iostream>
#include "Linklist.h"
using namespace std;

node *middleNode(node *head){
    node *fast = head, *slow = head;
    if(head==NULL)
        return NULL;
    while (fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

void printNode(node *ptr){
    if(ptr){
        cout << "Middle Node Address : " << ptr << endl;
        cout << "Middle Node Data : " << ptr->data << endl;
    }
    else
        cout << "Empty Linklist\n";
}

int main(){
    int A[] = {3, 5, 7, 1, 2, 9, 0}, n = 7;
    node *l1 = input(A, n);
    int B[] = {4, 7, 2, 9, 6, 1}, m = 6;
    node *l2 = input(B, m);

    node *middle_l1 = middleNode(l1);
    printNode(middle_l1);

    node *middle_l2 = middleNode(l2);
    printNode(middle_l2);

    Delete(l1);
    Delete(l2);
    return 0;
}