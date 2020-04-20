#include<iostream>
#include<algorithm>
#include<vector>
#include<set>

using namespace std;
//dfs 8ms 击败97.97% 内存消耗8.5MB, 击败100%
class Solution 
{
public:
    int numIslands(vector<vector<char>>& grid) 
    {
        int count = 0;
        for(int i = 0; i < grid.size(); ++i)
        {
            for(int j = 0; j < grid[0].size(); ++j)
            {
                if(grid[i][j] == '1')
                {
                    dfs(grid, i, j);
                    ++count;
                }
            }
        }
        return count;
    }
    void dfs(vector<vector<char>>& grid, int x, int y)
    {
        grid[x][y] = '0';
        for(int i = 0; i < dir_x.size(); ++i)
        {
            int temp_x = x + dir_x[i];
            int temp_y = y + dir_y[i];
            if(temp_x < 0 || temp_x >= grid.size() || temp_y < 0 || temp_y >= grid[0].size() ||grid[temp_x][temp_y] == '0')
                continue;
            dfs(grid, temp_x, temp_y);
        }
    }
    vector<int> dir_x {1, 0, -1, 0};
    vector<int> dir_y {0, 1, 0, -1};
};