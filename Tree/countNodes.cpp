#include<iostream>
#include "BTree.h"
using namespace std;

class CountNode : public Tree{
public:
    int countNode(Node *p){
        int x, y;
        if(p != NULL){
            x = countNode(p->lchild);
            y = countNode(p->rchild);
            return x + y + 1;
        }
        else{
            return 0;
        }
    }
    int countNode(){
        return countNode(root);
    }

    int countDeg2Nodes(Node *p){
        int x, y;
        if(p != NULL){
            x = countDeg2Nodes(p->lchild);
            y = countDeg2Nodes(p->rchild);

            if(p->lchild && p->rchild)
                return x + y + 1;
            else
                return x + y;
        }
        else{
            return 0;
        }
    }
    int countDeg2Nodes(){
        return countDeg2Nodes(root);
    }

    int countDeg1Nodes(Node *p){
        int x, y;
        if(p != NULL){
            x = countDeg1Nodes(p->lchild);
            y = countDeg1Nodes(p->rchild);

            if ((!p->lchild && p->rchild) || (p->lchild && !p->rchild))
                return x + y + 1;
            else
                return x + y;
        }
        else{
            return 0;
        }
    }
    int countDeg1Nodes(){
        return countDeg1Nodes(root);
    }

    int countLeafNode(Node *p){
        int x, y;
        if (p != NULL){
            x = countLeafNode(p->lchild);
            y = countLeafNode(p->rchild);

            if(p->lchild==NULL && p->rchild==NULL)
                return x + y + 1;
            else
                return x + y;
        }
        else{
            return 0;
        }
    }
    int countLeafNode(){
        return countLeafNode(root);
    }
};


int main(){
    CountNode obj;
    obj.CreateTree();
    cout << "Total No. of Nodes = " << obj.countNode() << endl;
    cout << "Nodes with Degree 2 = " << obj.countDeg2Nodes() << endl;
    cout << "Nodes with Degree 1 = " << obj.countDeg1Nodes() << endl;
    cout << "No. of Leaf Nodes = " << obj.countLeafNode() << endl;
    return 0;
}