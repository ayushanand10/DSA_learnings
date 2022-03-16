#include<iostream>
using namespace std;

class Stack{
public:
    int size, top;
    string s;

    Stack(string exp){
        size = exp.length();
        top = -1;
        s = new char[size];
    }

    // ~Stack(){
    //     delete s;
    // }
};

void Push(Stack &st, char data){
    if(st.top == st.size-1){
        cout << "!! Stack Overflow !!" << endl;
        return;
    }
    st.top++;
    st.s[st.top] = data;
}

void Pop(Stack st){
    if(st.top == -1){
        cout << "!! Stack Underflow !!" << endl;
        // return -1;
    }
    else{
        // char a = st.s[st.top];
        st.top--;
        // return a;
    }
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

bool isBalanced(string exp){
    int i;
    Stack st(exp);
    for (i = 0; exp[i] != '\0'; i++){
        if(exp[i]=='(')
            Push(st,exp[i]);
        else if(exp[i]==')'){
            if(IsEmpty(st))
                return 0;
            else
                Pop(st);
        }
    }
    if(st.top==-1)
        return true;
    else
        return false;
}

int main(){
    string exp = "(2+3)*(5-8))";
    cout << isBalanced(exp);

    return 0;
}