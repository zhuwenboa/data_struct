#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
/*
利用二叉搜索树的性质:
    中序遍历是将树中的值从小到大进行排列。
    题目为了求第ｋ大的数，那我们可以进行反向的中序遍历，
    让其从大到小排列，不需要额外数组存储，节省空间。
*/
class Solution 
{
public:
    int kthLargest(TreeNode* root, int k) 
    {
        if(root == NULL || k == 0)
            return -1;
        int ans;
        inorder(root, ans, k);
        return ans;
    }
    void inorder(TreeNode* node, int& ans, int& k)
    {
        if(k <= 0)
            return;
        if(node->right != NULL)
            inorder(node->right, ans, k);
        --k;
        if(k == 0)  
            ans = node->val;
        if(node->left != NULL)
            inorder(node->left, ans, k);
    }
};