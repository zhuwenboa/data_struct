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
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution 
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
        if(!root)
            return {};
        queue<TreeNode*> que_;
        bool flag = true;
        vector<vector<int>> ans;
        que_.push(root);
        while(!que_.empty())
        {
            int size = que_.size();
            vector<int> cur(size);
            for(int i = 0; i < size; ++i)
            {
                TreeNode* tmp = que_.front();
                que_.pop();
                cur[i] = tmp->val;
                if(tmp->left)
                    que_.push(tmp->left);
                if(tmp->right)
                    que_.push(tmp->right);
            }
            if(!flag)
            {
                reverse(cur.begin(), cur.end());
                flag = true;
            }
            else 
                flag = false;
            ans.emplace_back(cur);
        }
        return ans;
    }
};