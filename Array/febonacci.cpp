#include <iostream>
using namespace std;

int febo(int n)
{
    // if(n==0)
    //     return 0;
    if (n <= 1)
        return n;
    return (febo(n - 2) + febo(n - 1));
}

int main()
{
    cout<<febo(6);
    return 0; 
}