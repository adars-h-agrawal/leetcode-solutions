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
    ListNode* removeElements(ListNode* head, int val) {
        if (!head) return nullptr;
        ListNode* tmp;
        while (head && val == head->val) head = head->next;
        tmp = head;

        while (tmp && tmp->next) {
            while (tmp->next && tmp->next->val == val) {
                tmp->next = tmp->next->next;
            }
            tmp = tmp->next;
        }
        return head;
    }
};