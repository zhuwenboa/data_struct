#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution 
{
public:
    string minNumber(vector<int>& nums) 
    {
        string ans;
        std::string tmp;
        std::sort(nums.begin(), nums.end(), 
        [&](const int& a, const int& b)
        {
            string t1, t2;
            t1 += to_string(a);
            t1 += to_string(b);
            t2 += to_string(b);
            t2 += to_string(a);
            if(atol(t1.c_str()) < atol(t2.c_str()))
                return true;
            else 
                return false;
        });
        for(int i = 0; i < nums.size(); ++i)
        {
            ans += to_string(nums[i]);
        }
        return ans;
    }
};

int main()
{
    vector<int> vec{3, 30, 34, 5, 9};
    Solution s;
    string ans =  s.minNumber(vec);
    std::cout << "ans = " << ans << "\n";
}