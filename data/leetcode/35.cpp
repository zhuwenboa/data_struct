#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) 
    {
        int high = nums.size() - 1;
        int low = 0;
        int mid;
        while(low <= high)
        {
            mid = low + (high - low ) / 2; //防止(low + high) /2 时 low + high 溢出范围
            if(target > nums[mid])
            {
                low = mid + 1;
                continue;
            }
            if(target < nums[mid])  
            {
                high = mid - 1;
                continue;
            } 
            if(target == nums[mid])
                return mid;
        }    
        if(target < nums[mid])
            return mid;
        else 
            return mid + 1;
    }
};

int main()
{
    Solution res;
    vector<int> vec{1, 3, 5, 6};
    int target;
    cin >> target;
    std::cout << res.searchInsert(vec, target) << "\n";
    
}