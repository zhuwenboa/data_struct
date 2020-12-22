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
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution 
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
        if(root == NULL)
            return {};
        vector<vector<int>> ans;
        bool flag = true;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty())
        {
            vector<int> cur;
            int size = que.size();
            for(int i = 0; i < size; ++i)
            {
                TreeNode* tmp = que.front();
                cur.emplace_back(tmp->val);
                que.pop();
                if(tmp->left != NULL)
                    que.push(tmp->left);
                if(tmp->right != NULL)
                    que.push(tmp->right);
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
