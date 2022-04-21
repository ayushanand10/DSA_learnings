#include<iostream>
using namespace std;

void BubbleSort(int A[], int n){
    for (int i = 0; i < n-1; i++){
        bool flag = false;
        for (int j = 0; j < n - 1 - i; j++){
            if (A[j] > A[j + 1]){
                swap(A[j], A[j + 1]);
                flag = true;
            }
        }
        if(flag==false)
            break;
    }
}

int main(){
    int A[] = {8, 5, 7, 3, 2};
    int n = 5;

    BubbleSort(A, n);

    for (int i = 0; i < n; i++){
        cout << A[i] << " ";
    }
    cout << endl;

    return 0;
}