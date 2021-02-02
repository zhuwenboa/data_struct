#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution
{
public:   
    void mergesort(vector<int>& vec, int l, int r)
    {
        if(l >= r)
            return;
        int mid = (l + r) / 2;
        mergesort(vec, l, mid);
        mergesort(vec, mid + 1, r);
        merge(vec, l, mid, r);
    }
    void merge(vector<int>& vec, int low, int mid, int high)
    {
        vector<int> tmp(high - low + 1);
        int tmp_index = 0;
        int i = low;
        int j = mid + 1;
        while(i <= mid && j <= high)
        {
            tmp[tmp_index] = vec[i] < vec[j] ? vec[i++] : vec[j++];
            tmp_index++;
        }
        while(i <= mid)
        {
            tmp[tmp_index] = vec[i];
            tmp_index++;
            i++;
        }
        while(j <= high)
        {
            tmp[tmp_index] = vec[j];
            tmp_index++;
            j++;
        }
        for(i = low, tmp_index = 0; tmp_index < tmp.size(); ++tmp_index, ++i)
            vec[i] = tmp[tmp_index];
    }    
};

int main()
{
    vector<int> vec{9, 8, 7, 6, 5, 4, 2, 1, 3};
    Solution res;
    res.mergesort(vec, 0, vec.size()-1);
    for(const int& a : vec)
        std::cout << a << "\t";
    std::cout << "\n";
}