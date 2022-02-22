// DRY RUN NEEDED

#include <iostream>
#include "Linklist.h"
using namespace std;

node *search(linkList obj, int key)
{
    node *temp = obj.first;
    while (temp != NULL)
    {
        if (temp->data == key)
            return temp;
        temp = temp->next;
    }
    return NULL;
}

int main()
{
    int *A = new int[6]{1, 4, 3, 6, 5, 2};
    linkList p(A, 6);
    cout << endl;
    p.display();
    int key = 9;
    search(p, key) ? cout << "\nKey Found" : cout << "\nKey Not Found";
    delete[] A;

    return 0;
}
