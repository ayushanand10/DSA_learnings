#include<iostream>
using namespace std;

bool binarySearch(int *arr, int s, int e, int k){

    if (s > e)
        return false;

    int mid = s + (e - s) / 2;

    if (arr[mid] == k)
        return true;
     
    if (k < arr[mid])
        return binarySearch(arr, s, mid, k);
    else
        return binarySearch(arr, mid+1, e, k);

}

int main(){
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, n = 10;
    cout << binarySearch(arr, 0, n, 6);
    return 0;
}