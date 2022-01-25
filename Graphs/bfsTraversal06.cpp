#include<bits/stdc++.h>
using namespace std;

void doBFS(int n, vector<int> adj[]) {
    vector<int> visited(n+1,0);
    vector<int> ans;
    for (int i = 1; i <= n; i++)
    {
        if (visited[i] == false)
        {
            queue<int> que;
            que.push(i);
            visited[i] = true;
            while (!que.empty())
            {
                int front = que.front();
                que.pop();
                ans.push_back(front);
                for (int j = 0; j < adj[front].size(); j++)
                {
                    if (visited[adj[front][j]] == false)
                    {
                        visited[adj[front][j]] = true;
                        que.push(adj[front][j]);
                    }
                }
            }
        }
    }
}

int main(){
    int m, n;
    cin >> n >> m;
    vector<int> adj[n+1];

    for (int i = 0; i < m; i++)
    {
        int n1, n2;
        cin >> n1 >> n2;
        adj[n1].push_back(n2);
        adj[n2].push_back(n1);
    }

    doBFS(m, adj);    
}