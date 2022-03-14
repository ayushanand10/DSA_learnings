/*      Implementing Stack Using Linklist       */

#include<iostream>
using namespace std;

class Stack{
public:
    int data;
    Stack *next;
    Stack (int data){
        this->data = data;
    }
};

void Push(Stack *&st, int value){
    Stack *t = new Stack(value);
    t->next = st;
    st = t;
}

int Pop(Stack *&st){
    if(st==NULL){
        cout << "!! Stack Underflow !!" << endl;
        return -1;
    }
    Stack *t = st;
    st = st->next;
    int d = t->data;
    delete t;
    return d;
}

void Display(Stack *st){
    Stack *t = st;
    while(t){
        cout << t->data << " ";
        t = t->next;
    }
    cout << endl;
}

int main(){
    Stack *st1_top = NULL;
    Push(st1_top, 5);
    Push(st1_top, 15);
    Push(st1_top, 54);
    Push(st1_top, 20);
    Display(st1_top);
    cout << Pop(st1_top) << endl;
    Display(st1_top);

    return 0;
}