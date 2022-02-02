#include <iostream>
using namespace std;

int main()
{
    int arr[] = {2, 4, 6, 9, 10, 14, 16}, size = 7;
    int key = 7, temp = 0, i = size - 1;

    while (arr[i] > key)
    {
        arr[i+1] = arr[i];
        i--;
    }
    arr[i+1]=key;
    for(i=0; i<size; i++)
        cout<<arr[i]<<" ";
    return 0;
}