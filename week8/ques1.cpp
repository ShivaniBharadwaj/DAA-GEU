/*Assume that a project of a road construction to connect some cities is given to your friend.
Map of these cities and roads which will connect them is provided to him in the form of a graph.
 Certain amount of rupees is associated with construction of each road.
 Your friend has to calculate the minimum budget required for this project.
 The budget should be designed in such a way that the cost of connecting the
  cities should be minimum and no. of roads required to connect all the cities should be minimum
  (if there are N cities then only N-1 roads need to be constructed). He asks you for help.
Now, you have to help your friend by designing an algorithm which will
 find minimum cost required to connect these cities.(Use Prim's algorithm)*/
#include <bits/stdc++.h>
using namespace std;
#define V 5
int minKey(int key[], bool mstSet[])
{
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;
    return min_index;
}
void printMST(int parent[], int graph[V][V])
{
    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; i++)
        cout << parent[i] << " - " << i << " \t" << graph[i][parent[i]] << " \n";
}
void primMST(int graph[V][V])
{
    int parent[V];
    int key[V];
    bool mstSet[V];
    for (int i = 0; i < V; i++)
        key[i] = INT_MAX, mstSet[i] = false;
    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V - 1; count++)
    {
        int u = minKey(key, mstSet);
        mstSet[u] = true;
        for (int v = 0; v < V; v++)
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }
    printMST(parent, graph);
}
int main()
{
    int graph[V][V] = {{1, 2, 0, 7, 0},
                       {2, 0, 3, 4, 5},
                       {0, 3, 0, 0, 7},
                       {6, 8, 0, 0, 9},
                       {0, 5, 4, 8, 0}};
    primMST(graph);
    return 0;
}
