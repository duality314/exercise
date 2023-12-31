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
};