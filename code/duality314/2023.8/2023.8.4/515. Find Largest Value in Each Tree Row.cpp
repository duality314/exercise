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
    vector<int> largestValues(TreeNode *root)
    {
        vector<int> re;
        queue<TreeNode *> que;
        int len = 0;
        if (root)
        {
            que.push(root);
        }
        while (!que.empty())
        {
            len = que.size();
            int mmax = INT_MIN;
            for (int i = 0; i < len; i++)
            {
                TreeNode *node = que.front();
                que.pop();
                mmax = max(mmax, node->val);
                if (node->left)
                    que.push(node->left);
                if (node->right)
                    que.push(node->right);
            }
            re.push_back(mmax);
        }
        return re;
    }
};