#include<iostream>
using namespace std;

bool checkSortedArray(int *arr, int n){
    if(n==1 || n==0)
        return true;

    bool prevAns = checkSortedArray(arr, n - 1);

    bool ans = arr[n-1] > arr[n - 2] ? true : false;
    return ans && prevAns;
}

int main(){
    int arr[] = {1, 2, 3, 4, 5, 6, 17, 8, 9}, n = 9;
    cout << checkSortedArray(arr, n);
}