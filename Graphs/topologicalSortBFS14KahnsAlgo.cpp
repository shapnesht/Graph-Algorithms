#include<bits/stdc++.h>
using namespace std;

vector<int> toposort(vector<int> adj[],int n) {
    queue<int> q;
    int inDegree[n+1];
    memset(inDegree, 0, sizeof(inDegree));
    vector<int> ans;

    for (int i = 0; i <= n; i++)
    {
        for(auto it : adj[i]) {
            inDegree[it]++;
        }
    }
    
    for (int i = 0; i <= n; i++)
    {
        if (inDegree[i] == 0)
        {
            q.push(i);
        }
    }

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        ans.push_back(node);

        for (int it : adj[node])
        {
            inDegree[it]--;
            if (inDegree[it] == 0)
            {
               q.push(it);
            }
        }
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