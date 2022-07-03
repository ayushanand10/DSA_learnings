#include <iostream>
using namespace std;

bool isSorted(int arr[], int size){
    if (size <= 1)
        return true;
    if (arr[0] > arr[1])
        return false;
    bool remAns = isSorted(arr + 1, size - 1);
    return remAns;
}

int main(){
    int A[] = {1, 2, 3, 4, 15, 6, 7, 8, 9, 0}, n = 10;
    cout << isSorted(A, n);
    return 0;
}