#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution 
{
public:
    int largestPerimeter(vector<int>& A) 
    {
        sort(A.begin(), A.end(), 
            [&](const int& a, const int& b)
            {
                return a > b;
            }
        );
        int ans = 0;
        for(int i = 0; i < A.size()-2; ++i)
        {
            if(A[i+1] + A[i+2] > A[i])
            {
                ans = A[i] + A[i+1] + A[i+2];
                return ans;
            }
        }
        return ans;
    }

};