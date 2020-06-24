#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution 
{
public:
    int threeSumClosest(vector<int>& nums, int target) 
    {
        sort(nums.begin(), nums.end());
        int i, j, k;
        int sum;
        int dif = nums[0] + nums[1] + nums[nums.size()-1];
        for(int i = 0; i < nums.size() - 2; ++i)
        {
            j = i + 1;
            k = nums.size() -1;
            while(j < k)
            {
                sum = nums[i] + nums[j] + nums[k];
                if(sum == target)
                    return sum;
                if(abs(sum - target) < abs(dif - target))
                    dif = sum;
                if( sum > target)
                {
                    --k;
                }
                else 
                {
                    ++j;
                }
            }
        }
        return dif;
    }
};