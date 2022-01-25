#include <bits/stdc++.h>
using namespace std;

int infinity = 9999999;

void shortestPathDijkstra(vector<pair<int, int>> adj[], int n, int source) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0,source});
    
    vector<int> distance(n+1, infinity);

    distance[source] = 0;

    while (!pq.empty())
    {
        int dist = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (distance[node] != infinity)
        {
            for (auto it : adj[node])
            {
                if (it.second + dist < distance[it.first])
                {
                    distance[it.first] = it.second + dist;
                    pq.push({distance[it.first], it.first});
                }
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
    vector<pair<int, int>> adj[n + 1];
    for (int i = 0; i < e; i++)
    {
        int n1,n2,dist;
        cin>>n1>>n2>>dist;
        adj[n1].push_back({n2, dist});
        adj[n2].push_back({n1, dist});
    }

    shortestPathDijkstra(adj, n, 1);
}