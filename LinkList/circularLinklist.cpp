#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node *next = NULL;
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

Node *Input(int A[], int n){
    Node  *newNode = new Node(A[0]);
    Node *head = newNode, *t = NULL;
    t = head;
    for (int i = 1; i < n; i++){
        newNode = new Node(A[i]);
        t->next = newNode;
        t = t->next;
    }
    t->next = head;
    return head;
}

void Display(Node *head){
    if(head==NULL)
        return;
    Node *t = head;
    do{
        cout << t->data << " ";
        t = t->next;
    } while (t != head);
    cout << endl;
}

int Length(Node *head){
    if(head==NULL)
        return 0;
    Node *t = head;
    int count = 0;
    do{
        count++;
        t = t->next;
    } while (t != head);
    return count;
}

void Delete(Node *&head){                                                                       
    Node *t = head, *p=NULL;
    Node *h = head;
    do{
        p = t;
        t = t->next;
        p->next = NULL;
        delete p;
    } while (t != h);
    head = NULL;
}

void Insert(Node *&head, int d, int posAfter){
    if(posAfter<=0 && posAfter>=Length(head)){
        cout << "Invalid Position\n";
        return;
    }
    Node *newNode = new Node(d);
    Node *t = head;
    if(posAfter == 0){
        do{
            t = t->next;
        } while (t->next != head);
        t->next = newNode;
        newNode->next = head;
        head = newNode;
    }
    else{
        for (int i = 1; i < posAfter; i++){
            t = t->next;
        }
        newNode->next = t->next;
        t->next = newNode;
    }
    
}

int main(){
    int A[] = {9, 8, 7, 6, 4, 2, 0}, n = 7;
    Node *cl1 = Input(A, n);
    Display(cl1);
    // cout << Length(cl1);
    
    Insert(cl1, 100, 7);
    Display(cl1);
    Insert(cl1, 100, 5);
    Display(cl1);
    Insert(cl1, 100, 0);
    Display(cl1);

    Delete(cl1);
    return 0;
}