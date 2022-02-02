#include <iostream>
using namespace std;

class lowTri
{
private:
    int n;
    int *a;

public:
    lowTri()
    {
        n = 2;
        a = new int[n * (n + 1) / 2];
    }
    lowTri(int n)
    {
        this->n = n;
        a = new int[n * (n + 1) / 2];
    }
    ~lowTri()
    {
        delete[] a;
    }
    void input(int i, int j, int data);
    int fetch(int i, int j);
    void display();
};

void lowTri::input(int i, int j, int data)
{
    // Storing in Row major
    if (i >= j)
        a[i * (i + 1) / 2 + j] = data;
}

int lowTri ::fetch(int i, int j)
{
    if (i < j)
        return 0;
    return a[i * (i + 1) / 2 + j];
}

void lowTri::display()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i < j)
                cout << "0 ";
            else
                cout << a[i * (i + 1) / 2 + j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int n;
    cout << "Enter the size : ";
    cin >> n;
    lowTri o1(n);

    int x;
    cout << "Enter the elements : " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> x;
            o1.input(i, j, x);
        }
    }
    o1.display();
    return 0;
}