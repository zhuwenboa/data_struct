#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

class Solution 
{
public:
    void backtrack(vector<string>& ans, string& cur, int left, int right, int n)
    {
        if(cur.size() == n * 2)
        {
            ans.push_back(cur);
            return;
        }
        //左括号的数量小于n，我们则继续加入左括号
        if(left < n)
        {
            cur.push_back('(');
            //继续递归
            backtrack(ans, cur, left +1, right, n);
            //结果返回后，我们就弹出最后一个字符，来遍历其它的结果
            cur.pop_back();
        }
        //右括号的数量小于左括号的数量，则加入右括号
        if(right < left)
        {
            cur.push_back(')');
            backtrack(ans, cur, left, right +1, n);
            cur.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) 
    {
        if(n <= 0)
            return {};
        vector<string> res;
        string current; 
        backtrack(res, current, 0, 0, n);
        return res;
    }

};