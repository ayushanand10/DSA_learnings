#include <iostream>
using namespace std;

class element
{
public:
    int i;
    int j;
    int value;
};

class sparse
{
private:
    int m;
    int n;
    int num;
    element *ele;

public:
    sparse(int m, int n, int num)
    {
        this->m = m;
        this->n = n;
        this->num = num;
        ele = new element[this->num];
        create();
    }
    ~sparse()
    {
        delete[] ele;
    }

    void create(void)
    {
        int i, j, val;
        for (int a = 0; a < num; a++)
        {
            cout << "Enter i : ";
            cin >> i;
            cout << "Enter j : ";
            cin >> j;
            cout << "Enter non-zero value : ";
            cin >> val;
            ele[a].i = i;
            ele[a].j = j;
            ele[a].value = val;
        }
    }

    void showSparse(void)
    {
        cout << " i j value" << endl;
        cout << "|-|-|-----|" << endl;
        for (int a = 0; a < num; a++)
            cout << " " << ele[a].i << " " << ele->j << " " << ele->value << endl;
    }

    void fullDisplay()
    {
        for (int c = 0, a = 0; a < m; a++)
        {
            for (int b = 0; b < n; b++)
            {
                if (a == ele[c].i && b == ele[c].j)
                    cout << ele[c++].value << " ";
                else
                    cout << "0 ";
            }
            cout << endl;
        }
    }
};

int main()
{
    int m, n, non0;
    cout << "Enter m, n and number of non-zero elements : ";
    cin >> m >> n >> non0;
    sparse obj(m, n, non0);

    cout << "The Sparse matrix is : " << endl;
    obj.showSparse();

    cout << "The Full matrix is : " << endl;
    obj.fullDisplay();

    return 0;
}
