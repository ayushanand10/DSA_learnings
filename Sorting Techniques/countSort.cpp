#include<iostream>
using namespace std;

void countSort(int A[], int n){
    int max = A[0];
    for (int i = 1; i < n; i++){
        if (A[i] > max)
            max = A[i];
    }
    
    int c[max+1] = {0};
    
    for (int i = 0; i < n; i++)
        c[A[i]]++;

    int i = 0, j = 0;
    while (i < max+1){
        if(c[i]>0){
            A[j++] = i;
            c[i]--;
        }
        else
            i++;
    }
}

int main(){
    int A[] = {2, 5, 8, 2, 3, 3, 7, 0};
    int n = 8;

    countSort(A, n);

    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    
    return 0;
}