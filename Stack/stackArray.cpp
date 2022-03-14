/*      Program illustrating functions of STACK     
        Such as :- 
            1. Push
            2. Pop
            3. Display
            4. Peek
            5. Stack Top
            6. Is Empty
            7. Is Full                              
*/

#include<iostream>
using namespace std;

class Stack{
public:
    int size, top, *s;

    Stack(int size){
        this->size = size;
        top = -1;
        s = new int[size];
    }

    ~Stack(){
        delete[] s;
    }
};

void Push(Stack &st, int data){
    if(st.top == st.size-1){
        cout << "!! Stack Overflow !!" << endl;
        return;
    }
    st.top++;
    st.s[st.top] = data;
}

int Pop(Stack st){
    if(st.top == -1){
        cout << "!! Stack Underflow !!" << endl;
        return -1;
    }
    else{
        int a = st.s[st.top];
        st.top--;
        return a;
    }
}

void Peek(Stack st, int index){
    if(index > st.top || index < 0){
        cout << "!! Invalid Index !!" << endl;
        return;
    }
    cout << st.s[index] << endl;
}

int StackTop(Stack st){
    if(st.top==-1)
        return -1;
    else
        return st.s[st.top];
}

bool IsFull(Stack st){
    if (st.top == st.size - 1)
        return true;
    else
        return false;
}

bool IsEmpty(Stack st){
    if (st.top == -1)
        return true;
    else
        return false;
}


void Display(Stack st){
    for (int i = st.top; i >= 0; i--){
        cout << st.s[i] << " ";
    }
    cout << endl;
}

int main(){
    int size = 5;
    Stack st1(size);
 
    Push(st1, 4);
    Push(st1, 14);
    Push(st1, 24);
    Push(st1, 34);
    Push(st1, 54);
 
    Display(st1);
 
    cout << Pop(st1) << endl;
 
    Peek(st1, 3);

    cout << StackTop(st1) << endl;

    return 0;
}