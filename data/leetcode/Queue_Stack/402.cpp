#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>

using namespace std;

class Solution 
{
public:
    string removeKdigits(string num, int k) 
    {
        vector<char> st;
        for(const char& digit : num)
        {
            while(st.size() > 0 && st.back() > digit && k > 0)
            {
                st.pop_back();
                --k;
            }
            st.emplace_back(digit);
        }
        while(k > 0)
        {   
            st.pop_back();
            --k;
        }
        string ans = "";
        bool isLeadingZero = true;
        for(auto& digit : st)
        {
            if(isLeadingZero && digit == '0')
                continue;
            isLeadingZero = false;
            ans += digit;
        }
        return ans == "" ? "0" : ans;
    }
};