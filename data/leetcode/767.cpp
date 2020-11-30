#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

class Solution 
{
public:
    string reorganizeString(string S) 
    {
        if(S.size() < 2)
            return S;
        //记录字符串中每个字符出现的个数
        vector<int> count(26);
        int maxCount = 0;
        for(int i = 0; i < S.size(); ++i)
        {
            count[S[i] - 'a']++;
            maxCount = max(maxCount, count[S[i] - 'a']);
        }
        if(maxCount > (S.size() + 1) / 2)
            return "";
        auto cmp = [&](const char& a, const char& b)
                    {
                        return count[a - 'a'] < count[b - 'a'];
                    };
        //构造大顶堆
        priority_queue<char, vector<char>, decltype(cmp)> queue(cmp);
        for(char a = 'a'; a <= 'z'; ++a)
        {
            if(count[a - 'a'] > 0)
                queue.push(a);
        }
        string ans;
        while(queue.size() > 1)
        {
            char tmp1 = queue.top();
            queue.pop();
            char tmp2 = queue.top();
            queue.pop();
            ans += tmp1;
            ans += tmp2;
            if(--count[tmp1-'a'] > 0)
                queue.push(tmp1);
            if(--count[tmp2-'a'] > 0)
                queue.push(tmp2);
        }
        if(queue.size() > 0)
            ans += queue.top();
        return ans;
    }
};