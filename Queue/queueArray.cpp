#include<iostream>
using namespace std;

class Queue{
public:
    int front, rear, size, *Qu;
    Queue(int size){
        this->size = size;
        Qu = new int[size];
        front = rear = -1;
    }
    ~Queue(){
        delete[] Qu;
    }
};

void Enqueue(Queue &ob, int data){
    if(ob.rear == ob.size-1){
        cout << "!! Queue is FULL !!" << endl;
        return;
    }
    ob.rear++;
    ob.Qu[ob.rear] = data;
}

int Dequeue(Queue &ob){
    int x = -1;
    if(ob.front==ob.rear)
        cout << "!! Queue is EMPTY !!" << endl;
    else{
        ob.front++;
        x = ob.Qu[ob.front];
    }
    return x;
}

void Display (Queue &ob){
    for (int i = ob.front + 1; i <= ob.rear; i++)
        cout << ob.Qu[i] << " ";
    cout << endl;
}

int main(){
    Queue q(5);
    Enqueue(q, 10);
    Enqueue(q, 20);
    Enqueue(q, 30);

    Display(q);
    // Display(q);

    cout << Dequeue(q) << endl;

    Display(q);

    Enqueue(q, 10);
    Enqueue(q, 20);
    Enqueue(q, 30);

    Display(q);

    return 0;
}