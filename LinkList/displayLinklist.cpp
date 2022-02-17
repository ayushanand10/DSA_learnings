#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
} *first = NULL;

class linkList
{
public:
    void create(int A[], int n)
    {
        Node *last, *t;
        first = new Node;
        first->data = A[0];
        first->next = NULL;
        last = first;
        for (int i = 1; i < n; i++)
        {
            t = new Node;
            t->data = A[i];
            // t->next = NULL;
            last->next = t;
            last = t;
        }
        last->next = NULL;
    }
    void displayIterative()
    {
        Node *t;
        t = first;
        while (t)
        {
            cout << t->data << " ";
            t = t->next;
        }
    }
    void displayRecursive(Node *t)
    {
        if (t == NULL)
            return;
        cout << t->data<<" ";
        displayRecursive(t->next);
        // // agr cout statement ko neche likhenge to ulta print ho jayega
        // cout << t->data<<" ";
    }
};

int main()
{
    linkList p;
    int A[] = {1, 62, 13, 9, 5}, n = 5;
    p.create(A, n);
    // p.displayIterative();
    p.displayRecursive(first);
    return 0;
}