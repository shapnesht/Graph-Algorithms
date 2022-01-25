#include<bits/stdc++.h>
using namespace std;

bool detectCycleDFS(int node, int parent, vector<int> adj[], vector<bool>& visited) {
    visited[node] = true;
    for(auto val : adj[node]) {
        if (visited[val]==0)
        {
            if(detectCycleDFS(val, node, adj, visited)) {
                return true;
            }
        }
        else if (val != parent)
        {
            return true;
        }
    }
    return false;
}

bool dfsTraversalCheck (int n, vector<int> adj[]) {
    vector<bool> visited(n+1, false);

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            if (detectCycleDFS(i, -1, adj, visited))
            {
                return true;
            }
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
    
    cout<<dfsTraversalCheck(n, adj)<<endl;
}