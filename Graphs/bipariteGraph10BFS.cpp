#include <bits/stdc++.h>
#define int long long int
using namespace std;

bool bipartiteBFS(int node,vector<int> adj[],int colors[]) {
    queue<int> q;
    q.push(node);
    colors[node] = 1;

    while (!q.empty())
    {
        int innerNode = q.front();
        q.pop();
        
        for (int i : adj[node])
        {
            if (colors[i] == -1)
            {
                colors[i] = 1 - colors[node];
            }
            else if (colors[i] == colors[node])
            {
                return false;
            }
        }
    }
    return true;
}

bool checkBipartite(vector<int> adj[], int n) {
    int colors[n+1];
    memset(colors, -1, sizeof(colors));

    for (int i = 1; i <= n; i++)
    {
        if (colors[i] == -1)
        {
            if (!bipartiteBFS(i, adj, colors))
            {
                return false;
            }
        }
    }
    return true;
}

int32_t main()
{
    int n, e;
    vector<int> adj[n + 1];
    for (int i = 0; i < e; i++)
    {
        int n1,n2;
        cin>>n1>>n2;
        adj[n1].push_back(n2);
        adj[n2].push_back(n1);
    }
    
    if (checkBipartite(adj, n))
    {
        cout<<"Yes, It is Bipartite graph."<<endl;
    }
    else
    {
        cout<<"No, It is not a Bipartite graph."<<endl;
    }
    
}