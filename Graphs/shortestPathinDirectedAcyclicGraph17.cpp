#include <bits/stdc++.h>
using namespace std;

int inf = 999999;

void DFS(int node, vector<pair<int,int>> adj[], vector<bool>& vis, stack<int>& st) {
    vis[node] = 1;

    for (auto it : adj[node])
    {
        if (!vis[it.first])
        {
            DFS(it.first, adj, vis, st);
        }
    }
    st.push(node);
}

void findShortestDistance(vector<pair<int,int>> adj[], int n, int source) {
    stack<int> st;
    vector<bool> vis(n+1, false);
    for (int i = 0; i <= n; i++)
    {
        if (!vis[i])
        {
            DFS(i, adj, vis, st);
        }
    }

    vector<int> distance(n+1, inf);
    distance[source] = 0;

    while (!st.empty())
    {
        int node = st.top();
        st.pop();

        if (distance[node] != inf)
        {
            for (auto it : adj[node])
            {
                if (distance[it.first] > distance[node] + it.second)
                {
                    distance[it.first] = distance[node] + it.second;
                }
            }
            
        }
    }

    for (auto it : distance)
    {
        cout<<it<<" ";
    }
    
}

int main(){
    int n,e;
    cin>>n>>e;

    vector<pair<int,int>> adj[n + 1];

    for (int i = 0; i < e; i++)
    {
        int n1,n2,dist;
        cin>>n1>>n2>>dist;
        adj[n1].push_back({n2, dist});
    }

    findShortestDistance(adj, n, 0);
}