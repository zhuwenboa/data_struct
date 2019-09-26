#include<iostream>
#include<array>
#include<memory>
class search
{
public:
    int s1(int arr[], int len, int ser); //二分查找查找一个数
    int s2(int arr[], int len, int ser); //二分查找 找出第一个值等于给定的元素
    int s3(int arr[], int len, int ser);//查找最后一个值等于给定的元素
    int s4(int arr[], int len, int ser);//查找第一个大于等于给定元素的值
    int s5(int arr[], int len, int ser);//查找最后一个小于等于给定元素的值
};

int search::s1(int arr[], int len, int ser)
{
    int low = 0;
    int high = len - 1;
    int mid;
    while(low <= high)
    {
        mid = low + ((high - low) >> 1); //避免数字溢出int范围
        if(arr[mid] == ser)
            return mid;
        else if(ser > arr[mid])
            low = mid + 1;
        else if(ser < arr[mid])
            high = mid - 1;        
    }
    return -1;
}

int search::s2(int arr[], int len, int ser)
{
    int low = 0;
    int high = len - 1;
    int mid;
    while(low <= high)
    {
        mid = low + ((high - low) >> 1);
        if(arr[mid] > ser)
            high = mid -1;
        else if(arr[mid] < ser)
            low = mid + 1;
        else
        {
            if(mid == 0 || arr[mid - 1] != ser)
                return mid;
            else 
                high = mid -1;
        }
        
    }
}

int search::s3(int arr[], int len, int ser)
{
    int low = 0;
    int high = len - 1;
    int mid;
    while(low <= high)
    {
        mid = low + ((high - low) >> 1);
        if(arr[mid] > ser)
            high = mid - 1;
        else if(arr[mid] < ser)
            low = mid + 1;
        else
        {
            if(mid == (len -1) || arr[mid + 1] != ser)
                return mid;
            else
                low = mid + 1;
        }
    }
}

int search::s4(int arr[], int len, int ser)
{
    int low = 0;
    int high = len - 1;
    int mid;
    while(low <= high)
    {
        mid = low + ((high - low) >> 1);
        if(arr[mid] < ser)
            low = mid + 1;
        else
        {
            if(mid == 0 || arr[mid - 1] < ser)
                return mid;
            else
            {
                high = mid - 1;   
            }
        }
        
    }
}

int search::s5(int arr[], int len, int ser)
{
    int low = 0; 
    int high = len - 1;
    int mid;
    while(low <= high)
    {
        mid = low + ((high - low ) >> 1);
        if(arr[mid] > ser)
            high = mid -1;
        else 
        {
            if(mid == 0 || arr[mid + 1]  >ser)
                return mid;
            else 
                low = mid + 1;
        }
    }
}
int main()
{
    int arr[15] = {1, 3, 5, 5, 5, 6, 6, 9, 17, 21, 35, 36, 36, 49, 100};
    search solution;
    int result;
    result = solution.s1(arr, 15, 17);
    std::cout << "17 is in arr " << result << "\n";
    result = solution.s2(arr, 15, 5);
    std::cout << "first 5 is in arr " << result << std::endl;
    result = solution.s3(arr, 15, 6);
    std::cout << "last 6 is in arr" << result << std::endl;
    result = solution.s4(arr, 15, 10);
    std::cout << "the first big than 10 is " << result << "\n";
    
    result = solution.s5(arr, 15, 6);
    std::cout << "last small than 6 is " << result  << "\n";
    return 0;
}