#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution 
{
public:
    void dfs(vector<vector<char>>& board, int x, int y, string& word, int index, bool& flag)
    {
        if(flag == true)
            return;
        if(index == word.size())
        {
            flag = true;
            return;
        }
        if(x+1 < board.size() && word[index] == board[x+1][y] && !flag)
        {
            board[x+1][y] = '#';
            dfs(board, x+1, y, word, index+1, flag);
            board[x+1][y] = word[index];
        }
        if(x-1 >= 0 && word[index] == board[x-1][y] && !flag)
        {
            board[x-1][y] = '#';
            dfs(board, x-1, y, word, index+1, flag);
            board[x-1][y] = word[index];
        }   
        if(y-1 >= 0 && word[index] == board[x][y-1] && !flag)
        {
            board[x][y-1] = '#';
            dfs(board, x, y-1, word, index+1, flag);
            board[x][y-1] = word[index];
        }   
        if(y+1 < board[0].size() && word[index] == board[x][y+1] && !flag)
        {
            board[x][y+1] = '#';
            dfs(board, x, y+1, word, index+1, flag);
            board[x][y+1] = word[index];
        }   
    }

    bool exist(vector<vector<char>>& board, string word) 
    {
        bool flag = false;
        for(int i = 0; i < board.size(); ++i)
        {
            for(int j = 0; j < board[0].size(); ++j)
            {
                if(board[i][j] == word[0])
                {
                    board[i][j] = '#';
                    dfs(board, i, j, word, 1, flag);
                    board[i][j] = word[0];
                }
            }
        }
        return flag;
    }
};