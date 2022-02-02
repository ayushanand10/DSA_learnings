#include <iostream>
using namespace std;

double fact(int n)
{
    if (n == 0)
        return 1;
    else
        return fact(n - 1) * n;
}

double power(int x, int exp)
{
    if (exp == 0)
        return 1;
    return power(x, exp - 1) * x;
}

double e(int x, int n)
{
    if (n == 1)
        return 1;
    return (e(x, n - 1) + power(x, n - 1) / fact(n - 1));
}

int main()
{
    cout << e(4, 10);
    // cout<<fact(5)<<" "<<power(2,4);
    return 0;
}