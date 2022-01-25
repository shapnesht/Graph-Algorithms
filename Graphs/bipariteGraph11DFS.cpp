#include<bits/stdc++.h>
using namespace std;

bool bipartiteDFS(int node,vector<int> adj[],int colors[]) {
    colors[node] = 1;
    for (auto it : adj[node])
    {
        if (colors[it] == -1)
        {
            colors[it] = 1 - colors[node];
            if (!bipartiteDFS(it, adj, colors))
            {
                return false;
            }
        }
        else if (colors[node] == colors[it])
        {
            return false;
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
            if (!bipartiteDFS(i, adj, colors))
            {
                return false;
            }
        }
    }
    return true;
}

int main(){
    int n,e;
    cin>>n>>e;

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