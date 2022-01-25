// TODO find Number Of Connected Components In Disconnected Graph

#include<bits/stdc++.h>
using namespace std;

int main() {
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
    int count = 0;
    vector<int> visited(n+1,0);
    vector<int> ans;
    for (int i = 1; i <= n; i++)
    {
        if (visited[i] == false)
        {
            count++;
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
    cout<<"Number of Connected components is equal to : "<<count<<endl;
}