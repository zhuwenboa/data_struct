#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution 
{
public:
    bool exist(vector<vector<char>>& board, string word) 
    {
        int str_s = word.size();
        if(str_s == 0)
            return false;
        if(board.empty())
            return false;
        for(int i = 0; i < board.size(); ++i)
        {
            for(int j = 0; j < board[0].size(); ++j)
            {
                if(board[i][j] == word[0])
                {
                    if(dfs(board, i, j, word, 0))
                        return true;
                }
            }
        }
        return false;
    }
    bool dfs(vector<vector<char>>& board, int row, int col, string& word, int index)
    {
        if(index == word.size()-1)
            return true;
        //将走过的字符标记为!
        int tmp = board[row][col];
        board[row][col] = '!';
        //向右
        if(row+1 < board.size() && board[row+1][col] == word[index+1])
        {
            if(dfs(board, row+1, col, word, index+1))
                return true;
        }
        //向左
        if(row-1 >= 0 && board[row-1][col] == word[index+1])
        {
            if(dfs(board, row-1, col, word, index+1))
                return true;
        }
        //向下
        if(col+1 < board[0].size() && board[row][col+1] == word[index+1])
        {
            if(dfs(board, row, col+1, word, index+1))
                return true;
        }
        //向上
        if(col-1 >= 0 && board[row][col-1] == word[index+1])
        {
            if(dfs(board, row, col-1, word, index+1))
                return true;
        }
        //当该路径不能到达时，恢复其原来的值
        board[row][col] = tmp;
        return false;
    }
};