#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
//二分查找
class Solution 
{
public:
    int minArray(vector<int>& numbers) 
    {
        int low = 0;
        int high = numbers.size() -1;
        while(low < high)
        {
            int mid = (low + high) / 2;
            if(numbers[mid] > numbers[high])
            {
                low = mid + 1;
            }
            else if(numbers[mid] < numbers[high])
            {
                high = mid;
            }
            else 
                high--;
        }
        return numbers[low];
    }
};