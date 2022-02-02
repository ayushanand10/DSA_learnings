#include <iostream>
using namespace std;

int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

int binary_search(int low, int high, int key)
{
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (key == arr[mid])
            return mid;
        else if (key < arr[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
    
}

int recBinarySearch(int low, int high, int key)
{
    if (low <= high)
    {
        int mid = (low + high) / 2;
        if (key == arr[mid])
            return mid;
        else if (key < arr[mid])
            recBinarySearch(low, mid - 1, key);
        else
            recBinarySearch(mid + 1, high, key);
    }
}

int main()
{
    int key = 4;
    cout << binary_search(0, 10, key) << endl;
    cout << recBinarySearch(0, 10, key) << endl;
    return 0;
}