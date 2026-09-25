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
        vector<ListNode*>nodes;
        ListNode* node = head;
        while (node) {
            nodes.push_back(node);
            node = node->next;
        }
        int totalNodes = nodes.size();

        if (totalNodes == 0 || n > totalNodes) {
            return head;
        }
        if (n == totalNodes) {
            return head->next;
        }

        int remove = totalNodes - n;

        nodes[remove - 1]->next = nullptr;
        if (remove + 1 < totalNodes) {
            nodes[remove - 1]->next = nodes[remove + 1];
        }
        return head;

    }
};
