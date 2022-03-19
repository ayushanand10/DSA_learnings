/*      Queue using LINKED LIST     */

#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node *next;
    Node(int data){
        this->data = data;
        next = NULL;
    }
    Node(){
        next = NULL;
    }
};

class Queue{
public:
    Node *front, *rear;
    Queue(){
        front = rear = NULL;
    }
    ~Queue(){
        Node *t;
        while(t){
            t = front;
            front = front->next;
            delete t;
        }
    }
};

void Enqueue(Queue *ob, int data){
    Node *t = new Node(data);
    if (t == NULL){
        cout << "!! Queue is FULL !!\n";
        return;
    }
    
    if(ob->front == NULL){
        ob->front = ob->rear = t;
    }
    else{
        ob->rear->next = t;
        ob->rear = t;
    }
}

int Dequeue(Queue *ob){
    int x = -1;
    if(ob->front == NULL){
        cout << "!! Queue is EMPTY !!\n";
    }
    else{
        x = ob->front->data;
        ob->front = ob->front->next;
    }
    return x;
}

void Display (Queue *ob){
    Node *t = ob->front;
    while(t){
        cout << t->data << " ";
        t = t->next;
    }
    cout << endl;
}

int main(){
    Queue q;
    cout << Dequeue(&q) << endl;
    Enqueue(&q, 10);
    Enqueue(&q, 20);
    Enqueue(&q, 30);
    Enqueue(&q, 40);
    Display(&q);

    cout << Dequeue(&q) << endl;
    Display(&q);

    return 0;
}