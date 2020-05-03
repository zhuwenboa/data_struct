#include<iostream>
#include<vector>
//最大子序和
using namespace std;

class Solution 
{
public:
    int maxSubArray(vector<int>& nums) 
    {
        int res = nums[0];
        int pre;
        int count = nums.size();
        pre = nums[0];

        for(int i = 1; i < count; ++i)
        {
            pre = max(nums[i], pre+nums[i]);
            res = max(res, pre);
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