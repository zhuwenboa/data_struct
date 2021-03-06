#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution 
{
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) 
    {
        if(matrix.empty())
            return {};
        int row = matrix.size();
        int col = matrix[0].size();
        int left = 0;
        int right = col - 1;
        int top = 0;
        int under = row - 1;
        vector<int> ans;
        while(left <= right && top <= under)
        {
            for(int i = left; i <= right; ++i)
                ans.emplace_back(matrix[top][i]);
            for(int i = top+1; i <= under; ++i)
                ans.emplace_back(matrix[i][right]);
            /*
            判断这一步是为了防止遍历了重复的行
            因为这两步是向回遍历，如果是重复的行或列会造成访问相同元素
            */
            if(left < right && top < under)
            {
                for(int i = right-1; i > left; --i)
                    ans.emplace_back(matrix[under][i]);
                for(int i = under; i > top; --i)
                    ans.emplace_back(matrix[i][left]);
            }
            left++;
            right--;
            top++;
            under--;
        }
        return ans;
    }
};