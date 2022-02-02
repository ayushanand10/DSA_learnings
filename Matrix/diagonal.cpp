#include <iostream>
using namespace std;

class diagonal
{
private:
    int n;
    int *p;

public:
    diagonal()
    {
        n = 2;
        p = new int[2];
    }
    diagonal(int n)
    {
        this->n = n;
        p = new int[n];
    }
    void input(int i, int j, int d)
    {
        if (i == j)
            p[i] = d;
    }
    int fetch(int i, int j)
    {
        if (i == j)
            return p[i];
        else
            return 0;
    }
    void display()
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                    cout << p[i] << " ";
                else
                    cout << 0 << " ";
            }
            cout << endl;
        }
    }

    ~diagonal()
    {
        cout << "Object deleted" << endl;
        delete[] p;
    }
};

int main()
{
    diagonal d1;
    d1.input(0, 0, 3);
    d1.input(1, 1, 5);
    d1.input(2, 2, 5);
    d1.display();

    diagonal d2(5);
    d2.input(0, 0, 3);
    d2.input(1, 1, 5);
    d2.input(2, 2, 5);
    d2.input(3, 3, 6);
    d2.input(4, 4, 9);
    d2.display();
    cout << d2.fetch(2, 4) << endl;
    cout << d2.fetch(4, 4) << endl;

    return 0;
}