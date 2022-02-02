#include<iostream>
using namespace std;

int main()
{
    int arr[] = {2, 4, -6, 9, 10, -4, 16}, size = 7;
    int i=0,j=size-1;
    while(i<j)
    {
        while(arr[i]<0)
            i++;
        while(arr[j]>-1)
            j--;
        if(i<j)
        {
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
        
    }
    for(i=0;i<size;i++)
        cout<<arr[i]<<" ";
}