#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    Node *lchild;
    int data;
    Node *rchild;
    Node(){
        lchild = nullptr;
        rchild = nullptr;
    }
};

class Tree{
protected:
    Node *root;

public:
    Tree() { root = nullptr; }
    void CreateTree();
    void Preorder(Node *p);
    void Preorder() { Preorder(root); cout << endl; } // Passing Private Parameter in Argument
    void Inorder(Node *p);
    void Inorder() { Inorder(root); cout << endl; }
    void Postorder(Node *p);
    void Postorder() { Postorder(root); cout << endl; }
    void Levelorder(Node *p);
    void Levelorder() { Levelorder(root); cout << endl; }
    int Height(Node *p);
    int Height() { return Height(root); }
};

void Tree::CreateTree(){
    Node *p;
    Node *t;
    int x;
    queue<Node *> q;

    root = new Node;
    cout << "Enter root data: " << flush;
    cin >> x;
    root->data = x;
    q.push(root);

    while (!q.empty()){
        p = q.front();
        q.pop();

        cout << "Enter left child data of " << p->data << ": " << flush;
        cin >> x;
        if (x != -1){
            t = new Node;
            t->data = x;
            p->lchild = t;
            q.push(t);
        }

        cout << "Enter right child data of " << p->data << ": " << flush;
        cin >> x;
        if (x != -1){
            t = new Node;
            t->data = x;
            p->rchild = t;
            q.push(t);
        }
    }
}

void Tree::Preorder(Node *p){
    if (p){
        cout << p->data << ", ";
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}

void Tree::Inorder(Node *p){
    if (p){
        Inorder(p->lchild);
        cout << p->data << ", " << flush;
        Inorder(p->rchild);
    }
}

void Tree::Postorder(Node *p){
    if (p){
        Postorder(p->lchild);
        Postorder(p->rchild);
        cout << p->data << ", " << flush;
    }
}

void Tree::Levelorder(Node *p){
    queue<Node *> q;
    cout << root->data << ", ";
    q.push(root);

    while (!q.empty()){
        p = q.front();
        q.pop();

        if (p->lchild){
            cout << p->lchild->data << ", ";
            q.push(p->lchild);
        }

        if (p->rchild){
            cout << p->rchild->data << ", ";
            q.push(p->rchild);
        }
    }
}

int Tree::Height(Node *p){
    int l = 0;
    int r = 0;
    if (p == nullptr)
        return 0;

    l = Height(p->lchild);
    r = Height(p->rchild);

    if (l > r)
        return l + 1;
    else
        return r + 1;
}
