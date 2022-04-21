#include<bits/stdc++.h>
using namespace std;

class Heap{
protected:
    int H[50];
    int size;
public:
    void Insert(int data);
    void Create(int A[], int s);
    void Delete();
    void Display();
    void HeapSort();
    // void Heapify(int A[],int n, int i);
    // void Heapify(int A[], int n){
    //     for (int i = n / 2; i > 0; i--){
    //         Heapify(A, n, i);
    //     }
    // }
    // void HeapSort(int A[], int n);
    Heap(){
        size = 0;
        H[0] = -1;
    }
};

void Heap:: Insert(int data){
    size = size + 1;
    int index = size;
    H[index] = data;

    while(index > 1){
        int parent = index / 2;
        if(H[parent] < H[index]){
            swap(H[parent], H[index]);
            index = parent;
        }
        else{
            return;
        }
    }
}

void Heap::Delete(){
    if (size == 0){
        cout << "!! Empty Heap !!\n";
        return;
    }

    H[1] = H[size];
    size--;

    int i = 1;
    while(i<size){
        int left = 2*i;
        int right = 2*i + 1;

        if (left < size && H[i] < H[left]){
            swap(H[i], H[left]);
            i = left;
        }
        else if(right<size && H[i]<H[right]){
            swap(H[i], H[right]);
            i = right;
        }
        else
            return;
    }
}

void Heap::Display(){
    for (int i = 1; i <= size; i++)
        cout << H[i] << " ";
    cout << endl;
}

void Heapify(int A[], int n, int i){
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if (left <= n && A[largest] < A[left])
        largest = left;
        
    if (right <= n && A[largest] < A[right])
        largest = right;
        
    if(largest != i){
        swap(A[largest], A[i]);
        Heapify(A, n, largest);
    }
}

void HeapSort(int A[], int n){
    int size = n;

    while (size > 1){
        swap(A[1], A[size]);
        size--;
        Heapify(A, size, 1);
    }

}

int main(){
    // Heap h;
    // h.Insert(50);
    // h.Insert(55);
    // h.Insert(53);
    // h.Insert(52);
    // h.Insert(54);
    // h.Display();

    // h.Delete();
    // h.Display();

    int A[] = {-1, 54, 53, 55, 52, 50};
    int n = 5;

    for (int i = n / 2; i > 0; i--){
        Heapify(A, n, i);
    }
    // Heapify(A,6);
    for (int i = 1; i <= n; i++)
        cout << A[i] << " ";
    cout << endl;

    HeapSort(A, n);
    for (int i = 1; i <= n; i++)
        cout << A[i] << " ";
    cout << endl;

    return 0;
}