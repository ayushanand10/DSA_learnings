#include<iostream>
using namespace std;

int countZero(int num){
    if(num<10){
        if(num % 10 == 0)
            return 1;
        else
            return 0;
    }

    int ans = countZero(num / 10);

    if (num % 10 == 0)
        return ans + 1;
    return ans;
}
int main(){
    cout << countZero(19);
    return 0;
}