#include<iostream>
#include<vector>
#include<algorithm>
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
    vector<int> inorderTraversal(TreeNode* root) 
    {
        vector<int> res;
        if(root == NULL)
            return res;
        stack<TreeNode*> st;
        TreeNode* temp = root;
        st.push(root);
        while(!st.empty())
        {
            while(temp->left != NULL)
            {
                temp = temp->left;
                st.push(temp);
            }
            TreeNode* p = st.top();
            st.pop();
            res.emplace_back(p->val);
            if(p->right != NULL)
            {
                st.push(p->right);
                temp = p->right;
            } 
        }  
        return res;      
    }
};

