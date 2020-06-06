#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>

using namespace std;

class Solution 
{
public:
    int longestConsecutive(vector<int>& nums) 
    {
        unordered_set<int> num_set;
        for(const int& num : nums)
            num_set.insert(num);
        int max_len = 0;
        for(const int& num : num_set)
        {
            //如果在这个数字之前没有相邻的数字，则它是新的连续数组的开始
            if(!num_set.count(num -1))
            {
                int currentnum = num;
                int current_len = 1;
                while(num_set.count(currentnum + 1))
                {
                    currentnum += 1;
                    current_len += 1;
                }
                max_len = max(max_len, current_len);
            }
        }
        return max_len;
    }
};