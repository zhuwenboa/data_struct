#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*
本题是寻找二叉搜索树中的众数，有二叉搜索树这个概念，那么我们就可以从中序遍历中获取排序好的数，然后进行遍历比较。
*/
class Solution 
{
public:
    void mid_order(TreeNode* root, vector<int>& cur)
    {
        if(!root)
            return;
        mid_order(root->left, cur);
        cur.emplace_back(root->val);
        mid_order(root->right, cur);
    }

    vector<int> findMode(TreeNode* root) 
    {
        if(!root)
            return {};
        int count = 0;
        int maxCount = 0;
        int base = INT32_MIN;
        vector<int> num_;
        vector<int> ans;
        mid_order(root, num_);
        for(int i = 0; i < num_.size(); ++i)
        {
            if(num_[i] == base)
            {
                ++count;
            }
            else 
            {
                count = 1;
                base = num_[i];
            }
            if(count == maxCount)
                ans.emplace_back(num_[i]);
            else if(count > maxCount)
            {
                maxCount = count;
                ans.clear();
                ans.emplace_back(num_[i]);
            }
        }
        return ans;
    }
};