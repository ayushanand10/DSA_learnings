#include<iostream>
using namespace std;

int multiply(int a, int b){
    if(a==0 || b==0)
        return 0;
    if(b==1)
        return a;
    return a + multiply(a, b - 1);
}

int main(){
    int a = 1, b = 3;
    cout << multiply(a, b);
    return 0;
}