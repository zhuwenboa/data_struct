#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<stack>
#include<sstream>
using namespace std;

class Solution {
public:
    bool isValid(string s) 
    {
        stack<char> st;
        for(auto a = s.begin(); a != s.end(); ++a)
        {
            if(*a == '(' || *a == '[' || *a == '{')
            {
                st.push(*a);
            }
            else if(*a == ')')
            {
                if(st.empty() || st.top() != '(')
                    return false;
                st.pop();
            }
            else if(*a == ']')
            {
                if(st.empty() || st.top() != '[')
                    return false;
                st.pop();
            }
            else if(*a == '}')
            {
                if(st.empty() || st.top() != '{')
                    return false;
                st.pop();
            }
        }
        if(st.empty())
            return true;
        else
            return false;
    }
    /*
    bool isValid(string s) {
       stack<char>sta;
       int len = s.size();
       if(!len) return true;
       if(len%2==1) return false;//先把边界条件写好
       for(int i=0;i<len;++i){
            if(sta.empty()){
                sta.push(s[i]);
                continue;
            }
            if(sta.top()=='('&&s[i]==')'){
                sta.pop();
                continue;
            }
            if(sta.top()=='['&&s[i]==']'){
                sta.pop();
                continue;
            }
            if(sta.top()=='{'&&s[i]=='}'){
                sta.pop();
                continue;
            }
            sta.push(s[i]);
       }
       return sta.empty();
    }

作者：d__wade
链接：https://leetcode-cn.com/problems/valid-parentheses/solution/c-zhan-hen-hao-li-jie-by-d__wade/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
    */
};

int main()
{
    string s;
    cin >> s;
    Solution result;
    std::cout << result.isValid(s) << "\n";
}