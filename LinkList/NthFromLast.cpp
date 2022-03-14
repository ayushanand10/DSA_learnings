/*  We need to find the Nth Node from end of linked list
https://practice.geeksforgeeks.org/problems/nth-node-from-end-of-linked-list/1/?page=1&difficulty[]=0&category[]=Linked%20List&sortBy=submissions */

#include <iostream>
#include "Linklist.h"

int getNthFromLast(node *head, int n)
{
    int count = 0;
    if (head->next == NULL)
    {
        if (n == 1)
            return head->data;
        else
            return -1;
    }
    node *f = head, *s = head;
    while (f)
    {
        if (count == n)
            s = s->next;
        else
            count++;
        f = f->next;
    }
    if (count == n)
    {
        return s->data;
    }
    return -1;
}
