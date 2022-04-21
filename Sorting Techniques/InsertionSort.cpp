#include <iostream>
using namespace std;

void InsertionSort(int A[], int n){
    for (int i = 1; i < n; i++){
        int temp = A[i];
        int j = i - 1;
        while(j > -1 &&A[j]>temp){
            A[j + 1] = A[j];
            j--;
        }

        A[j + 1] = temp;
    }
}

int main(){
    int A[] = {8, 5, 7, 3, 2};
    int n = 5;
    InsertionSort(A, n);

    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    cout << endl;

    return 0;
}