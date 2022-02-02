#include <iostream>
using namespace std;

int main()
{
    //Array should be sorted & can have multiple missing elements
    int arr[] = {1, 3, 4, 6, 8, 12}, n = 6;
    int l = arr[0], h = arr[n - 1];
    int diff = l - 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] - i != diff)
        {
            while (diff < arr[i] - i)
            {
                cout << i + diff << endl;
                diff++;
            }
        }
    }
}