#include <iostream>
using namespace std;

int main()
{
    int arr1[] = {1, 3, 4, 6, 8, 12}, n = 6;
    int arr2[] = {0, 2, 3, 5, 6, 7, 10}, m = 7;
    int size = m + n, final_arr[size] = {0};
    int i = 0, j = 0, k = 0;
    while (i<n && j<m)
    {
        if (arr1[i] < arr2[j] && i < n)
            final_arr[k++] = arr1[i++];
        else
                final_arr[k++] = arr2[j++];
    }
    for(; i<n; )
        final_arr[k++]=arr1[i++];

    for(; j<m; )
        final_arr[k++]=arr2[j++];

    for (k = 0; k < size; k++)
        cout << final_arr[k] << " ";
    return 0;
}