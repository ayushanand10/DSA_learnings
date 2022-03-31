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
};

int main(){
    CountNode obj;
    obj.CreateTree();
    cout << "No. of Nodes = " << obj.countNode() << endl;
    return 0;
}