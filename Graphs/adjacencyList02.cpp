#include<bits/stdc++.h>
using namespace std;

// TODO For an undirected Graph && Unweighted Graph

// n -> numberOfNodes
// m -> numberOfEdges

int main(){
    int n,m;
    cin >> n >> m;

    vector<int> adj[n+1];

    for (int i = 0; i < m; i++)
    {
        int n1, n2;
        cin >> n1 >> n2;
        adj[n1].push_back(n2);
        adj[n2].push_back(n1);
    }

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j < adj[i].size(); j++)
        {
            cout << adj[i][j] <<" ";
        }
        cout<<endl;
    }
    
}