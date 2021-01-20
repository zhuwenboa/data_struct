#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution 
{
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) 
    {
        if(matrix.empty())
            return false;
        int row = 0;
        int col = matrix[0].size() -1;
        while(row < matrix.size() && col >= 0)
        {
            if(matrix[row][col] == target)
                return true;
            else if(matrix[row][col] > target)
                col--;
            else 
                row++;
        }
        return false;
    }
};