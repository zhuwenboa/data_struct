#include<iostream>
#include<vector>
#include<algorithm>
#include<deque>
//找到最接近的K个数 二分查找
using namespace std;

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) 
    {
        if(x < arr[0])
            return vector<int>(&arr[0], &arr[k]);
        int len = arr.size();
        if(x > arr[len -1])
            return vector<int>(&arr[len - 1- k], &arr[len]);
        int MinApproach = Binarysearch(arr, x);
        int i, j;
        i = MinApproach;
        j = MinApproach + 1;
        vector<int> temp;
        temp.reserve(k);
        while(k > 0)
        {
            if(j >= len ||  ( i >=0 && abs(x - arr[i]) <= abs(x - arr[j]) ))
            {
                temp.insert(temp.begin(), arr[i]);
                --i;
            }
            else if(i < 0 || (j <= len && abs(x - arr[i]) > abs(x - arr[j]) ) )
            {
                temp.push_back(arr[j]);
                ++j;
            }
            k--;
        }
        return temp;
    }
    int Binarysearch(vector<int>& arr, int x)
    {
        int high = arr.size() -1;
        int low = 0;
        int mid;
        while(low+1 < high)
        {
            mid = (low + high) / 2;
            if(x <= arr[mid])
                high = mid;
            else 
                low = mid;
        }
        return low;
    }
};


int main()
{
    //vector<int> arr{0,1,2,3,4,4,4,5,5,5,6,7,9,9,10,10,11,11,12,13,14,14,15,17,19,19,22,24,24,25,25,27,27,29,30,32,32,33,33,35,36,38,39,41,42,43,44,44,46,47,48,49,52,53,53,54,54,57,57,58,59,59,59,60,60,60,61,61,62,64,66,68,68,70,72,72,74,74,74,75,76,76,77,77,80,80,82,83,85,86,87,87,92,93,94,96,96,97,98,99};
    vector<int> arr{0,0,1,2,3,3,4,7,7,8};
    Solution res;
    vector<int> vec = res.findClosestElements(arr, 3, 5);
    for(auto a : vec)
        std::cout << a << "\n";
}
