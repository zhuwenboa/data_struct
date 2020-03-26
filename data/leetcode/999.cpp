#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
//车的可用捕获量
class Solution 
{
public:
    int numRookCaptures(vector<vector<char>>& board) 
    {
        int R_x, R_y;
        bool flag = false;
        int sum = 0;
        for(int i = 0; (i < board.size()) && (flag == false); ++i)
        {
            for(int j = 0; j < board[0].size(); ++j)
            {
                if(board[i][j] == 'R')
                {
                    R_x = i;
                    R_y = j;
                    flag = true;
                    break;
                }
            }
        }
        vector<int> X{0, 1, 0, -1};
        vector<int> Y{1, 0, -1, 0};
        for(int i = 0; i < 4; ++i)
        {
            for(int step = 0; ; ++step)
            {
                int x = R_x + step * X[i];
                int y = R_y + step * Y[i];
                if(x < 0 || x >= 8 || y < 0 || y >= 8 || board[x][y] == 'B')
                    break;
                if(board[x][y] == 'p')
                {
                    sum++;
                    break;
                }
            }
        }
        return sum;
    }
    /*
    void dfs(vector<vector<char>>& board, int x, int y, int& sum)
    {
        for(int i = 0; i < X.size(); ++i)
        {
            x += X[i];
            y += Y[i];
            if(judge.count({x, y}) > 0)
                continue;
            if(x >= 0 && y >= 0 && x < board.size() && y < board[0].size() && board[x][y] != 'R')
            {
                //judge.insert({x, y});
                if(board[x][y] == 'p')
                    sum += 1;
                dfs(board, x, y, sum);
            }
        }
    }
    */
    //set<pair<int, int>> judge;    
};