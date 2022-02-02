#include <iostream>
using namespace std;

int main()
{
    int a[] = {4, 1, 6, 3, 7, 9, 11}, n = 7;
    int l = 1, h = 11;
    int *p = new int[h];
    for (int i = 0; i < h; i++)
    {
        p[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        int val = a[i];
        p[val] = 1;
    }

    for (int i = 0; i < h; i++)
    {
        if (p[i] == 0)
            cout << i << endl;
    }

    delete[] p;
    return 0;
}