class Solution
{
public:
    ListNode* middleNode(ListNode* head)
    {
        ListNode newhead;
        newhead.next = head;

        ListNode* slow = &newhead, * fast = &newhead;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    ListNode* reverseList(ListNode* head)
    {
        ListNode* newhead = nullptr;
        ListNode* cur = head;
        while (cur)
        {
            ListNode* next = cur->next;
            cur->next = newhead;
            newhead = cur;
            cur = next;
        }
        return newhead;
    }

    void reorderList(ListNode* head)
    {
        ListNode* middle = middleNode(head);
        ListNode* head1 = head;
        ListNode* head2 = middle->next;
        middle->next = nullptr;

        head2 = reverseList(head2);

        ListNode newhead;
        ListNode* tail = &newhead;
        ListNode* cur1 = head1, * cur2 = head2;
        while (cur1)
        {
            ListNode* next = cur1->next;
            tail = tail->next = cur1;
            cur1 = next;
            if (cur2)
            {
                ListNode* next = cur2->next;
                tail = tail->next = cur2;
                cur2 = next;
            }
        }
        head = newhead.next;
    }
};