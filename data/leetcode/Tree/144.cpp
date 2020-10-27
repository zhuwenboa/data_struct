#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
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
    vector<int> preorderTraversal(TreeNode* root) 
    {
        if(root == NULL)
            return {};
        vector<int> ans;
        stack<TreeNode*> st;
        TreeNode* tmp = root;
        while(!st.empty() || tmp != NULL)
        {
            while(tmp != NULL)
            {
                ans.push_back(tmp->val);
                st.push(tmp);
                tmp = tmp->left;
            }
            tmp = st.top()->right;
            st.pop();
        }       
        return ans; 
    }
};