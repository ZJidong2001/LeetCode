class Solution
{
public:
    ListNode* reverseKGroup(ListNode* head, int k)
    {
        ListNode* node = head;
        int cnt = 0;
        while (node)
        {
            ++cnt;
            node = node->next;
        }

        ListNode newhead;
        ListNode* prev = &newhead, * cur = head;
        for (int i = 0; i < cnt / k; ++i)
        {
            ListNode* tmp = cur;
            for (int j = 0; j < k; ++j)
            {
                ListNode* next = cur->next;
                cur->next = prev->next;
                prev->next = cur;
                cur = next;
            }
            prev = tmp;
        }
        prev->next = cur;

        return newhead.next;
    }
};