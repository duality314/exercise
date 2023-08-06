struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *vHead = new ListNode(0);
        vHead->next = head;
        ListNode *fast = vHead;
        ListNode *slow = vHead;
        // 双指针 ， 快慢指针 ，快指针走n+1 ，之后一起走
        while (n-- && fast != nullptr)
        {
            fast = fast->next;
        }
        fast = fast->next;
        while (fast != nullptr)
        {
            fast = fast->next;
            slow = slow->next;
        }
        ListNode *tmp;
        tmp = slow->next;
        slow->next = slow->next->next delete tmp;
        head = vHead->next;
        delete vHead;
        return head;
    }
};