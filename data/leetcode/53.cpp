#include<iostream>
#include<vector>

using namespace std;


class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
        int res = nums[0];
        vector<int> dp;
        int count = nums.size();
        
        dp.emplace_back(nums[0]);
        for(int i = 1; i < count; ++i)
        {
            if(nums[i] + dp[i - 1] > nums[i])
                dp.emplace_back(nums[i] + dp[i - 1]);
            else
               dp.emplace_back(nums[i]);
            res = max(res, dp[i]);
        }
        return res;
    }
};

int main()
{
    Solution solut;
    vector<int> a;
    int temp;
    while(cin >> temp)
        a.emplace_back(temp);
    int result = solut.maxSubArray(a);
    cout << result <<endl;
    
}