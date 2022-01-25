#include<bits/stdc++.h>
using namespace std;

void DFStraversal(int node, vector<int> adj[], int vis[], stack<int> & st) {
    vis[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            DFStraversal(it, adj, vis, st);
        }
    }
    st.push(node);
}

vector<int> toposort(vector<int> adj[],int n) {
    stack<int> st;
    int vis[n+1];
    memset(vis, 0, sizeof(vis));
    vector<int> ans;

    for (int i = 0; i <= n; i++)
    {
        if (!vis[i])
        {
            DFStraversal(i, adj, vis, st);
        }
    }

    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
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
    }

    vector<int> ans = toposort(adj, n);

    for(int i : ans) {
        cout<<i<<" ";
    }
}