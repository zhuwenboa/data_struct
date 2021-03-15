#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution 
{
public:
    int max_sum_dfs(TreeNode* node, int& ans)
    {
        int max_left = 0, max_right = 0;
        if(node->left != NULL)
            max_left = max(0, max_sum_dfs(node->left, ans));
        if(node->right != NULL)
            max_right = max(0, max_sum_dfs(node->right, ans));
        int cur_sum = node->val + max_left + max_right;
        ans = max(ans, cur_sum);
        return max_left > max_right ? node->val + max_left : node->val + max_right;
    }
    int maxPathSum(TreeNode* root) 
    {
        if(!root)
            return 0;
        int ans = INT32_MIN;
        max_sum_dfs(root, ans);
        return ans;
    }
};