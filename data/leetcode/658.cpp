#include<iostream>
#include<vector>
#include<algorithm>

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
        while(low <= high)
        {
            mid = (low + high) / 2;
            if(x < arr[mid])
            {
                high = mid -1;
            }
            if(x > arr[mid])
                low = mid + 1;
            return mid;
        }
        return mid;
    }
};

int main()
{
    vector<int> arr{1, 1, 1, 10, 10, 10};
    Solution res;
    vector<int> vec = res.findClosestElements(arr, 1, 9);
    for(auto a : vec)
        std::cout << a << "\n";
}