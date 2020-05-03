#include<iostream>
#include<vector>
//最大子序和
using namespace std;

class Solution 
{
public:
    int maxSubArray(vector<int>& nums) 
    {
        int res = nums[0];
        int pre;
        int count = nums.size();
        pre = nums[0];

        for(int i = 1; i < count; ++i)
        {
            pre = max(nums[i], pre+nums[i]);
            res = max(res, pre);
        }
        return res;
    }
};

//分治法 线段树
class Solution2
{
public:  
    struct status 
    {
        //lsum表示[l,r]区间内以l为左端点的最大子段和,rsum表示[l,r]内以r为右端点的最大子段和
        //msum表示[l,r]内的最大子段和，isum表示[l,r]的区间和
        int lsum, rsum, msum, isum;
    };
    status pushup(status l, status r)
    {
        int isum = l.isum + r.isum;
        int lsum = max(l.lsum, l.isum + r.lsum);
        int rsum = max(r.rsum, l.rsum + r.isum);
        int msum = max(max(l.msum, r.msum), l.rsum + r.lsum);
        return status{lsum, rsum, msum, isum};
    }
    status get(vector<int>& vec, int l, int r)
    {
        if(l == r)
            return status{vec[l], vec[l], vec[l], vec[l]};
        int mid = (l + r) >> 1;
        status lsub = get(vec, l, mid);
        status rsub = get(vec, mid + 1, r);
        return pushup(lsub, rsub);
    }
    int maxSubArray(vector<int>& nums)
    {
        return get(nums, 0, nums.size()-1).msum;
    }
};

int main()
{
    Solution2 solut;
    vector<int> a;
    int temp;
    while(cin >> temp)
        a.emplace_back(temp);
    int result = solut.maxSubArray(a);
    cout << result <<endl;
    
}