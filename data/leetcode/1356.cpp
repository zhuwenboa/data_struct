#include<algorithm>
#include<vector>
#include<set>
#include<iostream>

using namespace std;

class Solution 
{
public:   
    int getBit(int num)
    {
        int sum = 0;
        while(num > 0)
        {
            sum += (num % 2);
            num /= 2;
        }
        return sum;
    }

    vector<int> sortByBits(vector<int>& arr) 
    {
        vector<pair<int, int>> bit;
        for(int i = 0; i < arr.size(); ++i)
        {
            bit.push_back({getBit(arr[i]), i});               
        }
        sort(bit.begin(), bit.end(), [&](pair<int, int>& a, pair<int, int>& b) {
                if(a.first == b.first)
                    return arr[a.second] < arr[b.second];
               return a.first < b.first; 
        });
        vector<int> ans(arr.size());
        for(int i = 0; i < ans.size(); ++i)
        {
            ans[i] = arr[bit[i].second];
        }
        return ans;
    }
};