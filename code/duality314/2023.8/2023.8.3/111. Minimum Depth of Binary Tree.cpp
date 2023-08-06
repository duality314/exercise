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
    int minDepth(TreeNode *root)
    {
        int re = 0;
        queue<TreeNode *> que;
        if (root)
        {
            que.push(root);
        }
        while (!que.empty())
        {
            re++;
            int len = que.size();
            for (int i = 0; i < len; i++)
            {
                TreeNode *node = que.front();
                que.pop();
                if (node->left)
                    que.push(node->left);
                if (node->right)
                    que.push(node->right);
                if (node->right == nullptr && node->left == nullptr)
                {
                    return re;
                }
            }
        }
        return re;
    }
};
