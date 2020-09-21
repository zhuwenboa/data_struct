#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct ListNode 
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/*
解题思路：由题可知链表是升序排列，我们可以得到一个排序的数组。
然后是建树，因为要建立平衡搜索二叉树，那左右子节点高度差不能超过1。
有了上述两个条件，那我们就可以用分治的思想
每次选取数组的中间节点。其左边都比他小，右边都比他大，并且左右节点差肯定不会大于1。
思路想好，那我们就直接代码实现
*/
class Solution 
{
public:
    TreeNode* transform(vector<int>& vec, int begin, int end)
    {
        if(begin > end)
        {
            return nullptr;
        }
        int mid = (begin + end) / 2;
        TreeNode* node = new TreeNode(vec[mid]);
        node->left = transform(vec, begin, mid-1);
        node->right = transform(vec, mid+1, end);
        return node;
    }
    TreeNode* sortedListToBST(ListNode* head) 
    {
        vector<int> vec;
        while(head != NULL)
        {
            vec.emplace_back(head->val);
            head = head->next;
        }
        return transform(vec, 0, vec.size()-1);
    }
};