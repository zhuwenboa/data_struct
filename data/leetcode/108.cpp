#include<iostream>
#include<vector>
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
    TreeNode* sortedArrayToBST(vector<int>& nums) 
    {
        return bulid(nums, 0, nums.size() -1);
        
    }
    
    TreeNode* bulid(vector<int>& nums, int start, int end)
    {
        if(start > end)
            return NULL;
        int mid = (start + end) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = bulid(nums, start, mid -1);
        root->right = bulid(nums, mid + 1, end);
        return root;
    }
};