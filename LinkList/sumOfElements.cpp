#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node()
    {
        next = NULL;
    }
} *start = NULL;

class linklist
{
public:
    void create(int a[], int n)
    {
        node *temp, *last;
        temp = new node;
        start = temp;
        start->data = a[0];
        last = start;
        for (int i = 1; i < n; i++)
        {
            temp = new node;
            temp->data = a[i];
            last->next = temp;
            last = temp;
        }
    }

    void display(node *t)
    {
        if (t == NULL)
            return;
        cout << t->data << " ";
        display(t->next);
    }
    int sum(node *t)
    {
        if (t == NULL)
            return 0;

        return (sum(t->next) + t->data);
    }
};

int main()
{
    int a[] = {3, 5, 2, 7, 1, 4, 1};
    linklist p;
    p.create(a, 7);
    p.display(start);
    cout << endl
         << "Sum of elements = " << p.sum(start);
    return 0;
}