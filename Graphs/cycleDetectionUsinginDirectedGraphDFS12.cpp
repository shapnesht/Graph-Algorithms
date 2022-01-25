#include <bits/stdc++.h>
using namespace std;

bool checkDFScycle(int node, vector<int> adj[],bool vis[],bool DFSvis[]) {
    vis[node] = 1;
    DFSvis[node] = 1;

    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            if (checkDFScycle(it, adj, vis, DFSvis)) return true;
        }
        else if (DFSvis[it] == 1)
        {
            return true;
        }
    }
    DFSvis[node] = 0;
    return false;
}

bool checkCycle(vector<int> adj[],int n) {
    bool vis[n+1];
    bool DFSvis[n+1];
    memset(vis, 0, sizeof(vis));
    memset(DFSvis, 0, sizeof(DFSvis));

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            if (checkDFScycle(i, adj, vis, DFSvis)) return true;
        }
    }
    return false;
}

int32_t main()
{
    int n,e;
    cin>>n>>e;

    vector<int> adj[n + 1];

    for (int i = 0; i < e; i++)
    {
        int n1,n2;
        cin>>n1>>n2;
        adj[n1].push_back(n2);
    }
    
    if (checkCycle(adj, n))
    {
        cout<<"Yes, It is Directed Cyclic graph."<<endl;
    }
    else
    {
        cout<<"No, It is not a Directed Cyclic graph."<<endl;
    }
}