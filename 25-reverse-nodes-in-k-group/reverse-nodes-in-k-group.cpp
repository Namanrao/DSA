class Solution {
public:
    ListNode* reversell(ListNode* start, ListNode* end) {
        ListNode* prev = NULL;
        ListNode* curr = start;
        ListNode* stop = end->next;

        while (curr != stop) {
            ListNode* forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL || k == 1)
            return head;

        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* beforeStart = dummy;
        ListNode* end = head;

        while (true) {
            // Find the end of the k-group
            for (int i = 1; i < k && end != NULL; i++) {
                end = end->next;
            }
            if (end == NULL) break;

            ListNode* start = beforeStart->next;
            ListNode* nextGroup = end->next;

            // Reverse this k-group
            ListNode* newHead = reversell(start, end);
            beforeStart->next = newHead;
            start->next = nextGroup;

            // Move pointers
            beforeStart = start;
            end = start->next;
        }

        return dummy->next;
    }
};
