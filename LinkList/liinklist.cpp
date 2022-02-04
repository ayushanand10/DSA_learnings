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
    linklist()
    {
        start = NULL;
        actions();
    }
    linklist(int A[], int n);
    ~linklist();
    void actions();
    void display(node *temp);
    void insert(int data, int pos);
    void Delete(int pos);
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
    actions();
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

void linklist ::actions(void)
{
    int choise;
up:
    cout << "Actions are : " << endl;
    cout << "1 - Enter an Element" << endl;
    cout << "2 - Delete an Element" << endl;
    cout << "3 - Display list" << endl;
    cout << "4 - Exit" << endl;
    cin >> choise;
    switch (choise)
    {
    case 1:
        int data, pos;
        cout << "Enter Data and Position :";
        cin >> data >> pos;
        insert(data, pos);
        goto up;
    case 2:
        int pos;
        cout << "Enter position : ";
        cin >> pos;
        Delete(pos);
        goto up;
    case 3:
        display(start);
        goto up;
    default:
        cout << " !!! E X I T I N G !!! " << endl;
    }
}

void linklist::insert(int data, int pos)
{
}

void linklist::display(node *temp)
{
    while (temp != NULL)
    {
        cout << temp->data;
        display(temp->next);
    }
}