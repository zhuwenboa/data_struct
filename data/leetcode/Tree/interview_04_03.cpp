#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<memory>

using namespace std;

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution 
{
public:
    vector<ListNode*> listOfDepth(TreeNode* tree) 
    {
        queue<TreeNode*> que;
        if(!tree)
            return {};
        vector<ListNode*> ans;
        que.push(tree);
        ListNode* root = new ListNode(0);
        while(!que.empty())
        {
            //一次循环遍历树的一层
            int n = que.size();
            ListNode* p = root;
            for(int i = 0; i < n; ++i)
            {
                TreeNode* t = que.front();
                que.pop();
                ListNode* cur = new ListNode(t->val);
                p->next = cur;
                p = p->next;
                if(t->left)
                    que.push(t->left);
                if(t->right)
                    que.push(t->right);
            }
            ans.emplace_back(root->next);
        }
        return ans;
    }
};

int main()
{
    Solution res;
    TreeNode *root = new TreeNode(3);
    auto a = res.listOfDepth(root);
    std::cout << a.front()->val << "\n";
}