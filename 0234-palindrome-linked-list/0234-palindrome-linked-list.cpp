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
    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return true;
        }
        else if(head->next->next==NULL ){
            return (head->val==head->next->val);
        }
        ListNode* curr=head;
        int count=0;
        while(curr!=NULL){curr=curr->next;count++;}
        int i=0;
        curr=head;
        while(i<count/2){curr=curr->next;i++;}
        ListNode* prev=NULL;
        while(curr!=NULL){
            ListNode* next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        i=0;
        while(i<count/2){
            if(head->val!=prev->val){
                return false;
            }
            head=head->next;
            prev=prev->next;
            i++;
        }
        return true;
    }
};