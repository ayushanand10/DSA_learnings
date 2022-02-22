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
    }
    linkList(int *A, int n)
    {
        first = NULL;
        create(A, n);
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
    }
};

bool detectLoop(node *head)
{
    if (head == NULL)
    {
        return false;
    }
    node *slow = head, *fast = head;

    if (head->next != NULL && head->next->next != NULL)
    {
        fast = head->next->next;
    }
    while (fast != NULL && fast->next != NULL)
    {
        if (fast == slow)
            return true;
        fast = fast->next->next;
        slow = slow->next;
    }
    return false;
}

int main()
{
    int *A = new int[6]{1, 4, 3, 6, 5, 2};
    linkList p(A, 6);
    p.display();
    if (detectLoop(p.first))
        cout << "LOOP EXIST\n";
    else
        cout << "LOOP DOES NOT EXIST\n";
    return 0;
}