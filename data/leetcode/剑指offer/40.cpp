#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution 
{
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) 
    {
        int res = -1;
        partition_k(arr, 0, arr.size()-1, res, k);
        if(res == -1)
            return {};
        return vector<int>(arr.begin(), arr.begin()+k);
    }
    int qsort(vector<int>& arr, int low, int high)
    {
        int judge = arr[low];
        while(low < high)
        {
           while(low < high && arr[high] >= judge)
                --high;
            swap(arr[low], arr[high]);
            while(low < high && arr[low] <= judge)
                ++low;
            swap(arr[low], arr[high]);
        }
        return low;
    }
    void partition_k(vector<int>& arr, int low, int high, int& res, const int& k)
    {
        if(low > high)
            return;
        int n = qsort(arr, low, high);
        if(n == k-1)
        {
            res = k;
            return;
        }
        if(n < k-1)
            return partition_k(arr, n+1, high, res, k);
        else 
            return partition_k(arr, low, n-1, res, k);
    }
};