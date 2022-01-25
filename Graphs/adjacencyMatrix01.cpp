#include<bits/stdc++.h>
using namespace std;

// TODO For an undirected Graph && Unweighted Graph

// n -> numberOfNodes
// m -> numberOfEdges

int main(){
    int n,m;
    cin >> n >> m;

    int adj[m+1][n+1];
    memset(adj,0,sizeof(adj));

    for (int i = 0; i < m; i++)
    {
        int n1, n2;
        cin >> n1 >> n2;
        adj[n1][n2] = 1;
        adj[n2][n1] = 1;
    }

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            cout << adj[i][j] <<" ";
        }
        cout<<endl;
    }
    
}