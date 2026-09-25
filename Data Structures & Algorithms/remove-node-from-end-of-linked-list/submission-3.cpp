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
        int totalNodes = 0;
        ListNode* node = head;
        while (node) {
            node = node->next;
            totalNodes++;
        }

        int removeNode = totalNodes - n;

        if (totalNodes == 0 || removeNode == 0 || totalNodes == 1) {
            return head->next;
        }


        ListNode* prev = head;
        while (removeNode > 1) {
            prev = prev->next;
            removeNode--;
        }

        ListNode* curr = prev->next;
        prev->next = curr->next;

        return head;

    }
};
