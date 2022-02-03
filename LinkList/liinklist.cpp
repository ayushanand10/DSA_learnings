#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node(int i)
    {
        data = i;
        next = NULL;
    }
};

class linklist
{
private:
    node *start;

public:
    linklist() { start = NULL; }
    linklist(int A[], int n);
    ~linklist();
    void display(node *temp);
};

linklist::linklist(int A[], int n)
{
    node *last, *temp;
    start = new node(A[0]);
    last = start;

    for (int i = 1; i < n; i++)
    {
        temp = new node(A[i]);
        last->next = temp;
        last = temp;
    }
}

linklist::~linklist()
{
    deletes(start);
}

void deletes(node *temp)
{
    while (temp != NULL)
    {
        deletes(temp->next);
        delete temp;
    }
}

void linklist::display(node *temp)
{
    
}