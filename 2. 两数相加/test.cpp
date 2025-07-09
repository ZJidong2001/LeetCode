class Solution
{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode* head = new ListNode;
        ListNode* tail = head;

        ListNode* cur1 = l1, * cur2 = l2;
        int sum = 0;
        while (cur1 || cur2 || sum)
        {
            if (cur1)
            {
                sum += cur1->val;
                cur1 = cur1->next;
            }
            if (cur2)
            {
                sum += cur2->val;
                cur2 = cur2->next;
            }
            tail->next = new ListNode(sum % 10);
            tail = tail->next;
            sum /= 10;
        }

        ListNode* ret = head->next;
        delete head;

        return ret;
    }
};