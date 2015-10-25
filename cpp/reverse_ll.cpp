/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == 0)
            return 0;
            
        ListNode* tmp;
        ListNode* prev =0;
        while(head != 0){
            tmp = head->next;
            head->next = prev;
            prev = head;
            head = tmp;
        }
        
        
        return prev;
        
    }
};
