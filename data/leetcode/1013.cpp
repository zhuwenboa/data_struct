#include<iostream>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

class Solution {
public:
    //因为要寻找三个和相同的数组，那么每个数组的和肯定为 sum(A) / 3。
    bool canThreePartsEqualSum(vector<int>& A) 
    {
        if(A.size() < 3)
            return false;
        int sum = 0;
        for(int i = 0; i < A.size(); ++i)
        {
            sum += A[i];
        }
        if(sum % 3 != 0)
        {
            return false;   
        }
        sum /= 3;
        int sum_1 = 0;
        int flag = -1;
        for(int i = 0; i < A.size() -2; ++i)
        {
            sum_1 += A[i];
            if(sum_1 == sum)
            {
                flag = i;
                break;
            }
        }
        if(flag == -1)
            return false;
        sum_1 = 0;
        for(int j = flag + 1; j < A.size() -1; ++j)
        {
            sum_1 += A[j];
            if(sum_1 == sum)
                return true;       
        }
        return false;
    }
};
int main()
{
    vector<int> vec {1, -1, 1, -1};
    Solution res;
    std::cout << res.canThreePartsEqualSum(vec) << "\n";
}