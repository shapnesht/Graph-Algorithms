#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int x, y;
    int time;
    Node(int x, int y, int time) {
        this->x = x;
        this->y = y;
        this->time = time;
    }
};

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<Node> q;
        int n = grid.size();
        int m = grid[0].size();
        int cntOranges = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 2)
                {
                    q.push(Node(i,j,0));
                }
                if (grid[i][j] != 1) cntOranges++;
            }
        }
        int count = 0, ans = 0;
        while (!q.empty())
        {
            int x = q.front().x;
            int y = q.front().y;
            int time = q.front().time;
            q.pop();
            count++;
            ans = max(ans, time);

            int dx[] = {1, 0, -1, 0};
            int dy[] = {0, 1, 0, -1};

            for (int i = 0; i < 4; i++)
            {
                int newX = x + dx[i];
                int newY = y + dy[i];

                if (newX >= 0 && newX < n && newY >= 0 && newY < m && grid[newX][newY] == 1)
                {
                    grid[newX][newY] = 2;
                    q.push(Node(newX, newY, time+1));
                }
            }            
        }
        if (count == cntOranges) return ans;    
        return -1;
    }
};

int main()
{
    
    return 0;
}
