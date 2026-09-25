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
        
        if (list1 == nullptr || list2 == nullptr) {
            return list1 == nullptr ? list2 : list1;
        }
        else {
            ListNode* tempNode = new ListNode();
            if (list1->val <= list2->val) {
                tempNode->val = list1->val;
                tempNode->next = mergeTwoLists(list1->next, list2);
            }
            else {
                tempNode->val = list2->val;
                tempNode->next = mergeTwoLists(list1, list2->next);
            }
            return tempNode;
        }
    }
};
