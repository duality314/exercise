class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *tmp_next;
        ListNode *cur = head;
        ListNode *pre = nullptr;
        while (cur)
        {
            tmp_next = cur->next; // 临时记录下一个
            cur->next = pre;      // 翻转
            pre = cur;            // 当前的成为前一个
            cur = tmp_next;       // 下一个成为接下来要操作的
        }
        head = pre; // 此时 cur为最后的nullptr ，pre则为列表头
        return head;
    }
};