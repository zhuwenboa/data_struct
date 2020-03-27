#include<iostream>
#include<vector>
//验证二叉搜索树
using namespace std;

 struct TreeNode 
 {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//方法一：用数组存储中序遍历的结果，如果数组不是递增序列则false，否则为true
class Solution 
{
public:
    bool isValidBST(TreeNode* root) 
    {
        vector<int> vec;
        midTraverse(root, vec);
        bool flag = true;
        for(int i = 1; i <= vec.size(); ++i)
        {
            if(vec[i] < vec[i-1])
            {
                flag = false;
                break;
            }
        } 
        return flag;  
    }
    
    void midTraverse(TreeNode* root, vector<int>& vec)
    {
        if(root == NULL)
            return;
        midTraverse(root->left, vec);
        vec.emplace_back(root->val);
        midTraverse(root->right, vec);
    }
};

//方法二 递归法判断是否为二叉搜索树
class Solution2 
{
public:
    bool isValidBST(TreeNode* root) 
    {
        return helper(root, NULL, NULL);
    }
    bool helper(TreeNode* root,  const int* lower, const int* upper)
    {
        if(root == NULL)
            return true;
        int val = root->val;
        if(lower != NULL && val >= *lower)
            return false;
        if(upper != NULL && val <= *upper)
            return false;
        if(!helper(root->right, lower, &val))
            return false;
        if(!helper(root->left, &val, upper))
            return false;
        return true;
    }
};