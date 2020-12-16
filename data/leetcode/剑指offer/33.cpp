#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution 
{
public:
    bool verifyPostorder(vector<int>& postorder) 
    {
        return judge_Tree(postorder, 0, postorder.size()-1);
    }
    bool judge_Tree(const vector<int>& postorder, int left_index, int right_index)
    {
        if(left_index >= right_index)
            return true;
        int cur_root = postorder[right_index];
        int pos_index = left_index;
        /*
            找到右子树的节点
        */
        while(pos_index < right_index)
        {
            if(postorder[pos_index] > cur_root)
                break;
            pos_index++;
        }
        int partition = pos_index;
        //在右子树中如果有小于root节点，则返回false
        while(pos_index < right_index)
        {
            if(postorder[pos_index] < cur_root)
                return false;
            pos_index++;
        }
        //递归判断左子树和右子树
        return judge_Tree(postorder, left_index, partition - 1) 
                && judge_Tree(postorder, partition, right_index-1);
    }
};