/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    void reorderList(ListNode* head) {
        auto* slow=head;
        auto* fast=head;
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Cut the list in two
        auto* half = slow->next;
        slow->next = nullptr;

        // reverse from half
        ListNode* prev=nullptr;
        ListNode* curr=half;
        while(curr)
        {
            auto* next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }

        auto start=head;
        auto end=prev;
        while(end)
        {
            auto* start_next = start->next;
            start->next = end;
            
            auto* end_next = end->next;
            end->next = start_next;
            
            start = start_next;
            end=end_next;
        }
    }
};
