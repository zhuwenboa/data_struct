#include<iostream>
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

/*
class Solution 
{
public:
    bool isSubStructure(TreeNode* A, TreeNode* B) 
    {
        if(A == NULL || B == NULL)
            return false;
        vector<int> Atree;
        vector<int> Btree;
        Traverse(A, Atree);
        Traverse(B, Btree);
        int j = 0;
        for(int i = 0; i < Atree.size(); ++i)
        {
            if(j < Btree.size() && Atree[i] == Btree[j])
            {
                ++j;
            }
        }
        if(j == Btree.size())
            return true;
        return false;
    }
    void Traverse(TreeNode* root, vector<int>& vec)
    {
        stack<TreeNode*> st;
        st.push(root);
        TreeNode* temp = root;
        vec.emplace_back(temp->val);
        while(!st.empty())
        {
            if(temp->left != NULL)
            {
                st.push(temp->left);
                vec.emplace_back(temp->val);
                temp = temp->left;
            }
            else 
            {
                TreeNode* p = st.top();
                st.pop();
                if(p->right != NULL)
                {
                    st.push(p->right);
                    temp = p->right;
                }
            }
        }
    }
};
*/

class Solution 
{
public:
    bool helper(TreeNode* A, TreeNode* B) {

        if (A == NULL || B == NULL) 
        {
            return B == NULL ? true : false;
        }
        if (A->val != B->val) 
        {
            return false;
        }
        return helper(A->left, B->left) && helper(A->right, B->right);
    }
    bool isSubStructure(TreeNode* A, TreeNode* B) 
    {
        if (A == NULL || B == NULL) 
        {
            return false;
        }
        return helper(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B);
    }
};

