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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* newHead = head;
        ListNode* prev = head;
        ListNode* curr = head->next;
        while(curr != NULL){
            swap(prev->val,curr->val);
            prev = curr->next;
            if(curr->next) curr = curr->next;
            curr = curr->next;
        }
        return newHead;
    }
};