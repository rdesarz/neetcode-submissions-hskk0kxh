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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Reverse linked list
        ListNode* prev = nullptr;
        auto* curr = head;
        while(curr)
        {
            auto* next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }

        // Save the reversed head;
        head=prev;

        // Search and remove element
        curr=prev;
        prev=nullptr;
        for(int i=0;i<n-1;++i)
        {
            prev=curr;
            curr=curr->next;
        }

        // Remove node
        if(prev==nullptr) head=curr->next;
        else prev->next=curr->next;

        // Reverse
        // Reverse linked list
        prev = nullptr;
        curr = head;
        while(curr)
        {
            auto* next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }

        return prev;
    }
};
