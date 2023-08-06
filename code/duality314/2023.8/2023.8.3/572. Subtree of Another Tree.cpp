#include <vector>
#include <queue>

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
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (p == nullptr && q == nullptr)
            return 1;
        else if (p == nullptr && q != nullptr)
            return 0;
        else if (p != nullptr && q == nullptr)
            return 0;
        else if (p->val != q->val)
            return 0;
        else
            return isSameTree(p->left, q->left) && isSameTree(q->right, p->right);
    }
    bool isSubtree(TreeNode *root, TreeNode *subRoot)
    {
        queue<TreeNode *> que;
        if (root)
        {
            que.push(root);
        }
        while (!que.empty())
        {
            int len = que.size();
            for (int i = 0; i < len; i++)
            {
                TreeNode *node = que.front();
                que.pop();
                if (isSameTree(node, subRoot))
                {
                    return 1;
                }
                if (node->left)
                    que.push(node->left);
                if (node->right)
                    que.push(node->right);
            }
        }
        return 0;
    }
};