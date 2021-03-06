#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution 
{
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
    {
        int index = m + n -1;
        int index_nums2 = m -1;
        int index_nums1 = n-1;
        while(index_nums1 >= 0 && index_nums2 >= 0)
        {
            nums1[index--] = nums1[index_nums1] > nums2[index_nums2] ? nums1[index_nums1--] : nums2[index_nums2--];
        }
        while(index_nums2 >= 0)
            nums1[index--] = nums2[index_nums2--];
    }
};

int main()
{
    vector<int> vec1{1, 2, 3, 0, 0, 0};
    vector<int> vec2{0, 4, 6};
    Solution res;
    res.merge(vec1, 3, vec2, 3);
    for(const int& a : vec1)
        std::cout << a << "\n";
}