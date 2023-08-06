/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *cura = headA;
        ListNode *curb = headB;
        int lena, lenb;
        lena = lenb = 0;
        while (cura)
        {
            lena++;
            cura = cura->next;
        }
        while (curb)
        {
            lenb++;
            curb = curb->next;
        }
        cura = headA;
        curb = headB;
        if (lena < lenb)
        {
            swap(lena, lenb);
            swap(cura, curb);
        }
        for (int i = 0; i < lena - lenb; i++)
        {
            cura = cura->next;
        }
        while (cura)
        {
            if (cura == curb)
            {
                return cura;
            }
            else
            {
                cura = cura->next;
                curb = curb->next;
            }
        }
        return 0;
    }
};