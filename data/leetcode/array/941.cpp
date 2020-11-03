#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

//二分查找失败，因为不是前后都连续递增或递减的数组
/*
class Solution 
{
public:
    bool validMountainArray(vector<int>& A) 
    {
        if(A.size() <= 2)
            return false;
        int n = A.size();
        int l = 0;
        int r = n -1;
        while(l < r)
        {
            int mid = l + (r - l) / 2;
            if(mid > 0 && mid < n -1)
            {
                if(A[mid] > A[mid - 1] && A[mid] > A[mid+1])
                    return true;
                if(A[mid] > A[mid - 1] && A[mid] < A[mid + 1])
                    l = mid + 1;
                else 
                    r = mid - 1;
            }
            else 
                return false;
        }
        return false;
    }
};
*/
class Solution 
{
public:
    bool validMountainArray(vector<int>& A) 
    {
        int N = A.size();
        int i = 0;

        // 递增扫描
        while (i + 1 < N && A[i] < A[i + 1]) 
        {
            i++;
        }

        // 最高点不能是数组的第一个位置或最后一个位置
        if (i == 0 || i == N - 1) 
        {
            return false;
        }

        // 递减扫描
        while (i + 1 < N && A[i] > A[i + 1]) 
        {
            i++;
        }

        return i == N - 1;
    }
};
