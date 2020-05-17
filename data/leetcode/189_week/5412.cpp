#include<iostream>
#include<vector>
#include<algorithm>

using namespace  std;  

class Solution 
{
public:
    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) 
    {
        int student_sum = 0;
        for(int i = 0; i < startTime.size(); ++i)
        {
            if(startTime[i] <= queryTime && endTime[i] >= queryTime)
                student_sum++;
        }
        return student_sum;
    }
};

int main()
{
    vector<int> start{1,1,1,1};
    vector<int> end{1,3,2,4};
    Solution res;
    std::cout << res.busyStudent(start, end, 5) << "\n";
}
