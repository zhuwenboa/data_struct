#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution 
{
public:
    //动态规划法
    /*
    *  1.先将num转换为字符串
    *  2.只有一位或者两位数字可以翻译成字符，而一位数字必然能被翻译，两位数字需要其小于26才可以翻译。
    *  3.所以dp[i]由dp[i-1]和dp[i-2]决定，其中要根据当前字符和前一个字符的值来判断是否需要dp[i-2]
    * 
    */
    int translateNum(int num) 
    {
        string value = to_string(num);
        if(value.empty())
            return 0;
        vector<int> dp(value.size()+1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2; i < dp.size(); ++i)
        {
            dp[i] += dp[i-1];
            if(value[i-2] == '1' || (value[i-2] == '2' && value[i-1] <= '5'))
                dp[i] += dp[i-2];
        }
        return dp[value.size()];
    }

};