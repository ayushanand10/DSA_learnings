#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

class linklist
{
private:
    node *start;
    int size;

public:
    linklist()
    {
        start = NULL;
        size = 0;
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
    size = 1;

    for (int i = 1; i < n; i++)
    {
        temp = new node(A[i]);
        last->next = temp;
        last = temp;
        size++;
    }
    actions();
}
void deletes(node *temp)
{
    while (temp != NULL)
    {
        deletes(temp->next);
        delete temp;
    }
}

linklist::~linklist()
{
    deletes(start);
}

void linklist ::actions(void)
{
    int choise;
    int data, pos;
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
        cout << "Enter Data and Position :";
        cin >> data >> pos;
        insert(data, pos);
        goto up;
    case 2:
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
    if (pos > 0 && pos <= size + 1)
    {
        node *temp;
        temp = new node(data);
        size++;
        if (pos == 1)
        {
            temp->next = start;
            start = temp;
        }
        else if (pos == size + 1)
        {
            node *temp2 = start;
            for (int i = 1; i < size; i++)
                temp2 = temp2->next;
            temp2->next = temp;
        }
        else
        {
            node *temp2 = start;
            for (int i = 1; i < pos - 1; i++)
                temp2 = temp2->next;
            temp->next = temp2->next;
            temp2->next = temp;
        }
    }
    else
    {
        cout << "!!! INVALID POSITION !!!" << endl;
    }
}

void linklist::display(node *temp)
{
    while (temp != NULL)
    {
        cout << temp->data;
        display(temp->next);
    }
}

// Delete function missing



int main()
{
// main missing
    return 0;
}