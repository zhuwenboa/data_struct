#include<iostream>
#include<memory>
#include<algorithm>

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
    TreeNode* convertBiNode(TreeNode* root) 
    {
        TreeNode *head = new TreeNode(0);
        inorder(root, head);
        return head->right;
    }
    TreeNode* inorder(TreeNode* root, TreeNode *prev)
    {
        if(root != NULL)
        {
            prev = inorder(root->left, prev);
            root->left = NULL;
            prev->right = root;
            prev = root;
            prev = inorder(root->right, prev);
        }
        return prev;
    }
};
