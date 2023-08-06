#include <vector>
#include <queue>

using namespace std;
class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;
    Node() : val(0), left(NULL), right(NULL), next(NULL) {}
    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
class Solution
{
public:
    Node *connect(Node *root)
    {
        queue<Node *> que;
        int len = 0;
        if (root)
        {
            que.push(root);
            que.push(nullptr);
        }
        while (!que.empty())
        {
            len = que.size() - 1;
            for (int i = 0; i < len; i++)
            {
                Node *node = que.front();
                que.pop();
                if (node->left)
                    que.push(node->left);
                if (node->right)
                    que.push(node->right);
                if (que.front() == nullptr)
                {
                    node->next = nullptr;
                }
                else
                    node->next = que.front();
            }
            que.push(nullptr);
        }
    }
};