#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<queue>
using namespace std;


class Solution
{
public: 
    struct Coordinate
    {
        int x;
        int y;
        int step;
    };
    int bfs(vector<vector<int>>& grid, int x, int y)
    {
        set<pair<int, int>> judge;
        queue<Coordinate> q;
        q.push({x, y, 0});
        judge.insert({x, y});
        while(!q.empty())
        {
            Coordinate temp = q.front();
            q.pop();
            for(int i = 0; i < 4; ++i)
            {
                int temp_x = temp.x + dir_x[i];
                int temp_y = temp.y + dir_y[i];
                if(temp_x < 0 || temp_x >= grid.size() || temp_y < 0 || temp_y >= grid[0].size())
                    continue;
                if(judge.count({temp_x, temp_y}) > 0)
                    continue;
                if(grid[temp_x][temp_y])
                    return temp.step + 1;
                q.push({temp_x, temp_y, temp.step +1});
                judge.insert({temp_x, temp_y});
            }
        }
        return -1;
    }

    int maxDistance(vector<vector<int>>& grid)
    {
        int max_step = -1;
        for(int i = 0; i < grid.size(); ++i)
        {
            for(int j = 0; j < grid[0].size(); ++j)
            {
                if(!grid[i][j])
                {
                    max_step = max(max_step, bfs(grid, i, j));
                }
            }
        }
        return max_step;
    }
    vector<int> dir_x{1, 0, -1, 0};
    vector<int> dir_y{0, 1, 0, -1};

};

/*
class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) 
    {
        set<pair<int, int>> island;
        for(int i = 0; i < grid.size(); ++i)
        {
            for(int j = 0; j < grid[0].size(); ++j)
            {
                if(grid[i][j] == 1)
                    island.insert({i, j});           
            }
        }
        if(island.size() == 0 || (island.size() == grid.size() * grid[0].size()) )
            return -1;
        int max_step = 0;
        for(auto a : island)
        {
            int step = 1;
            start_x = a.first;
            start_y = a.second;
            dfs(grid, a.first, a.second, step);
            if(step > max_step)
                max_step = step;
        }
        return max_step;
    }
    void dfs(vector<vector<int>>& grid, int x, int y, int& step)
    {
        if(judge.count({x, y}) > 0)
            return;
        judge.insert({x, y});
        if( (x + 1 >= grid.size() || grid[x+1][y] == 0) && (x-1 < 0 || grid[x-1][y] == 0) 
            && (y+1 >= grid[0].size() || grid[x][y+1] == 0) && (y-1 < 0 || grid[x][y-1] == 0) )
            {
                int temp = 0;
                temp += abs(x - start_x) + abs(y - start_y);
                if(temp > step)
                    step = temp;                
            }


        for(int i = 0; i < 4; ++i)
        {
            int temp_x = x + dir_x[i];
            int temp_y = y + dir_y[i];
            if(temp_x < 0 || temp_x >= grid.size() || temp_y < 0 || temp_y >= grid[0].size() || grid[temp_x][temp_y] == 1)
                continue;
            dfs(grid, temp_x, temp_y, step);
        }
    }
    int start_x;
    int start_y;
    set<pair<int, int>> judge;
    vector<int> dir_x{1, 0, -1, 0};
    vector<int> dir_y{0, 1, 0, -1};    
};
*/
int main()
{
    vector<vector<int>> grid{ {0, 0,0, 0,0}, {0,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0},{0,0,0,0,0} };
    Solution res;
    std::cout << res.maxDistance(grid) << "\n";
}