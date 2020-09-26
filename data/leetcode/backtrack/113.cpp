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
    void backtrack(vector<vector<int>>& ans, vector<int>& cur, TreeNode* node, int target)
    {
        if(!node->left && !node->right && target - node->val == 0)
        {
            cur.emplace_back(node->val);
            ans.emplace_back(cur);
            cur.pop_back();
            return;
        }
        cur.emplace_back(node->val);
        if(node->left)
            backtrack(ans, cur, node->left, target - node->val);
        if(node->right)
            backtrack(ans, cur, node->right, target - node->val);
        cur.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int sum) 
    {
        if(!root)
            return {};
        vector<vector<int>> ans;
        vector<int> cur;
        backtrack(ans, cur, root, sum);
        return ans;
    }
};