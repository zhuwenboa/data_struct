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
        TreeNode* temp = root->left;
        st.push(root);
        while(!st.empty())
        {
            while(temp != NULL)
            {
                st.push(temp);
                temp = temp->left;
            }
            temp = st.top();
            st.pop();
            res.emplace_back(temp->val);
            temp = temp->right;
        }  
        return res;      
    }
};

