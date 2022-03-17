/*      To overcome the drawbacks of linear linklist using Arrays, we use Circular Queue    */

#include<iostream>
using namespace std;

class Queue{
public:
    int size, front, rear, *Q;
    Queue(int size){
        this->size = size;
        front = rear = 0;
        Q = new int[size];
    }
    ~Queue(){
        delete[] Q;
    }
};

void Enqueue(Queue *ob, int data){
    if ((ob->rear + 1) % (ob->size) == ob->front){
        cout << "!! Queue is FULL !!\n";
        return;
    }
    else{
        ob->rear = (ob->rear + 1) % (ob->size);
        ob->Q[ob->rear] = data;
    }
}

int Dequeue(Queue *ob){
    int x = -1;
    if (ob->front == ob->rear)
        cout << "!! Queue if Empty !!\n";
    else{
        ob->front = (ob->front + 1) % (ob->size);
        x = ob->Q[ob->front];
    }
    return x;
}

void Display(Queue *ob){
    if (ob->front == ob->rear)
        cout << "!! Queue if Empty !!\n";
    else{
        int i = ob->front+1;
        for (; i != ob->rear; i = (i + 1) % ob->size)
            cout << ob->Q[i] << " ";
        cout << ob->Q[i] << endl;
    }
}

int main(){
    Queue CQ(7);

    Enqueue(&CQ, 10);
    Enqueue(&CQ, 20);
    Enqueue(&CQ, 30);
    Enqueue(&CQ, 40);
    Enqueue(&CQ, 50);
    Enqueue(&CQ, 60);

    Display(&CQ);

    Enqueue(&CQ, 70);

    cout << Dequeue(&CQ) << endl;
    Display(&CQ);

    Enqueue(&CQ, 80);

    Display(&CQ);

    return 0;
}