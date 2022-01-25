#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int weight;
    int u;
    int v;
    Node(int v, int u, int wt) {
        this->weight = wt;
        this->u = u;
        this->v = v;
    }
};

int findParent(int node, vector<int>& parent) {
    if (parent[node] == node)
    {
        return node;
    }
    
    return parent[node] = findParent(parent[node], parent);
}

void unionn(int u, int v, vector<int>& parents, vector<int>& heightRank) {
    if (heightRank[u] < heightRank[v])
    {
        parents[u] = v;
    }
    else if (heightRank[v] < heightRank[u])
    {
        parents[v] = u;
    }
    else
    {
        parents[v] = u;
        heightRank[u]++;
    }
}

bool comp(Node a, Node b) {
    return a.weight < b.weight;
}

int main(){
    int n, e;
    cin>>n>>e;
    vector<Node> edges;

    for (int i = 0; i < e; i++)
    {
        int u, v, wt;
        cin>>u>>v>>wt;
        edges.push_back(Node(u, v, wt));
    }

    sort(edges.begin(), edges.end(), comp);
    
    vector<int> parents(n+1);
    for (int i = 0; i < n+1; i++)
        parents[i] = i;
    vector<int> heightRank(n+1,0);
    
    int cost = 0;
    vector<pair<int, int>> mst;

    for (auto it : edges)
    {
        if (findParent(it.u, parents) != findParent(it.v, parents))
        {
            mst.push_back({it.u, it.v});
            unionn(it.u, it.v, parents, heightRank);
            cost += it.weight;
        }
    }
    
    cout<<cost<<endl;
    for (auto it : mst)
    {
        cout<<it.first<<"-"<<it.second<<endl;
    }
    
}