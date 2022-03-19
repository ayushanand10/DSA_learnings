#include<iostream>
using namespace std;
class TreeNode{
public:
    TreeNode *left;
    int treeData;
    TreeNode *right;

    TreeNode(int tdata){
        treeData = tdata;
        left = right = NULL;
    }
};
class QueueNode{
public:
    TreeNode *Tptr;
    QueueNode *next;
    QueueNode(TreeNode *ptr){
        this->Tptr = ptr;
        next = NULL;
    }
};
class Queue{
public:
    QueueNode *front;
    QueueNode *rear;
    Queue(){
        front = rear = NULL;
    }
    ~Queue(){
        QueueNode *t;
        while(t){
            t = front;
            front = front->next;
            delete t;
        }
    }
};
void Enqueue(Queue *Q, TreeNode *T){
    QueueNode *t = new QueueNode(T);
    if(t==NULL){
        return;
    }
    if(Q->front == NULL){
        Q->front = Q->rear = t;
    }
    else{
        Q->rear->next = t;
        Q->rear = t;
    }
}
TreeNode *Dequeue(Queue *Q){
    TreeNode *T = NULL;
    if(Q->front != NULL){
        T = Q->front->Tptr;
        Q->front = Q->front->next;
    }
    return T;
}
