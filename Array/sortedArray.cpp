#include<iostream>
using namespace std;
int main()
{
    int arr[] = {2, 4, 6, 19, 10, 14, 16}, size = 7;
    int i = 0;
    while(i<size-2)
    {
        if(arr[i]>arr[i+1])
        {
            cout<<"Unsorted Array";
            return 0;
            
        }
        i++;
    }
    cout<<"Sorted Array";
    return 0;
}