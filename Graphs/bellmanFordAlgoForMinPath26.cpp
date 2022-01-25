#include <bits/stdc++.h>
using namespace std;

int infinity = 999999999;

struct Node
{
    int u;
    int v;
    int wt;

    Node(int _u, int _v, int _wt) {
        u = _u;
        v = _v;
        wt = _wt;
    }
};


int main(){
    int n,e;
    cin>>n>>e;

    vector<Node> edges;

    for (int i = 0; i < e; i++)
    {
        int n1,n2,dist;
        cin>>n1>>n2>>dist;
        edges.push_back(Node(n1,n2,dist));
    }
    int src = 1;

    vector<int> distance(n+1, infinity);
    distance[src] = 0;

    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < e; j++)
        {
            int u = edges[j].u;
            int v = edges[j].v;
            int wt = edges[j].wt;

            if (distance[u] + wt < distance[v])
            {
                distance[v] = distance[u] + wt;
            }
        }
    }
    
    bool flag = false;

    for (int j = 0; j < e; j++)
    {
        int u = edges[j].u;
        int v = edges[j].v;
        int wt = edges[j].wt;

        if (distance[u] + wt < distance[v])
        {
            flag = true;
            cout<<"CYCLE DETECTED!!!\n";
            break;
        }
    }

    if (!flag)
    {
        for (auto it = 1; it <= n; it++)
        {
            cout<<it<<" - "<<distance[it]<<"\n";
        }
        
    }
    
}