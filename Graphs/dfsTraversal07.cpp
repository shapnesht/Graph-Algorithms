#include<bits/stdc++.h>
using namespace std;

void dfs(int i, vector<int> adj[], vector<bool>& visited, vector<int>& dfsAns) {
    visited[i] = true;
    dfsAns.push_back(i);
    for (int j = 0; j < adj[i].size(); j++)
    {
        if (visited[adj[i][j]] == 0)
        {
            dfs(adj[i][j], adj, visited, dfsAns);
        }
    }
}

int main(){
    int m, n;
    cin >> n >> m;
    vector<int> adj[n+1];
    vector<bool> visited(n+1, 0);
    vector<int> dfsAns;

    for (int i = 0; i < m; i++)
    {
        int n1, n2;
        cin >> n1 >> n2;
        adj[n1].push_back(n2);
        adj[n2].push_back(n1);
    }

    for (int i = 1; i <= n; i++)
    {
        if (visited[i] == 0) {
            dfs(i , adj, visited, dfsAns);
        }
    }

    for(int noo : dfsAns) {
        cout<<noo<<" ";
    }
      
}