struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *cur1 = list1;
        ListNode *cur2 = list2;
        ListNode *cur;
        ListNode *head;
        if (!cur1)
        {
            if (cur2)
                return cur2;
            else
            {
                return cur1;
            }
        }
        else
        {
            if (!cur2)
            {
                return cur1;
            }
        }
        if (cur1->val > cur2->val)
        {
            cur = cur2;
            cur2 = cur2->next;
        }
        else
        {
            cur = cur1;
            cur1 = cur1->next;
        }
        head = cur;
        while (cur1 != nullptr || cur2 != nullptr)
        {

            if (cur1 == nullptr)
            {
                while (cur2)
                {
                    cur->next = cur2;
                    cur2 = cur2->next;
                    cur = cur->next;
                }
                break;
            }
            if (cur2 == nullptr)
            {
                while (cur1)
                {
                    cur->next = cur1;
                    cur1 = cur1->next;
                    cur = cur->next;
                }
                break;
            }
            // cout<<cur->val<<endl;
            // cout<<cur1->val<<endl;
            // cout<<cur2->val<<endl;
            // cout<<"--------"<<endl;

            if (cur1->val > cur2->val)
            {
                cur->next = cur2;
                cur2 = cur2->next;
                cur = cur->next;
            }
            else
            {
                cur->next = cur1;
                cur1 = cur1->next;
                cur = cur->next;
            }
        }
        return head;
    }
};