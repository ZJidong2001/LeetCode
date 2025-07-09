class Solution
{
public:
    ListNode* swapPairs(ListNode* head)
    {
        ListNode* newhead = new ListNode;
        newhead->next = head;

        ListNode* prev = newhead, * cur = head;
        while (cur && cur->next)
        {
            ListNode* next = cur->next->next;
            prev->next = cur->next;
            cur->next->next = cur;
            cur->next = next;
            prev = cur;
            cur = cur->next;
        }

        head = newhead->next;
        delete newhead;

        return head;
    }
};