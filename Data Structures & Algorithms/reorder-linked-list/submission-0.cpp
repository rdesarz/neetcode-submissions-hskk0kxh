class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;

        // 1) find middle (slow at end of first half)
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // 2) split + reverse second half
        ListNode* second = slow->next;
        slow->next = nullptr;

        ListNode* prev = nullptr;
        while (second) {
            ListNode* nxt = second->next;
            second->next = prev;
            prev = second;
            second = nxt;
        }
        second = prev; // head of reversed second half

        // 3) merge
        ListNode* first = head;
        while (second) {
            ListNode* fnext = first->next;
            ListNode* snext = second->next;

            first->next = second;
            second->next = fnext;

            first = fnext;
            second = snext;
        }
    }
};