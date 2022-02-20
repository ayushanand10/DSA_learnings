#include <iostream>
#include <limits.h>
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

    int Max(node *t)
    {
        int max = INT_MIN;
        while (t != NULL)
        {
            if (max < t->data)
                max = t->data;
            t = t->next;
        }
        return max;
    }
};

int main()
{
    int a[] = {3, 5, 2, 7, 1, 4, 1};
    linklist p;
    p.create(a, 7);
    p.display(start);
    cout << "\nMax : " << p.Max(start);

    return 0;
}