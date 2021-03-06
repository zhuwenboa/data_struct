#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution 
{
public:
    int numIslands(vector<vector<char>>& grid) 
    {
        int ans = 0;
        for(int i = 0; i < grid.size(); ++i)
        {
            for(int j = 0; i < grid[0].size(); ++j)
            {
                if(grid[i][j] == '1')
                {
                    bfs(grid, i, j);
                    ans++;
                }
            }
        }
        return ans;
    }
    void bfs(vector<vector<char>>& grid, int x, int y)
    {
        grid[x][y] = '0';
        for(int i = 0; i < row.size(); ++i)
        {
            x += row[i];
            y += col[i];
            if(x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size() && grid[x][y] == '1')
                bfs(grid, x, y);
        }
    }
    vector<int> row{0, 1, 0, -1};
    vector<int> col{1, 0, -1, 0};
};