#include <bits/stdc++.h>
using namespace std;

class Edge{
public:
    int source;
    int dest;
    int weight;
};

Edge *TakeInput(int e){                 // fun. that take input from user <source, destination, weight>
    Edge *Input = new Edge[e];
    for (int i = 0; i < e; i++){
        int s, d, w;
        cin >> s >> d >> w;
        Input[i].source = s;
        Input[i].dest = d;
        Input[i].weight = w;
    }
    return Input;                        // Returns the pointer of input array of edges   
}

void ShowEdge(Edge *edge, int e){        // fun. to print an aray of Edges
    for (int i = 0; i < e; i++)
        cout << edge[i].source << " " << edge[i].dest << " " << edge[i].weight << endl;
}

bool compare(Edge E1, Edge E2){           // fun. for sorting Edge array on basis of weight
    return E1.weight < E2.weight;
}

int FindParent(int *Parent, int index){    // fun. to return super parent of any vertex
    while(Parent[index] != index){
        index = Parent[index];
    }
    return index;
}

Edge *Kruskal(Edge *Input, int n, int e){   // fun. to find MST using Kruskal's algorithm
    int cost = 0, edgeCount = 0;
    Edge *Output = new Edge[n - 1];          // array to store the MST

    sort(Input, Input + e, compare);         // sort Input array on basis of weight
    
    int Parent[n] = {0};                     // parent array to store parent of vertices
    for (int i = 0; i < n; i++){
        Parent[i] = i;                       // initially every vertex is parent of self
    }

    for (int i = 0, j = 0; edgeCount < n - 1 && i < e; i++)     // runs untill output has n-1 edges
    {
        int s = Input[i].source;
        int d = Input[i].dest;
        int w = Input[i].weight;
        int ParentS = FindParent(Parent, s);                // parent of source
        int ParentD = FindParent(Parent, d);                // parent of destination
        
        if(ParentS == ParentD)
            continue;                                       // if parents are same then do nothing

        Output[j].source = s;                               // coping into output array
        Output[j].dest = d;
        Output[j].weight = w;
        Parent[ParentD] = s;                                // updating the parent of destination
        edgeCount++;
        cost += w;
        j++;
    }

    return Output;
}

int main(){
    int n, e;
    cout << "Enter No. of Vertex then No. of Edges and then Source, Destination and Weight :\n";
    cin >> n >> e;
    Edge *Input = TakeInput(e);
    Edge *Output = Kruskal(Input, n, e);
    cout << "\nMST is : " << endl;
    ShowEdge(Output, n - 1);

    return 0;
}