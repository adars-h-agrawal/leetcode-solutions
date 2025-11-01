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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> deletable(nums.begin(), nums.end());

        // Remove deletable nodes at the beginning
        while (head && deletable.count(head->val)) {
            head = head->next;
        }

        // Traverse and remove deletable nodes
        ListNode* curr = head;
        while (curr && curr->next) {
            if (deletable.count(curr->next->val)) {
                curr->next = curr->next->next;
            } else {
                curr = curr->next;
            }
        }

        return head;
    }
};