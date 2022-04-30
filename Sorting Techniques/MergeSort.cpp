#include<iostream>
using namespace std;

void Merge(int A[], int low, int mid, int high){
    int i = low, j = mid + 1, k = low;
    int B[high + 1];
    while (i <= mid && j <= high){
        if(A[i]<A[j])
            B[k++] = A[i++];
        else    
            B[k++] = A[j++];
    }
    while(i<=mid)
        B[k++] = A[i++];
    
    while(j<=high)
        B[k++] = A[j++];

    for (i = low; i <= high; i++)
        A[i] = B[i];
}

void MergeSort(int A[], int low, int high){
    if(low >= high)
        return;
    
    int mid = (low + high) / 2;
    MergeSort(A, low, mid);
    MergeSort(A, mid + 1, high);
    Merge(A, low, mid, high);
}

int main(){
    int A[] = {2, 5, 8, 12, 3, 3, 7, 10};
    int n = 8;

    MergeSort(A, 0, n - 1);

    for (int i = 0; i < n; i++){
        cout << A[i] << " ";
    }
    cout << endl;

    return 0;
}