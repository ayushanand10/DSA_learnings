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
            last->next = t;
            last = t;
        }
        last->next = NULL;
    }
    int countIterative(Node *t)
    {
        int count = 0;
        while (t)
        {
            count++;
            t = t->next;
        }
        return count;
    }
    int countRecursive(Node *t)
    {
        if (t == NULL)
            return 0;
        return countRecursive(t->next) + 1;
    }
};

int main()
{
    linkList p;
    int A[] = {1, 62, 13, 9, 5}, n = 5;
    p.create(A, n);
    cout << "Iterative count :" << p.countIterative(first) << endl;
    cout << "Recursive count :" << p.countRecursive(first) << endl;
    return 0;
}