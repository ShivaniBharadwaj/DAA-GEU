/* Given a directed graph, design an algorithm and implement it using a program to find whether cycle exists in the graph or not .*/
#include <bits/stdc++.h>
    using namespace std;

    bool CheckCycle(int node, vector<int> adj[], int vis[], int dfsvis[])
    {
        vis[node] = 1;
        dfsvis[node] = 1;
        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                if (CheckCycle(it, adj, vis, dfsvis))
                    return true;
            }
            else if (dfsvis[it])
                return true;
        }
        dfsvis[node] = 0;
        return false;
    }
    bool isCycle(vector<int> adj[], int N)
    {

        int vis[N + 1], dfsVis[N + 1];
        memset(vis, 0, sizeof(vis));
        memset(dfsVis, 0, sizeof(dfsVis));
        for (int i = 1; i <= N; i++)
        {
            if (!vis[i])
            {
                if (CheckCycle(i, adj, vis, dfsVis))
                    return true;
            }
        }
        return false;
    }
    int main()
    {
        int n, m; // n=no of Vertices, m= no of lines of edges
        cout << "enter n and m" << endl;
        cin >> n >> m;
        vector<int> adj[n + 1];

        cout << "enter the nodes between there is edge" << endl;
        for (int i = 1; i <= m; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        if (isCycle(adj, n))
            cout << "Cycle Detected" << endl;
        else
            cout << "Cycle Not Detected" << endl;
        return 0;
    }

