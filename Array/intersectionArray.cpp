#include <iostream>
using namespace std;

int *intersectionUnsorted(int *a1, int *a2, int n, int m)
{
    int s = 0, k = 0;
    n > m ? s = n : s = m;
    // int a3[s] = {0};
    int *a3 = new int[s]();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a1[i] == a2[j])
                a3[k++] = a1[i];
        }
    }
    return a3;
}

int main()
{ // array me unique elements hone chahiye
    int arr1[] = {2, 3, 1, 4, 7, 5}, n = 6;
    int arr2[] = {3, 6, 1, 8, 2}, m = 5;
    int *ptr = intersectionUnsorted(arr1, arr2, n, m);
    int s = 0;
    n > m ? s = n : s = m;
    for (int k = 0; k < s; k++)
        cout << ptr[k] << " ";
    delete[] ptr;
    return 0;
}