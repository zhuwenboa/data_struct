#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

class Solution 
{
public:
    string addStrings(string num1, string num2) 
    {
        int index_num1 = num1.size()-1, index_num2 = num2.size()-1;
        int count = 0;
        
        string ans;
        while(index_num1 >= 0 && index_num2 >= 0)
        {   
            int cur_sum = (num1[index_num1] - '0') + (num2[index_num2] - '0') + count;
            count = cur_sum / 10;
            cur_sum %= 10;
            ans += to_string(cur_sum);
            --index_num1;
            --index_num2;
        }
        while(index_num1 >= 0)
        {
            int cur_sum = (num1[index_num1] - '0') + count;
            count = cur_sum / 10;
            cur_sum %= 10;
            ans += to_string(cur_sum);
            --index_num1;
        }
        while(index_num2 >= 0)
        {
            int cur_sum = (num2[index_num2] - '0') + count;
            count = cur_sum / 10;
            cur_sum %= 10;
            ans += to_string(cur_sum);
            --index_num2;
        }
        if(count)
            ans += to_string(count);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};