#include<iostream>
#include "BinaryTree.h"
using namespace std;

class Tree{
public:
    TreeNode *root;

    Tree(int data, Queue *Q){
        root = new TreeNode(data);
        Enqueue(Q, root);
    }
};

void preOrder(TreeNode *T){
    if(T==NULL){
        return;
    }
    else{
        cout << T->treeData << " ";
        preOrder(T->left);
        preOrder(T->right);
    }
}

Tree *Create(){
    Queue Q;
    cout << "Enter Root data : ";
    int rootdata;
    cin >> rootdata;

    Tree *tree = new Tree(rootdata, &Q);

    TreeNode *p = Dequeue(&Q);
    while(p){
        TreeNode *t;
        cout << "Enter Left child value of : " << p->treeData << endl;
        int ldata;
        cin >> ldata;
        if(ldata != -1){
            t = new TreeNode(ldata);
            p->left = t;
            Enqueue(&Q, t);
        }

        cout << "Enter Right child value of : " << p->treeData << endl;
        int rdata;
        cin >> rdata;
        if(rdata != -1){
            t = new TreeNode(rdata);
            p->right = t;
            Enqueue(&Q, t);
        }

        p = Dequeue(&Q);
    }
    cout << "Tree successufully Created.\n";

    preOrder(tree->root);

    return tree;
}


int main(){
    Tree *tree;
    cout << "IN MAIN BEFORE CREATE()\n";
    tree = Create();
    cout << "IN MAIN AFTER CREATE()\n";
    cout << "Pre-order Output : ";
    preOrder(tree->root);

    return 0;
}