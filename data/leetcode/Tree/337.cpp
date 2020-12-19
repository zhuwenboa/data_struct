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
    int rob(TreeNode* root) 
    {
        auto res = dp(root);
        return max(res.first, res.second);
    }
    /*
        pair.first代表选择当前节点，pair.second代表不选择当前节点
    */
    pair<int, int> dp(TreeNode* root)
    {
        if(root == NULL)
            return {0, 0};
        auto left = dp(root->left);
        auto right = dp(root->right);
        pair<int, int> cur;
        cur.first = left.second + right.second + root->val;
        cur.second = max(left.first, left.second) + max(right.first,right.second);
        return cur;
    }
};