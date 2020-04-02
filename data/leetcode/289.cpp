//leetcode 289 生命游戏

#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
using namespace std; 

//我的方法
class Solution 
{
public:
    void gameOfLife(vector<vector<int>>& board) 
    {
        for(int i = 0; i < board.size(); ++i)
        {
            for(int j = 0; j < board[0].size(); ++j)
            {
                if(board[i][j])
                {
                    alive(i, j, board);
                }
                else 
                    died(i, j, board);
            }
        }
        for(auto a : judge)
        {
            int x = a.first;
            int y = a.second;
            if(board[x][y])
                board[x][y] = 0;
            else
                board[x][y] = 1;
        }
    }

    void alive(int x, int y, vector<vector<int>>& board)
    {
        int alive_count = 0;
        for(int i = 0; i < 8; ++i)
        {
            int temp_x = x + dir_x[i];
            int temp_y = y + dir_y[i];
            if(temp_x < 0 || temp_x >= board.size() || temp_y < 0 || temp_y >= board[0].size())
                continue;
            if(board[temp_x][temp_y])
                alive_count++;
        }
        if(alive_count < 2 || alive_count > 3)
            judge.insert({x, y});
    }
    void died(int x, int y, vector<vector<int>>& board)
    {
        int alive_count = 0;
        for(int i = 0; i < 8; ++i)
        {
            int temp_x = x + dir_x[i];
            int temp_y = y + dir_y[i];
            if(temp_x < 0 || temp_x >= board.size() || temp_y < 0 || temp_y >= board[0].size())
                continue;
            if(board[temp_x][temp_y])
                alive_count++;
        }
        if(alive_count == 3)
            judge.insert({x, y});
    }
    vector<int> dir_x = {1, 0, -1, 0, -1, -1, 1, 1};
    vector<int> dir_y = {0, 1, 0, -1, -1, 1, -1, 1};
    set<pair<int, int>> judge;    
};

//官方题解
class Solution2 {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int neighbors[3] = {0, 1, -1};

        int rows = board.size();
        int cols = board[0].size();

        // 遍历面板每一个格子里的细胞
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {

                // 对于每一个细胞统计其八个相邻位置里的活细胞数量
                int liveNeighbors = 0;

                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {

                        if (!(neighbors[i] == 0 && neighbors[j] == 0)) {
                            // 相邻位置的坐标
                            int r = (row + neighbors[i]);
                            int c = (col + neighbors[j]);

                            // 查看相邻的细胞是否是活细胞
                            if ((r < rows && r >= 0) && (c < cols && c >= 0) && (abs(board[r][c]) == 1)) {
                                liveNeighbors += 1;
                            }
                        }
                    }
                }

                // 规则 1 或规则 3 
                if ((board[row][col] == 1) && (liveNeighbors < 2 || liveNeighbors > 3)) {
                    // -1 代表这个细胞过去是活的现在死了
                    board[row][col] = -1;
                }
                // 规则 4
                if (board[row][col] == 0 && liveNeighbors == 3) {
                    // 2 代表这个细胞过去是死的现在活了
                    board[row][col] = 2;
                }
            }
        }

        // 遍历 board 得到一次更新后的状态
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (board[row][col] > 0) {
                    board[row][col] = 1;
                } else {
                    board[row][col] = 0;
                }
            }
        }
    }
};

int main()
{
    vector<vector<int>> vec {{0,1,0}, {0,0,1}, {1,1,1}, {0,0,0}};
    Solution res;
}