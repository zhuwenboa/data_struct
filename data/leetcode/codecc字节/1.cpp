#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution 
{
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        unordered_map<int, int> hash_;
        for(int i = 0; i < nums.size(); ++i)
        {
            if(hash_.count(target - nums[i]) > 0)
            {
                return {i, hash_[target - nums[i]]};
            }
            hash_[nums[i]] = i;
        }
        return {};
    }
};