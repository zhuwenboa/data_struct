#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>

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
    vector<int> inorderTraversal(TreeNode* root) 
    {
        stack<TreeNode*> st_;
        vector<int> ans;
        TreeNode* p = root;
        while(!st_.empty() || p != NULL)
        {
            while(p)
            {
                st_.push(p);
                p = p->left;
            }
            TreeNode* tmp = st_.top();
            st_.pop();
            ans.emplace_back(tmp->val);
            if(tmp->right)
                p = tmp->right;
        }
        return ans;
    }
};