#include<iostream>
#include<algorithm>
//分治算法
class solution
{
public:  
    solution () : num(0) {}
    void mergesort(int a[], int q, int r)
    {
        if(q >= r)
            return;
        int p = (q + r) / 2;
        mergesort(a, q, p);
        mergesort(a, p + 1, r);
        merge(a, q, p, r);
    }
    int res() { return num;}
private:
    int num;
    void merge(int a[], int q, int p, int r)
    {
        int i = q, j = p + 1, k = 0;
        int *temp = new int[r - q + 1];
        while(i <= p && j <= r)
        {
            if(a[i] <= a[j])
            {
                temp[k++] = a[i++];
            }
            else 
            {
                num += (p - i + 1);
                temp[k++] = a[j++];
            }
        }
        while(i <= p)
            temp[k++] = a[i++];
        while(j <= r)
            temp[k++] = a[j++];
        for(int i = 0; i <= r - q; ++i)
        {
            a[q + i] = temp[i];
        }
    }
    
};

int main()
{
    solution result;
    int a[] = {2, 4, 3, 1, 5, 6};
    result.mergesort(a, 0, 5);
    std::cout << "num: " << result.res() << std::endl;
    for(int i = 0; i < 6; i ++)
    {
        std::cout << "a[i] = " << a[i] << "\n";
    }
}