#include <iostream>
using namespace std;

class node{
public:
    int data;
    node *next;
    node(int data){
        this->data = data;
        next = NULL;
    }
};

node* input(int A[], int n){
    node *head = NULL, *tail = NULL;
    for (int i = 0; i < n; i++){
            node *temp = new node(A[i]);
        if(head == NULL){
            head = temp;
            tail = head;
        }
        else{
            tail->next = temp;
            tail = temp;
        }
    }
    return head;
}

void display(node* head){
    node *temp = head;
    while (temp){
        cout << temp->data<<" ";
        temp = temp->next;
    }
    cout << endl;
}

node* insert(node* head, int data, int after_pos){
    if(after_pos==0){
        node *newNode = new node(data);
        newNode->next = head;
        head = newNode;
    }
    else{
        node *temp = head;
        for (int i = 1; i < after_pos && temp != NULL; i++){
            temp = temp->next;
        }
        if(temp == NULL)
            cout << "\n*******Invalid Position Entered*******\n";
        else{
            node *newNode = new node(data);
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
    return head;
}

void Delete(node *&head){
    node *p = head, *q = NULL;
    while(p){
        q = p;
        p = p->next;
        q->next = NULL;
        delete q;
    }
    head = NULL;
}