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

class Solution 
{
public:
    bool isBalanced(TreeNode* root) 
    {
        bool flag = true;
        dfs(root, flag);
        return flag;
    }
    int dfs(TreeNode* node, bool& flag)
    {
        if(!flag)   
            return 0;
        if(node == NULL)
            return 0;
        int left = dfs(node->left, flag);
        int right = dfs(node->right, flag);
        if(!flag || abs(left - right) >= 2)
        {
            flag = false;
            return 0;
        }
        return max(left, right) + 1;
    }
};