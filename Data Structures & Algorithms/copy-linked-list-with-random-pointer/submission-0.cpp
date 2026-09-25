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
        unordered_map<Node*, Node*> hashMap;
        Node* node = head;

        while (node) {
            Node* copy = new Node(node->val);
            hashMap[node] = copy;
            node = node->next;
        }

        node = head;
        while (node) {
            Node* copy = hashMap[node];
            copy->next = hashMap[node->next];
            copy->random = hashMap[node->random];
            node = node->next;
        }
        return hashMap[head];
    }
};
