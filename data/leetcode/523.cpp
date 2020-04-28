#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<unordered_set>
using namespace std;
/*
struct node 
{
    friend bool operator < (const node& a, const node& b)
    {
        return a.sum < b.sum;
    }
    int sum;
    int step;
    int index;
    node(int a, int b, int c) : sum(a), step(b), index(c) {}
};
*/

class Solution 
{
public:
    //回溯法 超出时间限制 因为递归子树中有太多相同的问题
    void huisu(vector<int>& nums, int k, int sum, int step, int index, bool& flag)
    {
        if(k != 0 && sum % k == 0 && step >= 2)
        {
            flag = true;
            return;
        }  
        if(sum == k && step >= 2)
        {
            flag = true;
            return;
        }
        if(flag == true || index == nums.size())
            return;
        huisu(nums, k, sum+nums[index], step+1, index+1, flag);
        huisu(nums, k, 0, 0, index+1, flag);
    }
    //暴力法 O(N^3)超出时间限制
    bool violence(vector<int>& nums, int k)
    {
        for(int start = 0; start < nums.size()-1; ++start)
        {
            for(int end = start+1; end < nums.size(); ++end)
            {
                int sum = 0;
                for(int i = start; i <= end; ++i)
                    sum += nums[i];
                if(sum == k || (k != 0 && sum % k == 0))
                    return true;
            }
        }
        return false;
    }
    //优化后的暴力法，时间复杂度为O(N^2)
    bool  nice_violence(vector<int>& nums, int k)
    {
        //记录第0到第i个nums的和
        vector<int> sum(nums.size(), 0);
        sum[0] = nums[0];
        for(int i = 1; i < nums.size(); ++i)
        {
            sum[i] = sum[i-1] + nums[i];
        }
        for(int start = 0; start < nums.size()-1; ++start)
        {
            for(int end = start+1; end < nums.size(); ++end)
            {
                int s = 0;
                s = sum[end] - sum[start] + nums[start];
                if(s == k || (k != 0 && s % k == 0))
                    return true;
            }
        }
        return false;
    }   


    bool checkSubarraySum(vector<int>& nums, int k) 
    {
        bool flag = false;
        if(nums.size() < 2)
            return false;
        huisu(nums, k, 0, 0, 0, flag);
        return flag;
    }
};

int main()
{
    Solution res;
    vector<int> vec{23, 2, 6, 4, 7};
    std::cout << res.violence(vec, 0) << "\n";
}