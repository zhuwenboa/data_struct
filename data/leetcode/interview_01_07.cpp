#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution 
{
public:
    //额外数组的方法
    void rotate(vector<vector<int>>& matrix) 
    {
        //初始化数组
        vector<vector<int>> vec(matrix.size(), vector<int>(matrix[0].size(), 0));
        int m = 0, n = 0;
        for(int i = 0; i < matrix[0].size(); ++i)
        {
            n = 0;
            for(int j = matrix.size()-1; j >= 0; --j)
            {
                vec[m][n] = matrix[j][i];
                ++n;
            }
            ++m;
        }
        matrix = vec;
    }
    //原地旋转不需要额外的空间
    void rotate2(vector<vector<int>>& matrix)
    {
        int n = matrix.size();
        // 水平翻转
        for (int i = 0; i < n / 2; ++i) 
        {
            for (int j = 0; j < n; ++j) 
            {
                swap(matrix[i][j], matrix[n - i - 1][j]);
            }
        }
        // 主对角线翻转
        for (int i = 0; i < n; ++i) 
        {
            for (int j = 0; j < i; ++j)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
   }
};