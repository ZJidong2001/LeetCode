class Solution
{
public:
    ListNode* mergeLists(vector<ListNode*>& lists, int begin, int end)
    {
        if (begin > end) return nullptr;
        if (begin == end) return lists[begin];

        int mid = (begin + end) >> 1;
        ListNode* l1 = mergeLists(lists, begin, mid);
        ListNode* l2 = mergeLists(lists, mid + 1, end);

        ListNode head;
        ListNode* cur1 = l1, * cur2 = l2, * tail = &head;
        while (cur1 && cur2)
        {
            if (cur1->val <= cur2->val)
            {
                tail = tail->next = cur1;
                cur1 = cur1->next;
            }
            else
            {
                tail = tail->next = cur2;
                cur2 = cur2->next;
            }
        }
        if (cur1) tail->next = cur1;
        if (cur2) tail->next = cur2;

        return head.next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        return mergeLists(lists, 0, lists.size() - 1);
    }
};