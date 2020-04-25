#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution 
{
public:
    //回溯法
    void backtrack(vector<vector<int>>& res, vector<int>& output, int first, int len)
    {
        if(first == len)
        {
            res.emplace_back(output);
            return;
        }
        for(int i = first; i < len; ++i)
        {
            //变更数组
            swap(output[i], output[first]);
            //递归填写下一个数
            backtrack(res, output, first+1, len);
            //撤销操作
            swap(output[i], output[first]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) 
    {
       vector<vector<int>> vec;
       backtrack(vec, nums, 0, nums.size());
       return vec; 
    }
};