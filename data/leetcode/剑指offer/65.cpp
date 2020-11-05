#include<iostream>

//二进制运算

class Solution 
{
public:
    int add(int a, int b) 
    {
        //当不需要进位时退出循环
        while(b != 0)
        {
            //需要进位的和 负数不能进行移位操作
            int c = (unsigned int)(a & b) << 1;        
            //不需要进位的和
            a ^= b;
            b = c;
        }
        return a;
    }
};