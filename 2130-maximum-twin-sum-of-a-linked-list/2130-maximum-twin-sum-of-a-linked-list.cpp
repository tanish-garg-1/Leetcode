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
    int pairSum(ListNode* head) {
        ListNode* curr1=head;
        ListNode* curr2=head;
        while(curr2 && curr2->next){
            curr1=curr1->next;
            curr2=curr2->next->next;
        }
        ListNode* nextnode;
        ListNode* prevnode=NULL;;
        while(curr1 != NULL){
            nextnode=curr1->next;
            curr1->next=prevnode;
            prevnode=curr1;
            curr1=nextnode;
        }

        ListNode* head2=prevnode;
        int sol=INT_MIN;
        while(head2){
            sol=max(sol,head->val + head2->val);
            head=head->next;
            head2=head2->next;
        }
        return sol;
    }
};