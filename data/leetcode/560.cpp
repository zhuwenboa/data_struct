#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

class Solution 
{
public:
    //暴力法 时间复杂度为O(N^2) 超出时间限制
    int subarraySum(vector<int>& nums, int k) 
    {
        vector<int> sums(nums.size(), 0);
        int sum = 0;
        int count = 0;
        for(int i = 0; i < nums.size(); ++i)
        {
            sum += nums[i];
            sums[i] = sum;
        }
        for(int start = 0; start < nums.size(); ++start)
        {
            for(int end = start; end < nums.size(); ++end)
            {
                if( (sums[end] - sums[start] + nums[start]) == k)
                    ++count;
            }
        }
        return count;
    }
};
//用哈希表进行优化 时间复杂度为O(N)
class Solution2 
{
public:
    int subarraySum(vector<int>& nums, int k) 
    {
        unordered_map<int, int> mp;
        mp[0] = 1;
        int count = 0, pre = 0;
        for (auto& x:nums) 
        {
            pre += x;
            if (mp.find(pre - k) != mp.end()) 
                count += mp[pre - k];
            mp[pre]++;
        }
        return count;
    }
};



int main()
{
    Solution res;
    vector<int> vec{1,1,1};
    std::cout << res.subarraySum(vec, 2) << "\n";
}