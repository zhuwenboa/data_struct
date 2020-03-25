#include<iostream>
#include<algorithm>
#include<vector>

//leetcode 895题 三维形体的表面积

using namespace std;

class Solution 
{
public:
    int surfaceArea(vector<vector<int>>& grid) 
    {
        int sum_surface = 0;
        for(int i = 0; i < grid.size(); ++i)
        {
            for (int  j = 0; j < grid[0].size(); ++j)
            {
                if(grid[i][j])
                {
                    sum_surface += 4 * grid[i][j] + 2;
                    if(i -1 >= 0 && grid[i -1][j])
                    {
                        sum_surface -= min(grid[i -1][j], grid[i][j]);
                    }
                    if(j - 1 >= 0 && grid[i][j -1])
                    {
                        sum_surface -= min(grid[i][j - 1], grid[i][j]);
                    }
                    if(i + 1 < grid.size() && grid[i + 1][j])
                        sum_surface -= min(grid[i+1][j], grid[i][j]);
                    if(j + 1 < grid[0].size() && grid[i][j+1])
                        sum_surface -= min(grid[i][j+1], grid[i][j]);
                }        
            }
        }
        return sum_surface;
    }
};