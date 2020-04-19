#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//方法一 二分查找
class Solution 
{
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) 
    {
        if(matrix.size() == 0)
            return false;
        int line = matrix.size()-1;
        int column = matrix[0].size();
        for(int i = 0; i < column; ++i)
        {
            line = midsearch(matrix, 0, line, i, target);
            if(matrix[line][i] == target)
            {
                return true;
            }
        }
        return false;
    }
    int midsearch(vector<vector<int>>& matrix, int low, int high, int column, int target)
    {
        while(low < high)
        {
            int mid = (low + high) / 2;
            if(matrix[mid][column] == target)
                return mid;
            else if(matrix[mid][column] > target)
                high = mid -1;
            else if(matrix[mid][column] < target)
                low = mid + 1;
        }
        return low;
    }
};