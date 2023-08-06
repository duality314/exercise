/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    void reorderList(ListNode *head)
    {
        int n = 0;
        if (head == nullptr)
            return;
        vector<ListNode *> vls;
        vls.push_back(nullptr);
        ListNode *cur = head;
        while (cur != nullptr)
        {
            vls.push_back(cur);
            cur = cur->next;
            n++;
        }
        bool f = 1;
        int index1 = 0, index2 = 2;
        cur = head;
        n = vls.size() - 1;
        for (int i = 0; i < n - 1; i++)
        {
            if (f)
            {
                cur->next = vls[n - index1];
                index1++;
                f = 0;
            }
            else
            {
                cur->next = vls[index2];
                f = 1;
                index2++;
            }
            cur = cur->next;
        }
        // 链表末尾归为空指针，不然还连着之前的
        cur->next = nullptr;
    }
};