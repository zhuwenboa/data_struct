#include<iostream>
#include<map>
#include<vector>

using namespace std;

class Solution {
public:
    int findRepeatNumber(vector<int>& nums) 
    {
        map<int, int> mem;
        for(auto a = nums.begin(); a != nums.end(); ++a)
        {
            if(mem.count(*a) == 0)
                mem[*a] = 1;
            else 
                return *a;
        }    
    }
};

int main()
{
    vector<int> vec {1, 2, 3, 4 ,5, 6 ,7 ,8 ,9, 1, 2, 3};
    Solution res;
    std::cout << res.findRepeatNumber(vec) << "\n";
}