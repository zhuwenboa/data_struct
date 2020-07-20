#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) 
    {
        int low = 0, high = numbers.size() - 1;
        while (low < high) 
        {
            int sum = numbers[low] + numbers[high];
            if (sum == target) 
            {
                return {low + 1, high + 1};
            } 
            else if (sum < target) 
            {
                ++low;
            } 
            else 
            {
                --high;
            }
        }
        return {-1, -1};
    }
};


/*
class Solution 
{
public:
    vector<int> twoSum(vector<int>& numbers, int target) 
    {
        int left = 0;
        int right = numbers.size() -1;
        while(left < right)
        {
            int mid = (left + right) / 2;
            if(numbers[mid] > target)
                right = mid - 1;
            else 
            {
                if(mid + 1 > right || numbers[mid + 1] >= target)
                {
                    left = mid;
                    break;
                }
                else 
                    left = mid + 1;
            }
        }
        right = left;
        left = 0;
        while(left < right)
        {
            if(numbers[left] + numbers[right] == target)
            {
                return {left+1, right+1};
            }
            if(numbers[left] + numbers[right] > target)
                right--;
            else
                left++;
        }
        return {0, 0};
    }
};
*/
int main()
{
    vector<int> vec{2, 3, 4};
    Solution res;
    vec = res.twoSum(vec, 6);
    for(auto a : vec)
        std::cout << a << "\n";
}