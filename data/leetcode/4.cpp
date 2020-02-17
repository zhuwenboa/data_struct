#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution 
{
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        int len1 = nums1.size();
        int len2 = nums2.size();
        int left = (len1 + len2 + 1) / 2;
        int right = (len1 + len2 + 2) / 2;
        return (getKmin(nums1, 0, len1 -1, nums2, 0, len2 -1, left) + getKmin(nums1, 0, len1 -1, nums2, 0, len2 -1, right)) * 0.5;         
    }
private:   
    /*
    double getKmin(vector<int>& nums1, int start_1, vector<int> &nums2, int start_2, int mid, int flag)
    {
        if(mid == 1)
        {
            //第一个数组元素全部被抛弃,用大于等于是为了防止nums1数组没有元素
            if(start_1 >= nums1.size() -1)
            {
                if(!flag)
                    return nums2[start_2] / 2.0;
                else
                    return (nums2[start_2 - 1] + nums2[start_2]) / 2.0;
            }
            if(start_2 >= nums2.size() -1)
            {
                if(!flag)
                    return nums1[start_1] / 2.0;
                else
                    return (nums1[start_1 - 1] + nums1[start_1]) / 2.0;
            }    
            else 
            {
                if(!flag)
                {
                    int num = min(nums1[start_1], nums2[start_2]);
                    return num / 2.0;
                }
                else
                {
                    int num1 = max(nums1[start_1 -1], nums2[start_2 -1]);
                    int num2 = min(nums1[start_1 -1], nums2[start_2 -1]);
                    return (num1 + num2) / 2.0;
                }
            }
            int k = mid / 2;
            if((k + start_1) > nums1.size())
            {
                int temp = nums1.size() - start_1 -1;
                if(temp <= 0)
                {
                    if(!flag)
                        return nums2[start_2 + mid -1] / 2.0;
                    else
                    {
                        return (nums2[start_2 + mid - 2] + nums2[start_2 + mid -1]) / 2.0;
                    }
                    
                }
                if(nums1[start_1 + temp] < nums2[start_2 + k -1])
                {
                    start_1 += temp;
                    return getKmin(nums1, start_1, nums2, start_2, mid - temp, flag);
                }
            }
        }    
    }
    */
    double getKmin(vector<int>& nums1, int start_1, int end_1, vector<int> &nums2, int start_2, int end_2, int k)
    {
        int len1 = end_1 - start_1 + 1;
        int len2 = end_2 - start_2 + 1;
        //让len1的长度小于len2,因为是找中位数，如果出现数组为空，肯定是含元素较少的数组为空
        if(len1 > len2)
            return getKmin(nums2, start_2, end_2, nums1, start_1, end_1, k);
        if(len1 == 0)
            return nums2[start_2 + k -1];
        if(k == 1)
            return min(nums1[start_1], nums2[start_2]);
        int i = start_1 + min(len1, k / 2) -1;
        int j = start_2 + min(len2, k / 2) -1;
        if(nums1[i] > nums2[j])
        {
            return getKmin(nums1, start_1, end_1, nums2, j + 1, end_2, k - (j - start_2 + 1));
        }
        else 
            return getKmin(nums1, i + 1, end_1, nums2, start_2, end_2, k - (i -start_1 + 1));
    }
};