#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

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
    void dfs(TreeNode* node, int cur, vector<int>& ans)
    {
        if(node->left == NULL && node->right == NULL)
        {
            ans.push_back(cur*10 + node->val);
        }
        if(node->left != NULL)
        {
            dfs(node->left, cur*10 + node->val, ans);
        }
        if(node->right != NULL)
        {
            dfs(node->right, cur*10 + node->val, ans);
        }
    }
    int sumNumbers(TreeNode* root) 
    {
        if(root == NULL)
            return 0;
        vector<int> ans;
        dfs(root, 0, ans);
        int sum = 0;
        for(int i = 0; i < ans.size(); ++i)
        {
            sum += ans[i];
        }
        return sum;
    }
};