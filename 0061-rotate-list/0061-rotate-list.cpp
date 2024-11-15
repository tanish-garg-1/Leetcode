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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL) return head;
        ListNode* fast=head;
        int sizee=0;
        while(fast!=NULL && fast->next!=NULL){
            fast=fast->next->next;
            sizee=sizee+2;
        }
        if(fast!=NULL) sizee++;
        cout<<sizee;

        int rotate=k%sizee;
        if(rotate==0) return head;

        int i=0;
        ListNode* curr =head;
        while(i<sizee-rotate-1){i++;curr=curr->next;}
        ListNode* new_head =curr->next;
        curr->next=NULL;

        ListNode* temp=new_head;
        while(temp->next!=NULL) temp=temp->next;
        temp->next=head;

        return new_head;

    }
};