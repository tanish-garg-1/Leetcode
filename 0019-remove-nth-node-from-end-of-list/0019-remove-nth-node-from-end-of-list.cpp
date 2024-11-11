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
        ListNode* fast=head;
        ListNode* slow;
        int i=1;
        int count=1;
        bool done=false;
        while(i<n) {fast=fast->next;i++;count++;}
        while(fast->next!=NULL){
            count++;
            fast=fast->next;
            if(done== false) {slow=head;done=true;}
            else
            slow=slow->next;
        }
        if(n!=count){
            slow->next=slow->next->next;
        }
        else{
            head=head->next;
        }
        return head;
    }
};