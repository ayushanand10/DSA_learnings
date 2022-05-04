#include <iostream>
#include <queue>
using namespace std;

void BFS(int G[][7], int start, int size){
    int i = start;
    int visited[size] = {0};
    queue<int> q;
    q.push(start);
    cout << i << " ";
    visited[i] = 1;

    while(!q.empty()){
        i = q.front();
        q.pop();
        for (int v = 1; v < size; v++){
            if(G[i][v] == 1 && visited[v] == 0){
                cout << v << " ";
                visited[v] = 1;
                q.push(v);
            }
        }
    }
}

void DFS(int G[][7], int start, int size, int visited[]){
    if(visited[start]==0){
        cout << start << " ";
        visited[start] = 1;
        for (int j = 0; j < size; j++){
            if(G[start][j]==1 && visited[j]==0)
                DFS(G, j, size, visited);
        }
    }
}

void DFS(int G[][7], int start, int size){
    int visited[size] = {0};
    DFS(G, start, size, visited);
}


int main(){
    int G[7][7] = {{0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 1, 1, 0, 0, 0},
                   {0, 1, 0, 0, 1, 0, 0},
                   {0, 1, 0, 0, 1, 0, 0},
                   {0, 0, 1, 1, 0, 1, 1},
                   {0, 0, 0, 0, 1, 0, 0},
                   {0, 0, 0, 0, 1, 0, 0}};

    BFS(G, 5, 7);
    cout << endl;
    DFS(G, 5, 7);

    return 0;
}