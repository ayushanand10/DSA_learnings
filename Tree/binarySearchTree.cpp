#include <iostream>
#include "BTree.h"
using namespace std;

class BST : public Tree{
public:
    Node *rSearch(Node *p, int key);
    Node *rSearch(int key) { return rSearch(root, key); }

    Node *iSearch(Node *p, int key);
    Node *iSearch(int key) { return iSearch(root, key); }
};

Node *BST::rSearch(Node *p, int key){
    if (p == NULL)
        return NULL;
    else{
        if(p->data == key)
            return p;
        if(key < p->data)
            return rSearch(p->lchild, key);
        else
            return rSearch(p->rchild, key);
    }
}

Node *BST::iSearch(Node *p, int key){
    while(p){
        if(p->data == key)
            return p;
        if(key < p->data)
            p = p->lchild;
        else
            p = p->rchild;
    }
    return NULL;
}

int main(){
    BST t;
    t.CreateTree();

    Node *k = t.rSearch(5);
    if(k)
        cout << " Element Found at " << k << endl;
    else
        cout << " Element NOT Found \n";
    
    k = t.iSearch(61);
    if(k)
        cout << " Element Found at " << k << endl;
    else
        cout << " Element NOT Found \n";

    return 0;
}