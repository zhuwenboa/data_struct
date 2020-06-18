#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution 
{
public:
    int maxScoreSightseeingPair(vector<int>& A) 
    {
        int ans = 0;
        int max_left = A[0] + 0;
        for(int i = 1; i < A.size(); ++i)
        {
            ans = max(ans, max_left + A[i] - i);
            max_left = max(max_left, A[i] + i);
        }
        return ans;
    }
};