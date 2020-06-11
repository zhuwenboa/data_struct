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
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution 
{
public:
    vector<int> postorderTraversal(TreeNode* root) 
    {
        if(root == NULL)
            return {};
        vector<int> res;
        stack<TreeNode*> st;
        TreeNode* p = root;
        TreeNode* pre = NULL;
        while(!st.empty() || p)
        {
            while(p != NULL)
            {
                st.push(p);
                p = p->left;
            }
            p = st.top();
            if(p->right != NULL && pre != p->right)
            {
                p = p->right;
            }
            else 
            {
                res.emplace_back(p->val);
                st.pop();
                pre = p;
                p = NULL;
            }
        }
        return res;
    }
};