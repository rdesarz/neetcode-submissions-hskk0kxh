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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == nullptr && list2 == nullptr) return nullptr;

        auto* p1=list1;
        auto* p2=list2;
        
        ListNode* out = new ListNode();
        auto* root = out;
        while(p1!=nullptr || p2!=nullptr)
        {
            if(p1==nullptr)
            {
                out->val = p2->val;
                p2 = p2->next;
            }
            else if (p2==nullptr)
            {
                out->val = p1->val;
                p1 = p1->next;
            }
            else if (p1->val <= p2->val)
            {
                out->val = p1->val;
                p1 = p1->next;
            }
            else
            {
                out->val = p2->val;
                p2 = p2->next;
            }

            if(p1!=nullptr || p2!=nullptr)
            {
                out->next = new ListNode();
                out = out->next;
            }
        }

        return root;
    }
};
