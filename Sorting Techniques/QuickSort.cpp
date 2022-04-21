#include<iostream>
using namespace std;

int Partition(int A[], int low, int high){
    int count = 0, pivot = A[low];
    for (int i = low+1; i <= high; i++){
        if(A[i]<pivot)
            count++;
    }
    int pivotIndex = low + count;
    swap(A[low], A[pivotIndex]);
    int i = low, j = high;

    while(i<j){
        while(A[i]<pivot)
            i++;
        while(A[j]>pivot)
            j--;
        
        if(i<j){
            swap(A[i], A[j]);
            i++;
            j--;
        }
    }
    return pivotIndex;
}

void QuickSort(int A[], int low, int high){
    if (low >= high)
        return;
    int p = Partition(A, low, high);

    QuickSort(A, low, p - 1);
    QuickSort(A, p + 1, high);
}

int main(){
    int A[] = {4, 5, 2, 7, 1, 3, 9, 9, 9, 10};
    int n = 10;

    QuickSort(A, 0, n - 1);

    for (int i = 0; i < n; i++){
        cout << A[i] << " ";
    }
    cout << endl;

    return 0;
}