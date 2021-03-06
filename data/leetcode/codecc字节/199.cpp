#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

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
    vector<int> rightSideView(TreeNode* root) 
    {
        if(!root)
            return {};
        queue<TreeNode*> que_;
        vector<int> ans;
        que_.push(root);
        while(!que_.empty())
        {
            int size = que_.size();
            for(int i = 0; i < size; ++i)
            {
                TreeNode* tmp = que_.front();
                que_.pop();
                if(i == size -1)
                    ans.emplace_back(tmp->val);
                if(tmp->left)
                    que_.push(tmp->left);
                if(tmp->right)
                    que_.push(tmp->right);
            }
        }
        return ans;
    }
};