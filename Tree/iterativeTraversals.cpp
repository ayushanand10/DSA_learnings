#include <stack>
#include <queue>
#include <iostream>
#include "BTree.h"
using namespace std;

class ExtendTree : public Tree{
public:
    void iPreorder(Node *p, stack<Node *> &st);
    void iPreorder() {
        stack<Node *> st;
        iPreorder(root, st); 
    }

    void iPostorder(Node *p, stack<Node *> &st);
    void iPostorder() {
        stack<Node *> st;
        iPostorder(root, st); 
    }

    void iInorder(Node *p, stack<Node *> &st);
    void iInorder() {
        stack<Node *> st;
        iInorder(root, st); 
    }

};

void ExtendTree ::iPreorder(Node *p, stack<Node *> &st){
    cout << "Pre-Order Traversal : ";
    while (p != NULL || !st.empty()){
        if(p != NULL){
            cout << p->data << ", ";
            st.push(p);
            p = p->lchild;
        }
        else{
            p = st.top();
            st.pop();
            p = p->rchild;
        }
    }
    cout << endl;
}

void ExtendTree ::iPostorder(Node *p, stack<Node *> &st){
    long long temp;
    cout << "Post-Order Traversal : ";
    while (p != NULL || !st.empty()){
        if(p != NULL){
            st.push(p);
            p = p->lchild;
        }
        else{
            temp =(long long) st.top();
            st.pop();
            if(temp > 0){
                st.push((Node *) -temp);
                p = ((Node *)temp)->rchild;
            }
            else{
                cout << ((Node *) -temp)->data<<", ";
                p = nullptr;
            }
        }
    }
    cout << endl;
}

void ExtendTree ::iInorder(Node *p, stack<Node *> &st){
    cout << "In-Order Traversal : ";
    while (p != NULL || !st.empty()){
        if(p != NULL){
            st.push(p);
            p = p->lchild;
        }
        else{
            p = st.top();
            st.pop();
            cout << p->data << ", ";
            p = p->rchild;
        }
    }
    cout << endl;
}

int main(){
    ExtendTree bt;
    bt.CreateTree();
    bt.iPreorder();
    bt.iInorder();
    bt.iPostorder();
    // bt.CreateTree();


    
}