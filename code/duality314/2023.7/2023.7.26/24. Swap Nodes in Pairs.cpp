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
    ListNode *swapPairs(ListNode *head)
    {
        ListNode *vHead = new ListNode(0);
        vHead->next = head;
        ListNode *cur = vHead;
        while (cur->next != nullptr && cur->next->next != nullptr)
        {
            ListNode *tmp_1next = cur->next;   // 1
            cur->next = cur->next->next;       // 0 - > 2
            tmp_1next->next = cur->next->next; // 1 - > 3
            cur->next->next = tmp_1next;       // 2 - > 1
            cur = cur->next->next;
        }
        // cout<<vHead->next->val<<endl;
        head = vHead->next;
        delete vHead;
        return head;
    }
};