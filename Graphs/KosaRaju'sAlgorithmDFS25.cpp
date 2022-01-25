#include <bits/stdc++.h>
using namespace std;

void DFS(int node, vector<int> adj[], vector<int>& vis, stack<int>& topo) {
    vis[node] =true;
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            DFS(it, adj, vis, topo);
        }
    }
    topo.push(node);
}

void reverseDFS(int node, vector<int> transpose[], vector<int>& vis) {
    cout<<node<<" ";
    vis[node] = true;

    for (auto it : transpose[node])
    {
        if (!vis[it])
        {
            reverseDFS(it, transpose, vis);
        }
    }
}

int main(){
    // Input.
    int n,e;
    cin>>n>>e;
    vector<int> adj[n + 1];
    for (int i = 0; i < e; i++)
    {
        int n1,n2;
        cin>>n1>>n2;
        adj[n1].push_back(n2);
    }
    // Calculate Topological Sort.
    stack<int> topo;
    vector<int> vis(n+1, 0);
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            DFS(i, adj, vis, topo);
        }
    }
    // Calculate Transpose.
    vector<int> transpose[n+1];
    for (int i = 1; i <= n; i++)
    {
        vis[i] = 0; // Preparing vis[] for next DFS
        for (auto it : adj[i])
        {
            transpose[it].push_back(i);
        }
    }
    // Do DFS for Connected components in Transpose List.
    while (!topo.empty())
    {
        int node = topo.top();
        topo.pop();
        if (!vis[node])
        {
            cout<<"SCC:\n";
            reverseDFS(node, transpose, vis);
            cout<<"\n";
        }
    }
    
    
}