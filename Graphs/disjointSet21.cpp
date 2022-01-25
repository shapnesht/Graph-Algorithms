#include <bits/stdc++.h>
using namespace std;

int parent[100000];
int height[100000];

void makeSet() {
    for (int i = 0; i < 100000; i++)
    {
        parent[i] = i;
        height[i] = 0;
    }
}

int findParent(int node) {
    if (parent[node] == node)
    {
        return node;
    }
    
    return parent[node] = findParent(parent[node]);
}

void createUnion(int u, int v) {
    int parentOfU = findParent(u);
    int parentOfV = findParent(v);

    if (height[parentOfU] < height[parentOfV])
    {
        parent[u] = v;
    } 
    else if (height[parentOfV] < height[parentOfU])
    {
        parent[v] = u;
    } 
    else
    {
        parent[u] = v;
        height[v]++;
    }
}


bool isConnected(int u, int v) {
    return findParent(u) == findParent(v);
}

int main(){
    makeSet();
    
    int n;
    cin>>n;
    while (n--)
    {
        int u, v;
        cin>>u>>v;
        createUnion(u,v);
    }
    
    int m;
    cin>>m;
    while (m--)
    {
        int u,v;
        cin>>u>>v;
        cout<<isConnected(u,v)<<endl;
    }
    
}