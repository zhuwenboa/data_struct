#include<iostream>
#include<algorithm>
#include<vector>

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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        return inorder_build(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
    }
    TreeNode* inorder_build(vector<int>& preorder, int p_start, int p_end, vector<int>& inorder, int i_start, int i_end)
    {
        if(p_start > p_end)
            return NULL;
        int cur_root_val = preorder[p_start];
        TreeNode* root = new TreeNode(cur_root_val);
        int i_root;
        for(int i = i_start; i <= i_end; ++i)
        {
            if(inorder[i] == cur_root_val)
            {
                i_root = i;
                break;
            }
        }
        int left_size = i_root - i_start;
        root->left = inorder_build(preorder, p_start+1, p_start + left_size, inorder, i_start, i_root-1);
        root->right = inorder_build(preorder, p_start + left_size+1, p_end, inorder, i_root + 1, i_end);
        return root;
    }
};