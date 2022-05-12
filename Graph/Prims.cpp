#include <bits/stdc++.h>
using namespace std;

void TakeInput(int **&A, int n){
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> A[i][j];
}

int *Prims(int **&A, int n){
    bool visited[n];
    int *parent = new int[n];
    int weight[n];
    for (int i = 0; i < n; i++){
        visited[i] = false;
        parent[i] = i;
        weight[i] = INT_MAX;
    }
    int v = 3;
    visited[v] = true;
    weight[v] = 0;
    int t = n;
    while(t--){
        for (int i = 0; i < n;i++){
            if (A[v][i] != 0 && visited[i] == false){
                if (A[v][i] < weight[i]){
                    parent[i] = v;
                    weight[i] = A[v][i];
                }
            }
        }
        int min = INT_MAX;
        for (int j = 0; j < n; j++){
            if(visited[j] == false && weight[j] < min){
                v = j;
                min = weight[j];
            }
        }
        visited[v] = true;
    }
    return parent;
}

int main(){
    int n;
    cin >> n;
    int **Arr = new int*[n];
    for (int i = 0; i < n; i++){
        Arr[i] = new int[n]{0};
    }

    TakeInput(Arr, n);

    int *MST = Prims(Arr, n);

    for (int i = 0; i < n; i++)
        if(i != MST[i])
            cout << i << " " << MST[i] << endl;

    return 0;
}