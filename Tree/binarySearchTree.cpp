#include <iostream>
#include "BTree.h"
using namespace std;

class BST : public Tree{
public:
    Node *rSearch(Node *p, int key);
    Node *rSearch(int key) { return rSearch(root, key); }

    Node *iSearch(Node *p, int key);
    Node *iSearch(int key) { return iSearch(root, key); }

    Node *rInsert(Node *p, int key);
    void rInsert(int key) { root = rInsert(root, key); }

    Node *iInsert(Node *p, int key);
    void iInsert(int key) { root = iInsert(root, key); }

    Node *inPre(Node *p);
    Node *inSucc(Node *p);

    Node *Delete(Node *p, int key);
    void Delete(int key) { Delete(root, key); }

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

Node *BST :: rInsert(Node *p, int key){
    Node *t = nullptr;
    if (p == nullptr){
        t = new Node;
        t->data = key;
        return t;
    }
    if (p->data == key)
        return p;
    if(key < p->data)
        p->lchild = rInsert(p->lchild, key);
    else
        p->rchild = rInsert(p->rchild, key);
}

Node *BST :: iInsert(Node *p, int key){
    Node *tail = nullptr;
    Node *root = p;
    while(p){
        if(key < p->data){
            tail = p;
            p = p->lchild;
        }
        else if (key > p->data){
            tail = p;
            p = p->rchild;
        }
        else
            return root;
    }
    Node *t = new Node;
    t->data = key;

    if(tail == nullptr){
        return t;
    }
    else{
        if(key < tail->data){
            tail->lchild = t;
            return root;
        }
        else{
            tail->rchild = t;
            return root;
        }
    }
}

Node *BST :: inPre(Node *p){
    while (p && p->rchild)
        p = p->rchild;
    return p;
}

Node *BST :: inSucc(Node *p){
    while (p && p->lchild)
        p = p->lchild;
    return p;
}

Node *BST:: Delete(Node *p, int key){
    Node *q;
    if (p == nullptr)
        return p;
    if (p->lchild == nullptr && p->rchild == nullptr){
        if(p==root){
            root == NULL;
        }
        delete p;
        return NULL;
    }

    if (key < p->data)
        p->lchild = Delete(p->lchild, key);
    else if (key > p->data)
        p->rchild = Delete(p->rchild, key);
    else{
        if (Height(p->lchild) > Height(p->rchild)){
            q = inPre(p->lchild);
            p->data = q->data;
            p->lchild = Delete(p->lchild, q->data);
        }
        else{
            q = inSucc(p->rchild);
            p->data = q->data;
            p->rchild = Delete(p->rchild, q->data);
        }
    }
}

int main(){
    BST t;
    // t.CreateTree();

    // Node *k = t.rSearch(5);
    // if(k)
    //     cout << " Element Found at " << k << endl;
    // else
    //     cout << " Element NOT Found \n";
    
    // k = t.iSearch(61);
    // if(k)
    //     cout << " Element Found at " << k << endl;
    // else
    //     cout << " Element NOT Found \n";

    // t.iInsert(26);
    // t.Inorder();

    t.rInsert(40);
    t.rInsert(50);
    t.rInsert(30);
    t.rInsert(25);
    t.rInsert(45);
    t.rInsert(20);
    t.rInsert(35);
    t.rInsert(32);
    t.Inorder();

    t.Delete(30);
    t.Inorder();
    return 0;
}