#include<iostream>
#include<algorithm>
#include<vector>

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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) 
    {
        if(!root)
            return {};
        vector<vector<int>> ans;
        vector<int> cur;
        backtrack(root, cur, ans, targetSum);
        return ans;
    }
    void backtrack(TreeNode* node, vector<int>& cur, vector<vector<int>>& ans, int target)
    {
        if(node->val == target && !node->left && !node->right)
        {
            cur.emplace_back(node->val);
            ans.emplace_back(cur);
            cur.pop_back();
            return;
        }
        cur.emplace_back(node->val);
        if(node->left)
            backtrack(node->left, cur, ans, target - node->val);
        if(node->right)
            backtrack(node->right, cur, ans, target - node->val);
        cur.pop_back();
    }
};