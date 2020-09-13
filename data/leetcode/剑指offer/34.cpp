#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>

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
    void dfs(TreeNode* root, int target, vector<vector<int>>& ans, vector<int>& cur)
    {
        if(root->left == NULL && root->right == NULL && (target-root->val) == 0)
        {
            cur.emplace_back(root->val);
            ans.emplace_back(cur);
            cur.pop_back();
            return;
        }
        if(root->left != NULL)
        {
            cur.emplace_back(root->val);
            dfs(root->left, target-root->val, ans, cur);
            cur.pop_back();
        }
        if(root->right != NULL)
        {
            cur.emplace_back(root->val);
            dfs(root->right, target-root->val, ans, cur);
            cur.pop_back();
        }
    }

    vector<vector<int>> pathSum(TreeNode* root, int sum) 
    {
        vector<vector<int>> ans;
        if(root == NULL)
            return ans;
        vector<int> cur;
        dfs(root, sum, ans, cur);
        return ans;
    }
};