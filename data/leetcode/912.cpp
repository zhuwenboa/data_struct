#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution 
{
public:
    vector<int> sortArray(vector<int>& nums) 
    {
        q_sort(nums, 0, nums.size()-1);
        return nums;   
    }
    //快排
    int quick_sort(vector<int>& nums, int low, int high)
    {
        int sentry = nums[low];
        while(low < high)
        {
            while(low < high && sentry <= nums[high])
                --high;
            swap(nums[low], nums[high]);
            while(low < high && sentry >= nums[low])
                ++low;
            swap(nums[low], nums[high]);
        }
        return low;
    }
    void q_sort(vector<int>& nums, int low, int high)
    {
        if(low < high)
        {
            int mid = quick_sort(nums, low, high);
            q_sort(nums, low, mid -1);
            q_sort(nums, mid + 1, high);
        }
    }
};

int main()
{
    vector<int> vec{5,4,3,2,1};
    Solution res;
    res.sortArray(vec);
    for(auto a : vec)
        std::cout << a << "\n";
}