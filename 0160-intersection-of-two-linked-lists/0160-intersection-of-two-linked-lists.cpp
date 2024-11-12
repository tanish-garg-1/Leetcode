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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* curr1=headA;
        ListNode* curr2=headB;
        int count1=0,count2=0;
        while(curr1!=NULL){curr1=curr1->next;count1++;}
        while(curr2!=NULL){curr2=curr2->next;count2++;}
        if(count1<=count2){
            for(int i=0;i<count2-count1;i++)  headB=headB->next;
        }
        else for(int i=0;i<count1-count2;i++)  headA=headA->next;
         while(headA!=NULL && headA!=headB){
            headB=headB->next;headA=headA->next;
            }
            return headA;
            return NULL;
    }

};