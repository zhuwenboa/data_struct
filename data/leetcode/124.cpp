#include<iostream>
#include<algorithm>
#include<vector>

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
    int maxPathSum(TreeNode* root) 
    {
        path(root);
        return max_sum;        
    }

    int path(TreeNode* node)
    {
        if(node == NULL)
            return  0;
        int left_max = max(path(node->left), 0);
        int right_max = max(path(node->right), 0);

        int cur_sum = node->val + left_max + right_max;
        max_sum = max(max_sum, cur_sum);
        return node->val + max(left_max, right_max);
    }

private:
    int max_sum = INT32_MIN;

};