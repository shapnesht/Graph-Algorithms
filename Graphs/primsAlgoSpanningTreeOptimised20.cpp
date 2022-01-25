#include <bits/stdc++.h>
using namespace std;

int infinity = 999999;

int main(){
    int n, e;
    cin>> n >> e;
    vector<pair<int, int>> adj[n];
    for (int i = 0; i < e; i++)
    {
        int n1,n2,dist;
        cin>>n1>>n2>>dist;
        adj[n1].push_back({n2, dist});
        adj[n2].push_back({n1, dist});
    }

    // Prims Algo Starts here
    bool MST[n];
    memset(MST, false, sizeof(MST));
    int key[n];
    memset(key, infinity, sizeof(key));
    int parent[n];
    memset(parent, -1, sizeof(parent));

    key[0] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0,0});

    for (int i = 0; i < n-1; i++)
    {
        int minIdx = pq.top().second;
        pq.pop();

        MST[minIdx] = true;

        for (auto it : adj[minIdx])
        {
            int node = it.first;
            int dist = it.second;
            if (!MST[node] && dist < key[node])
            {
                parent[node] = minIdx;
                key[node] = dist;
                pq.push({key[node], node});
            }
        }
    }

    for (auto it : parent)
    {
        cout<<it<<" ";
    }
    cout<<endl;
    for (auto it : key)
    {
        cout<<it<<" ";
    }
    
}