#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) 
    {
        return quick_k(nums, 0, nums.size() -1, k);
    }
    int quick_sort(vector<int>& nums, int low, int high)
    {
        int last = high;
        int pre = low;
        int temp = nums[low];
        while(pre < last)
        {
            while(pre < last && nums[last] >= temp)
                --last;
            swap(nums[pre], nums[last]);
            while(pre < last && nums[pre] <= temp)
                ++pre;
            swap(nums[pre], nums[last]);
        }   
        return pre;
    }
    int quick_k(vector<int>& nums, int low, int high, int k)
    {
        int size = nums.size();
        if(low <= high)
        {
            int mid = quick_sort(nums, low, high);
            if(mid == (size - k))    
                return nums[mid];
            else if(mid < (size - k))
            {
                return quick_k(nums, mid + 1, high, k);
            }
            else
            {
                return quick_k(nums, low, mid -1, k);
            }
        }     
    }
};

int main()
{
    vector<int> vec{3, 2, 3, 1, 2, 4, 5, 5, 6};
    Solution res;
    std::cout << res.findKthLargest(vec, 4) << "\n";
}