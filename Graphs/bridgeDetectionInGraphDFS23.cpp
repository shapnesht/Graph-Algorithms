#include <bits/stdc++.h>
using namespace std;

void DFS(int node, int parent, int& timer, vector<int> adj[], vector<bool>& vis, vector<int>& timeInitial, vector<int>& low) {
    vis[node] = true;
    timeInitial[node] = low[node] = timer++;

    for (auto it : adj[node])
    {
        if (it == parent) continue;
        if (!vis[it])
        {
            DFS(it, node, timer, adj, vis, timeInitial, low);
            low[node] = min(low[node], low[it]);
            if (low[it] > timeInitial[node])
            {
                cout<<node<<"--"<<it<<endl;
            }
        }
        else
        {
            low[node] = min(low[node], timeInitial[it]);
        }
    }
}

int main() {
    int n, e;
    cin>> n >> e;
    vector<int> adj[n + 1];
    for (int i = 0; i < e; i++)
    {
        int n1,n2;
        cin>>n1>>n2;
        adj[n1].push_back(n2);
        adj[n2].push_back(n1);
    }

    int timer = 0;

    vector<bool> vis(n+1, 0);
    vector<int> timeInitial(n+1, -1);
    vector<int> low(n+1, -1);

    for (int i = 1; i < n+1; i++)
    {
        if (!vis[i])
        {
            DFS(i, -1, timer, adj, vis, timeInitial, low);
        }
    }
    
}