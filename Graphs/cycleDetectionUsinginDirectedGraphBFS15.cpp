#include<bits/stdc++.h>
using namespace std;

vector<int> toposort(vector<int> adj[],int n) {
    queue<int> q;
    vector<int> ans;
    vector<int> inDegree(n+1,0);

    for (int i = 1; i <= n; i++)
    {
        for (int it : adj[i])
        {
            inDegree[it]++;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (inDegree[i] == 0)
        {
            q.push(i);
        }
    }
    int count = 0;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        ans.push_back(node);
        count++;
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

    if (ans.size() != n)
    {
        cout<<endl<<"Is Cyclic"<<endl;
    } else
    {
        cout<<endl<<"Is Not a Cyclic"<<endl;
    }
    
    
}