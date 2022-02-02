#include <iostream>
using namespace std;

int main()
{
//  Sortd Array
    int a[] = {1, 2, 4, 4, 6, 6, 6, 8, 9, 9, 9, 9, 11}, n = 13;
    int lastDuplicate = 0;

    for (int i = 0; i < n; i++) // To find the duplicate elements only
    {
        if (a[i] == a[i + 1] && lastDuplicate != a[i])
        {
            cout << a[i] << endl;
            lastDuplicate = a[i];
        }
    }

    // To find the occurance of duplicate elements
    int h = 11;
    int *p = new int[h + 1]{0};
    for (int i = 0; i < n; i++)
    {
        p[a[i]] += 1;
    }
    for (int i = 0; i < h + 1; i++)
    {
        if (p[i] > 1)
            cout << i << " -> " << p[i] << endl;
    }
    delete[] p;

// For unsorted Array
    int A[] = {6, 8, 6, 4, 6, 5, 6, 8, 2};
    int m = 9;

    //  Wirhout hashing
    for (int i = 0; i < m; i++)
    {
        int count = 1;
        if (A[i] == -1)
            continue;
        for (int j = i + 1; j < m; j++)
        {
            if (A[j] == A[i])
            {
                count++;
                A[j] = -1;
            }
        }
        if (count > 1)
            cout << A[i] << " - " << count << endl;
    }

    //  With Hashing
    int max = A[0];
    for (int i = 1; i < m; i++)
        if (A[i] > max)
            max = A[i];
    int *ptr = new int[max+1]{0};
    for (int i = 0; i < m; i++)
        ptr[A[i]]++;
    for (int i = 0; i < max+1; i++)
        if (ptr[i] > 1)
            cout << i << " # " << ptr[i] << endl;
    delete[] ptr;

    return 0;
}