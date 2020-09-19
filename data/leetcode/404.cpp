#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

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
    int sumOfLeftLeaves(TreeNode* root) 
    {
        int sum = 0;
        queue<pair<TreeNode*, int>> que_;
        if(root == NULL)
            return 0;
        que_.push({root, 0});
        while(!que_.empty())
        {
            auto tmp = que_.front();
            que_.pop();
            TreeNode* p = tmp.first;
            if(p == NULL)
                continue;
            if(p->left == NULL && p->right == NULL && tmp.second == 1)
                sum += p->val;   
            else 
            {
                que_.push({p->left, 1});
                que_.push({p->right, 0});
            }
        }
        return sum;
    }
};

int main()
{
    Solution res;
    TreeNode* root = new TreeNode(3);
    std::cout << res.sumOfLeftLeaves(root) << "\n";
}