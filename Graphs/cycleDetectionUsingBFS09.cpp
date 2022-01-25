#include<bits/stdc++.h>
using namespace std;

bool cycleBFS(int i, vector<int> adj[], vector<bool>& visited) {
    visited[i] = true;
    queue<pair<int, int>> q;
    q.push({i, -1});

    while (!q.empty())
    {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();
        for (auto value : adj[node])
        {
            if (!visited[value])
            {
                visited[value] = true;
                q.push({value, node});
            }
            else if (value != parent)
            {
                return true;
            }
            
        }
        
    }
    return false;
}

bool checkCycleBFS(int n, vector<int> adj[]) {
    vector<bool> visited(n+1, 0);
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i] && cycleBFS(i, adj, visited))
        {
            return true;
        }
        
    }
    return false;
}

int main(){
    int n, m;
    cin >> n >> m;

    vector<int> adj[n+1];

    for (int i = 0; i < m; i++)
    {
        int n1, n2;
        cin >> n1 >> n2;

        adj[n1].push_back(n2);
        adj[n2].push_back(n1);
    }
    
    cout<<checkCycleBFS(n, adj);
}