#include<iostream>
#include<limits.h>
using namespace std;

void TakeInput(int **&A, int n){
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> A[i][j];
}

int findMinVertex(int *cost, bool *visited, int n){

    int minCost = INT_MAX;
    int minVertex = -1;

    for (int i = 0; i < n; i++){
        if (!visited[i] && cost[i] < minCost){
            minVertex = i;
            minCost = cost[i];
        }
    }

    return minVertex;
}

int *Dijkstra(int **Edge, int n, int source){
    
    bool *visited = new bool[n];
    int *cost = new int[n];
    for (int i = 0; i < n; i++){
        visited[i] = false;
        cost[i] = INT_MAX;        
    }
    
    cost[source] = 0;
    int t = n;
    while (t--){
        int minVertex = findMinVertex(cost, visited, n);
        visited[minVertex] = true;
        for (int i = 0; i < n; i++){
            if (Edge[minVertex][i] && !visited[i]){
                int tempCost = cost[minVertex] + Edge[minVertex][i];
                if (tempCost < cost[i]){
                    cost[i] = tempCost;
                }
            }
        }
    }
    delete[] visited;
    return cost;
}

int main(){
    int n;
    cin >> n;
    int **Arr = new int*[n];
    for (int i = 0; i < n; i++){
        Arr[i] = new int[n]{0};
    }

    TakeInput(Arr, n);

    int source;
    cout << "Enter the source : ";
    cin >> source;
    int *cost = Dijkstra(Arr, n, source);
    for (int i = 0; i < n; i++){
        cout << "Cost of " << source << " to " << i << " : " << cost[i] << endl;
    }

    delete[] Arr;
    delete[] cost;
    return 0;
}