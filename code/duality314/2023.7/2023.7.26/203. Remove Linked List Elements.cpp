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
    ListNode *removeElements(ListNode *head, int val)
    {
        ListNode *vHead = new ListNode(0); // 虚拟头结点
        vHead->next = head;
        ListNode *cur = vHead;
        while (cur->next != nullptr)
        {
            if (cur->next->val == val)
            {
                ListNode *tmp = cur->next;
                cur->next = cur->next->next; // 已经转移到下一个节点了
                delete tmp;                  // 及时释放空间
            }
            else
            {
                cur = cur->next; // 需要转移到下一个节点
            }
        }
        head = vHead->next;
        delete vHead;
        return head;
    }
};