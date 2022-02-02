#include <iostream>
using namespace std;
int main()
{
    int arr1[] = {1, 3, 4, 6, 8, 12}, n = 6;
    int arr2[] = {0, 2, 3, 5, 6, 7, 10}, m = 7;
    int size = m + n;
    int union_arr[size] = {0};
    int i = 0, j = 0, k = 0;
    while (i < n && j < m)
    {
        if (arr1[i] < arr2[j] && i < n)
            union_arr[k++] = arr1[i++];
        else
        {
            if (arr1[i] > arr2[j] && j < m)
                union_arr[k++] = arr2[j++];
            else
            {
                union_arr[k++] = arr1[i++];
                j++;
            }
        }
    }
    for (; i < n;)
        union_arr[k++] = arr1[i++];

    for (; j < m;)
        union_arr[k++] = arr2[j++];

    for (i = 0; i < k; i++)
        cout << union_arr[i] << " ";
    return 0;
}