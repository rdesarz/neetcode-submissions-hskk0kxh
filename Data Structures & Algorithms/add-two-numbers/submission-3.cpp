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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        auto* out=&dummy;
        auto* p1 = l1;
        auto* p2 = l2;
        int remainder = 0;
        while(p1 && p2)
        {
            int sum=p1->val + p2->val + remainder;
            remainder = sum / 10;
            sum = sum % 10;
            out->next = new ListNode(sum);

            p1 = p1->next;
            p2 = p2->next;
            out = out->next;
        }

        while(remainder && (p1 || p2))
        {
            if(p1)
            {
                int sum=p1->val + remainder;
                remainder = sum / 10;
                sum = sum % 10;
                p1->val = sum;
                p1=p1->next;
                out->next = new ListNode(sum);
                out = out->next;
            }
            else if (p2)
            {
                int sum=p2->val + remainder;
                remainder = sum / 10;
                sum = sum % 10;
                out->next = new ListNode(sum);
                
                p2=p2->next;
                out=out->next;
            }
        }

        if(remainder)
        {
            out->next=new ListNode(1);
            out = out->next;
        }

        if(p1)
        {
            out->next = p1;
        }
        else if(p2)
        {
            out->next = p2;
        }

        return dummy.next;
    }
};
