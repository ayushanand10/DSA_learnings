#include <iostream>
using namespace std;

void reverse(string &str, int i, int j){
    cout << "Call received for : " << str << endl;

    if (i > j)
        return;

    swap(str[i], str[j]);
    j--;
    i++;
    reverse(str, i, j);
}

int main(){
    string name = "Ayush";
    reverse(name, 0, name.length() - 1);
    cout << name << endl;
}