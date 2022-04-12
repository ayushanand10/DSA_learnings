#include<iostream>
using namespace std;

class Node{
public:
    Node *lchild;
    int data;
    int height;
    Node *rchild;
};

class AVL{
protected:
    Node *root;
public:
    AVL() { root = nullptr; }

    int NodeHeight(Node *p);
    int BalanceFactor(Node *p);
    Node *LLrotation(Node *p);
    Node *LRrotation(Node *p);
    Node *RRrotation(Node *p);
    Node *RLrotation(Node *p);

    Node *rInsert(Node *p, int);
    void rInsert(int key) { root = rInsert(root, key); }

    void Preorder(Node *p);
    void Preorder() { Preorder(root); cout << endl; }
    void Inorder(Node* p);
    void Inorder(){ Inorder(root); }
};

int AVL::NodeHeight(Node *p){
    int hleft, hright;

    if (p && p->lchild)
        hleft = p->lchild->height;
    else
        hleft = 0;
    
    if (p && p->rchild)
        hright = p->rchild->height;
    else
        hright = 0;

    return hleft > hright ? hleft + 1 : hright + 1;
}

int AVL::BalanceFactor(Node *p){
    int hleft, hright;

    if (p && p->lchild)
        hleft = p->lchild->height;
    else
        hleft = 0;
    
    if (p && p->rchild)
        hright = p->rchild->height;
    else
        hright = 0;

    return hleft - hright;
}

Node *AVL::LLrotation(Node *p){
    Node *pl = p->lchild;
    Node *plr = pl->rchild;
    pl->rchild = p;
    p->lchild = plr;
    p->height = NodeHeight(p);
    pl->height = NodeHeight(pl);

    if(root == p)
        root = pl;
    return pl;
}

Node *AVL::LRrotation(Node *p){
    Node *pl = p->lchild;
    Node *plr = pl->rchild;

    pl->rchild = plr->lchild;
    p->lchild = plr->rchild;

    plr->lchild = pl;
    plr->rchild = p;

    pl->height = NodeHeight(pl);
    p->height = NodeHeight(p);
    plr->height = NodeHeight(plr);

    if(root == p)
        root = plr;
    return plr;
}

Node *AVL::rInsert(Node *p, int key){
    Node *t = nullptr;
    if(p == nullptr){
        t = new Node;
        t->data = key;
        t->lchild = nullptr;
        t->rchild = nullptr;
        t->height = 1;
        return t;
    }
    if(p->data == key)
        return p;
    if(key < p->data)
        p->lchild = rInsert(p->lchild, key);
    else
        p->rchild = rInsert(p->rchild, key);

    p->height = NodeHeight(p);

    if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == 1)
        return LLrotation(p);
    else if(BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == -1)
        return LRrotation(p);
    // else if(BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == -1)
    //     return RRrotation(p);
    // else if(BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == 1)
    //     return RLrotation(p);

    return p;
}

void AVL :: Preorder(Node *p){
    if (p){
        cout << p->data << ", ";
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}

void AVL::Inorder(Node *p) {
    if (p){
        Inorder(p->lchild);
        cout << p->data << ", " << flush;
        Inorder(p->rchild);
    }
}

int main(){
    AVL t;
    t.rInsert(30);
    t.rInsert(20);
    t.rInsert(40);
    t.rInsert(10);
    t.rInsert(25);
    t.rInsert(50);
    t.rInsert(5);
    t.rInsert(15);
    t.rInsert(28);

    t.Preorder();

    t.rInsert(4);
    t.Preorder();
    // t.rInsert();
    return 0;
}