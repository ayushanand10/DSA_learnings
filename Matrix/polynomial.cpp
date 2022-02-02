#include <iostream>
using namespace std;

class term
{
public:
    int coef;
    int deg;
    term()
    {
        coef = 0;
    }
};

class polynomial
{
private:
    int non0;
    term *ptr;

public:
    polynomial(int non0)
    {
        this->non0 = non0;
        ptr = new term[non0];
        create();
    }

    ~polynomial()
    {
        delete[] ptr;
    }

    void create(void)
    {
        cout << "Enter coefficient and degree : " << endl;
        for (int i = 0; i < non0; i++)
        {
            cin >> ptr[i].coef;
            cin >> ptr[i].deg;
        }
        cout << "Polynomial Successfully registered !!" << endl;
    }

    void display(void)
    {
        cout << "Polynomial is : ";
        for (int i = 0; i < non0; i++)
        {
            cout << ptr[i].coef << "x^" << ptr[i].deg;
            if (i != non0 - 1)
                cout << " + ";
        }
    }

    int value(int x)
    {
        int value = 0;
        for (int i = 0; i < non0; i++)
        {
            int v = 1, deg = ptr[i].deg;
            while (deg-- != 0)
                v *= x;
            value += (v * ptr[i].coef);
        }
        return value;
    }
};

int main()
{
    cout << "Enter number of non-zero terms : ";
    int n;
    cin >> n;
    polynomial p(n);
    p.display();
    cout << endl << "Enter the value of x : ";
    int x;
    cin >> x;
    cout << "Value of the polynomial = " << p.value(x);
    return 0;
}