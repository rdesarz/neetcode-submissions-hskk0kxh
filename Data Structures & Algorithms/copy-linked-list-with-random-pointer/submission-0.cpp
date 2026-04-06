/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node dummy(0);
        Node* cpy = &dummy; 
        Node* ori = head;

        // // We need a table to store node already met
        std::unordered_map<Node*, Node*> t;

        while(ori)
        {
            auto* next = cpy->next;
            // Handle current node
            if (ori == nullptr)
            {

            }
            else if(t.contains(ori))
            {
                next = t[ori];
            }
            else
            {
                next = new Node(ori->val);
                t[ori] = next;
            }

            if (ori->next == nullptr)
            {

            }
            else if(t.contains(ori->next))
            {
                next->next = t[ori->next];
            }
            else
            {
                next->next = new Node(ori->next->val);
                t[ori->next] = next->next;
            }

            if (ori->random == nullptr)
            {

            }
            else if(t.contains(ori->random))
            {
                next->random = t[ori->random];
            }
            else
            {
                next->random = new Node(ori->random->val);
                t[ori->random] = next->random;
            }

            // Go to next node
            cpy = next;
            ori = ori->next;
        }

        return t[head];
    }
};
