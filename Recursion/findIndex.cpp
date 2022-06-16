#include<iostream>
using namespace std;

int indexFinder(int arr[], int size, int key){
    if (arr[0] == key)
        return 0;
    if (size < 1)
        return -1;
    int remAns = indexFinder(arr + 1, size - 1, key);
    if (remAns == -1)
        return -1;
    else
        return remAns + 1;
}

int main(){
    int arr[] = {1, 2, 3, 7, 5, 6, 7, 8, 9}, n = 9;
    cout << indexFinder(arr, n, 17);
    return 0;
}