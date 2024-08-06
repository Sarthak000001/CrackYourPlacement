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
    
    // Recursive 
    ListNode* Reverse(ListNode* head){
        // Base case 
        if(head == NULL || head->next == NULL) return head;
        ListNode* newHead = Reverse(head->next);
        ListNode* front = head->next;
        front->next = head;
        head->next = NULL;
        return newHead;
    }
public:
    ListNode* reverseList(ListNode* head) {
        return Reverse(head);
        // ListNode* pre = NULL;
        // ListNode* curr = head;
        // ListNode* forward = NULL;
        // while(curr != NULL){
        //     forward = curr->next;
        //     curr->next = pre;
        //     pre = curr;
        //     curr = forward;
        //  }
        // return pre;
    }
};