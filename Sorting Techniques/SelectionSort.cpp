#include<iostream>
using namespace std;

void SelectionSort(int A[], int n){
    for (int i = 0; i < n; i++){
        int j = i, k = i;
        for (; j < n; j++){
            if(A[j]<A[k])
                k = j;
        }
        swap(A[i], A[k]);
    }
}

int main(){
    int A[] = {8, 5, 7, 3, 2};
    int n = 5;
    SelectionSort(A, n);

    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    cout << endl;

    return 0;
}