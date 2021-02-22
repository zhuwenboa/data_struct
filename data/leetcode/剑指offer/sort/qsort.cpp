#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution
{
public:   
    void qsort(vector<int>& vec, int l, int r)
    {
        if(l >= r)
            return;
        int mid = partition(vec, l, r);
        qsort(vec, l, mid - 1);
        qsort(vec, mid+1, r);
    }
    int partition(vector<int>& vec, int l, int r)
    {
        if(l >= r)
            return l;
        int judge = vec[l];
        while(l < r)
        {
            while(l < r && vec[r] >= judge)
                --r;
            swap(vec[l], vec[r]);
            while(l < r && vec[l] <= judge)
                ++l;
            swap(vec[l], vec[r]);
        }
        return l;
    }
};

int main()
{
    vector<int> vec{9, 8, 7, 6, 5, 4 ,3, 1, 1};
    Solution res;
    res.qsort(vec, 0, vec.size()-1);
    //swap(vec[0], vec[0]);
    for(const int& a : vec)
    {
        std::cout << a << "\t";
    }
    std::cout << "\n";
}