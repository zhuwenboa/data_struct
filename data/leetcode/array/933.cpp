#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution 
{
public:
    vector<int> sortArrayByParityII(vector<int>& A) 
    {
        for(int i = 0, j = 1; i < A.size(); i += 2)
        {
            if(A[i] % 2 == 0)
                continue;
            else 
            {
                while(A[j] % 2 != 0)
                    j += 2;
                swap(A[i], A[j]);
            }
        }
        return A;
    }
};