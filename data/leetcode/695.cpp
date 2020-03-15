#include<iostream>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;
/*
自己的沙雕方法。。。想得太多
class Solution {
public:
    map< pair<int,int>, bool> judge;
    int maxAreaOfIsland(vector<vector<int>>& grid) 
    {
        vector<pair<int, int>> save;
        for(int i = 0; i < grid.size(); ++i)
        {
            for(int j = 0; j < grid[0].size(); ++j)
            {
                if(grid[i][j] == 1)
                {
                    save.push_back({i, j});
                    judge[{i, j}] = true;
                }
            }
        }
        if(save.size() < 1)
            return 0;
        
    }
    int dfs(vector<vector<int>>& grid, const pair<int, int>& iland, int max_area)
    {
        int x = iland.first;
        int y = iland.second;
    }
};
*/

class Solution {
public:
    int dfs(vector<vector<int>>& grid, int cur_x, int cur_y)
    {
        //边界判断
        if(cur_x < 0 || cur_y < 0 || cur_x >= grid.size() || cur_y >= grid[0].size() || grid[cur_x][cur_y] != 1)
            return 0;
        //遍历过就将其置为0
        grid[cur_x][cur_y] = 0;
        int ans = 1; //记录从该结点出发的岛屿面积数
        int dir_x[4] = {0, 0, 1, -1};
        int dir_y[4] = {1, -1, 0, 0};
        for(int i = 0; i < 4; ++i)
        {
            ans += dfs(grid, cur_x + dir_x[i], cur_y + dir_y[i]); 
        }
        return ans;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) 
    {
        int max_area = 0;
        for(int i = 0; i < grid.size(); ++i)
        {
            for(int j = 0; j < grid[0].size(); ++j)
            {
                max_area = max(max_area, dfs(grid, i, j)) ;      
            }
        }
        return max_area;
    }
};