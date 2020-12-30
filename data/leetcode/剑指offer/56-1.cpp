#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

/*
题目描述：
一个整型数组 nums 里除两个数字之外，其他数字都出现了两次。
请写程序找出这两个只出现一次的数字。要求时间复杂度是O(n)，空间复杂度是O(1)。
*/    


class Solution 
{
public:
    vector<int> singleNumbers(vector<int>& nums) 
    {
        //先对数组进行异或
        int ret = 0;
        for(int num : nums)
            ret ^= num;
        //ret保存的是两个不相同数的异或值
        //然后找到异或答案中的任意一位1
        int div = 1;
        while((div & ret) == 0)
            div <<= 1;
        //找到一位1，证明两个数在这一位上不相同。然后进行分组
        int a = 0, b = 0;
        for(int num : nums)
        {
            if(num & div)
                a ^= num;
            else    
                b ^= num;
        }
        return {a, b};
    }
};