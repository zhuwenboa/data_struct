#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<queue>
using namespace std;

struct node 
{
    int x;
    int y;
    int step;
};

class Solution 
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) 
    {
        for(int i = 0; i < matrix.size(); ++i)
        {
            for(int j = 0; j < matrix[0].size(); ++j)
            {
                if(matrix[i][j])
                {
                    matrix[i][j] = bfs(matrix, i, j);
                    judge.clear();
                }
            }
        }
        return matrix;
    }
    int bfs(vector<vector<int>>& matrix, int x, int y)
    {
        queue<node> q;
        q.push({x, y, 0});
        while(!q.empty())
        {
            auto res = q.front();
            q.pop();
            if(judge.count({res.x, res.y}))
                continue;
            judge.insert({res.x, res.y});
            for(int i = 0; i < 4; ++i)
            {
                int temp_x = res.x + dir_x[i];
                int temp_y = res.y + dir_y[i];
                if(temp_x < 0 || temp_x >= matrix.size() || temp_y < 0 || temp_y >= matrix[0].size())
                    continue;
                if(matrix[temp_x][temp_y] == 0)
                {
                    return res.step +1;
                }
                else
                {
                    q.push({temp_x, temp_y, res.step+1});
                }
            }
        }    
        return 1;    
    }
private:  
    vector<int> dir_x{1, 0, -1, 0};
    vector<int> dir_y{0, 1, 0, -1};
    set<pair<int, int>> judge;    
};

int main()
{
    vector<vector<int>> vec {{1,0,1,1,0,0,1,0,0,1},
                             {0,1,1,0,1,0,1,0,1,1},
                             {0,0,1,0,1,0,0,1,0,0},
                             {1,0,1,0,1,1,1,1,1,1},
                             {0,1,0,1,1,0,0,0,0,1},
                             {0,0,1,0,1,1,1,0,1,0},
                             {0,1,0,1,0,1,0,0,1,1},
                             {1,0,0,0,1,1,1,1,0,1},
                             {1,1,1,1,1,1,1,0,1,0},
                             {1,1,1,1,0,1,0,0,1,1}};
    Solution res;
    vec = res.updateMatrix(vec);
    for(int i = 0; i < vec.size(); ++i)
    {
        for(int j = 0; j < vec[0].size(); ++j)
        {
            std::cout << vec[i][j] << "  ";
        }
        std::cout << "\n";
    }
}