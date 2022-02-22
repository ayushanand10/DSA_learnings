//  DRY RUN NEEDED

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
};
class linkList
{
public:
    node *first;
    void create(int *A, int n)
    {
        node *last, *t;
        first = new node;
        first->data = A[0];
        last = first;
        for (int i = 1; i < n; i++)
        {
            t = new node;
            t->data = A[i];
            last->next = t;
            last = t;
        }
        cout << "\nLinklist Created";
    }
    void display()
    {
        node *t;
        t = first;
        while (t)
        {
            cout << t->data << " ";
            t = t->next;
        }
        cout << "\nDisplay () Ended";
    }
    linkList(int *A, int n)
    {
        first = NULL;
        create(A, n);
        cout << "\nConstructor Called";
    }
    ~linkList()
    {
        node *last, *next;
        last = first;
        while (last != NULL)
        {
            next = last->next;
            delete last;
            last = next;
        }
        cout << "\nLinklist Deleted\n";
    }
};