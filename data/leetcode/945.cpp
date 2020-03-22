#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<unordered_set>

using namespace std;

class Solution {
public:
    int minIncrementForUnique(vector<int>& A) 
    {
        sort(A.begin(), A.end());
        int step = 0;
        for(int i = 1; i < A.size(); ++i)
        {
            if(A[i] == A[i -1])
            {
                ++A[i];
                ++step;
            }
            else if(A[i] < A[i -1])
            {
                step += A[i -1] -A[i] + 1;
                A[i] = A[i -1] + 1;
            }
        }
        return step;
    }
};


class Solution2 {
public:
    //该方法超时,用暴力法，为O(N方)
    int minIncrementForUnique(vector<int>& A) 
    {
        int step = 0;
        unordered_set<int> judge;
        for(int i = 0; i < A.size(); ++i)
        {
            if(judge.count(A[i]) > 0)
            {
                do
                {
                    ++A[i];
                    ++step;
                } while (judge.count(A[i]) > 0);
                judge.insert(A[i]);  
            }
            else
            {
                judge.insert(A[i]);   
            }
        }  
        return step;                      
    }
};

int main()
{
    vector<int> vec{1, 2, 2};
    Solution res;
    std::cout << res.minIncrementForUnique(vec) << "\n";
}