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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;

        // dummy node to handle left = 1
        ListNode dummy(0);
        dummy.next = head;

        // move prev to the node before 'left'
        ListNode* prev = &dummy;
        for (int i = 1; i < left; i++) {
            prev = prev->next;
        }

        // first node of the part to reverse
        ListNode* cur = prev->next;

        // reverse by head insertion
        for (int i = 0; i < right - left; i++) {
            ListNode* tmp = cur->next;
            cur->next = tmp->next;
            tmp->next = prev->next;
            prev->next = tmp;
        }
        return dummy.next;
    }
};