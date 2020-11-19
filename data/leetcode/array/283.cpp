#include<iostream>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;

class Solution 
{
public:
    void moveZeroes(vector<int>& nums) 
    {
        map<int, int> judge;
        for(int i = 0; i < nums.size(); ++i)
        {
            if(nums[i] != 0)
            {
                judge[i] = nums[i];
            }
        }    
        int zero_sum = nums.size() - judge.size();
        for(int j = nums.size() -1; zero_sum > 0; --zero_sum, --j)
        {
            nums[j] = 0;
        }   
        int i = 0;
        for(auto t = judge.begin(); t != judge.end(); ++t, ++i)
        {
            nums[i] = t->second;
        }
    }
};

//双指针法
class Solution2 
{
public:
    void moveZeroes(vector<int>& nums) 
    {
        int left = 0, right = 0;
        int n = nums.size();
        while(right < n)
        {
            if(nums[right])
            {
                swap(nums[left], nums[right]);
                ++left;
            }
            ++right;
        }       
    }
};