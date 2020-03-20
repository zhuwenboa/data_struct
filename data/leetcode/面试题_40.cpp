#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
using namespace std;
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) 
    {
        int p = quick_k(arr, 0, arr.size() -1, k);
        return vector<int>(arr.begin(), arr.begin()+p);
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
        int mid = quick_sort(nums, low, high);
        if(mid == (k - 1))    
            return mid+1; 
        else if(mid < (k -1))
        {
            return quick_k(nums, mid + 1, high, k);
        }
        else
        {
            return quick_k(nums, low, mid -1, k);
        }
    }
};


class Solution2 {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) 
    {
        sort(arr.begin(), arr.end());
        return vector<int>(arr.begin(), arr.begin() + k);
    }
};

int main()
{
    vector<int> vec{3, 2 ,1};
    Solution res;
    vector<int>temp = res.getLeastNumbers(vec, 2);
    for(auto a : temp)
        std::cout << a << "\n";
}