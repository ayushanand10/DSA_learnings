/*    Sparse Matrix Implementation Using Linklist    */

#include<iostream>
using namespace std;

class Node{
public:
    int col, value;
    Node *next;
    Node(int col, int value){
        this->col = col;
        this->value = value;
        next = NULL;
    }
};

int main(){
    const int m = 3, n = 4;
    int A[m][n] = {{0, 2, 0, 0}, {1, 0, 5, 0}, {8, 0, 0, 0}};
    Node *ptr[m] = {};

    for (int i = m - 1 ; i >= 0; i--){
        for (int j = n - 1 ; j >= 0;j--){
            if(A[i][j] != 0){
                Node *temp = new Node(j, A[i][j]);
                temp->next = ptr[i];
                ptr[i] = temp;
            }
        }
    }

    for (int i = 0; i < m; i++){
        Node *temp = ptr[i];
        while(temp){
            cout << i << "," << temp->col << " : " << temp->value << endl;
            temp = temp->next;
        }
    }

    return 0;
}