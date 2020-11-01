#include<iostream>
#include<algorithm>
#include<vector>
#include<memory>

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
    TreeNode* build(vector<int>& preorder, int p_start, int p_end, 
                    vector<int>& inorder, int i_start, int i_end)
    {
        if(p_start > p_end)
            return NULL;
        int root_val = preorder[p_start];
        TreeNode* root = new TreeNode(root_val);
        int i;
        for(i = i_start; i <= i_end; ++i)
        {
            if(inorder[i] == root_val)
            {
                break;
            }
        }
        int l_size = i - i_start;
        root->left = build(preorder, p_start+1, p_start + l_size, inorder, i_start, i_start + l_size -1);
        root->right = build(preorder, p_start + l_size + 1, p_end, inorder, i_start + l_size + 1, i_end);
        return root;
    }


    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        return build(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);        
    }
};