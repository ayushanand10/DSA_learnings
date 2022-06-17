#include<iostream>
using namespace std;

bool checkPalindrome(string str, int start, int end){
    if(start>=end)
        return true;
    if(str[start]==str[end])
        return true && checkPalindrome(str, start + 1, end - 1);
    return false;
}

int main(){
    cout << checkPalindrome("AyuyS", 0, 4);
}