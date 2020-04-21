#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<map>

using namespace std;

class Solution 
{
public:
    bool wordPattern(string pattern, string str) 
    {
        vector<string> lis;
        map<char, int> s1;
        map<string, int> s2;
        int pos = 0;
        int i = 0;
        while(pos != -1)
        {
            pos = str.find_first_of(' ', i);
            string temp = str.substr(i, pos-i);
            lis.push_back(temp);
            i = pos+1;
        }
        if(pattern.size() == 0 || pattern.size() > lis.size())
            return false;
        for(int i = 0; i < lis.size(); ++i)
        {
            if(s2.count(lis[i]))
            {
                int str_index = s2[lis[i]];
                if(!s1.count(pattern[i]))
                    return false;
                int pat_index = s1[pattern[i]];
                if(str_index != pat_index)
                    return false;
            }
            else
            {
                s2.insert({lis[i], i});
                if(s1.count(pattern[i]))
                    return false;
                s1.insert({pattern[i], i});
            }
        }
        return true;
    }
};

int main()
{
    string pattern = "abba";
    string str = "dog cat cat dog";
    Solution res;
    std::cout << res.wordPattern(pattern, str) << "\n";
}