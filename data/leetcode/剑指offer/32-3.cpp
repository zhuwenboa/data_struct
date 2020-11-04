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
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        if(root == nullptr)
            return {};
        vector<vector<int>> ans;
        queue<TreeNode*> que;
        que.push(root);
        bool flag = true;
        while(!que.empty())
        {
            int n = que.size();            
            vector<int> cur;
            for(int i = 0; i < n; ++i)
            {
                TreeNode* node = que.front();
                que.pop();
                cur.emplace_back(node->val); 
                if(node->left)
                    que.push(node->left);
                if(node->right)
                    que.push(node->right);
            }
            if(!flag)
            {
                flag = true;
                reverse(cur.begin(), cur.end());
            }
            else 
                flag = false;
            ans.push_back(cur);
        }
        return ans;
    }
};