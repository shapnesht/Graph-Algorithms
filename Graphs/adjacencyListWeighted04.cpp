#include<bits/stdc++.h>
using namespace std;

// TODO For an undirected Graph && Unweighted Graph

// n -> numberOfNodes
// m -> numberOfEdges

int main(){
    int n,m;
    cin >> n >> m;

    vector<pair<int, int>> adj[n+1];

    for (int i = 0; i < m; i++)
    {
        int n1, n2, wt;
        cin >> n1 >> n2 >> wt;
        adj[n1].push_back({n2, wt});
        adj[n2].push_back({n1, wt});
    }

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j < adj[i].size(); j++)
        {
            cout << adj[i][j].first << " wt ->" << adj[i][j].second <<" ";
        }
        cout<<endl;
    }
    
}