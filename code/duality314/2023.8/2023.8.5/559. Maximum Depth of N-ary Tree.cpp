#include <vector>
#include <queue>
using namespace std;

class Node
{
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val)
    {
        val = _val;
    }

    Node(int _val, vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
};

class Solution
{
public:
    int maxDepth(Node *root)
    {
        int dep = 0;
        queue<Node *> que;
        if (root)
        {
            que.push(root);
        }
        while (!que.empty())
        {
            dep++;
            int len = que.size();
            for (int i = 0; i < len; i++)
            {
                Node *node = que.front();
                que.pop();
                for (auto child : node->children)
                {
                    if (child)
                        que.push(child);
                }
            }
        }
        return dep;
    }
};