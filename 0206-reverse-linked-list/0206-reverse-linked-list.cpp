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
    ListNode* reverseList(ListNode* head) {
        ListNode* curr=head;
        ListNode* nextt;
        ListNode* prev=NULL;
        if(curr==NULL || curr->next==NULL) return curr;

        while(curr->next!=NULL){
            nextt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextt;
        }
        curr->next=prev;
        return curr;
    }
};