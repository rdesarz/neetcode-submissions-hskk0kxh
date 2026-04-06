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
        Node* cpy = nullptr; 
        Node* ori = head;

        // // We need a table to store node already met
        std::unordered_map<Node*, Node*> t;
        while(ori)
        {
            // Handle current node
            if (ori == nullptr)
            {

            }
            else if(t.contains(ori))
            {
                cpy = t[ori];
            }
            else
            {
                cpy = new Node(ori->val);
                t[ori] = cpy;
            }

            if (ori->next == nullptr)
            {

            }
            else if(t.contains(ori->next))
            {
                cpy->next = t[ori->next];
            }
            else
            {
                cpy->next = new Node(ori->next->val);
                t[ori->next] = cpy->next;
            }

            if (ori->random == nullptr)
            {

            }
            else if(t.contains(ori->random))
            {
                cpy->random = t[ori->random];
            }
            else
            {
                cpy->random = new Node(ori->random->val);
                t[ori->random] = cpy->random;
            }

            // Go to next node
            cpy = cpy->next;
            ori = ori->next;
        }

        return t[head];
    }
};
