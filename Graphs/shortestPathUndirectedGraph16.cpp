#include<bits/stdc++.h>
using namespace std;

void shortestPath(vector<int> adj[], int n, int source) {
    int distance[n];
    for (int i = 0; i < n; i++)
    {
        distance[i] = 99999;
    }
    queue<int> q;
    q.push(source);
    distance[source] = 0;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (auto it : adj[node])
        {
            if (distance[node] + 1 < distance[it])
            {
                distance[it] = distance[node] + 1;
                q.push(it);
            }
        }
    }
    
    for (int it : distance)
    {
        cout<<it<<" ";
    }
    
}

int main(){
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

    shortestPath(adj, n, 0);
}