//      PROBLEM IN INORDER  
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

void postOrder(TreeNode *T){
    if(T==NULL){
        return;
    }
    else{
        postOrder(T->left);
        postOrder(T->right);
        cout << T->treeData << " ";
    }
}

void inOrder(TreeNode *T){
    if(T==NULL){
        return;
    }
    else{
        postOrder(T->left);
        cout << T->treeData << " ";
        postOrder(T->right);
    }
}

int main(){
    Queue Q;
    cout << "Enter Root data : ";
    int rdata;
    cin >> rdata;
    Tree tree(rdata, &Q);
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

    cout << "\nPre-order Output : ";
    preOrder(tree.root);

    cout << "\nPost-order Output : ";
    postOrder(tree.root);

    cout << "\nIn-order Output : ";
    inOrder(tree.root);

    return 0;
}