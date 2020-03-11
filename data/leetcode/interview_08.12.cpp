#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) 
    {
        res.reserve(n);
        callbackqueen(0, n);
        return s;
    }
    void callbackqueen(int row, int n)
    {
        if(row == n)
        {
            s.push_back(print(n));
            return;
        }
        for(int i = 0; i < n; ++i)
        {
            if(Isok(row, i))
            {
                res[row] = i;
                callbackqueen(row+1, n);
            }
        }
    }
    bool Isok(int row, int column)
    {
        int left = column -1;
        int right = column + 1;
        for(int i = row -1; i >= 0; --i)
        {
            //判断这一列是否有元素
            if(res[i] == column)
                return false;
            //判断左上角是否有元素
            if(left >= 0 && res[i] == left)
                return false;
            //判断右上角是否有元素
            if(res[i] == right)
                return false;
            --left, ++right;
        }
        return true;
    }

    vector<string> print(int n)
    {
        vector<string> vec;
        for(int i = 0; i < n; ++i)
        {
            string temp("");
            for(int j = 0; j < n; ++j)
            {
                if(res[i] == j)
                {
                    temp += "Q";
                }
                else
                {
                    temp += ".";
                }
            }
            vec.push_back(temp);
        }
        return vec;
    }

private:  
    vector<int> res;
    vector<vector<string>> s;
};

int main()
{
    Solution res;
    vector<vector<string>> vec = res.solveNQueens(4);
    for(int i = 0; i < vec.size(); ++i)
    {
        for(int j = 0; j < vec[0].size(); ++j)
        {
            std::cout << vec[i][j] << "\n";
        }
        std::cout << "\n";
    }

}