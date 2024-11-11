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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* curr1;
        ListNode* curr2;
        if(list1==NULL) return list2;
        else if(list2==NULL) return list1;
        if(list1->val<=list2->val) {
            curr1=list1;
            curr2=list2;
        }
        else{
            curr1=list2;
            curr2=list1;
        }
        ListNode* head=curr1;
        ListNode* prev;
        ListNode* temp;
        while(curr2!=NULL && curr1!=NULL){
            if(curr1->val<=curr2->val){
                prev=curr1;
                curr1=curr1->next;
            }
            else if(curr1->val>curr2->val){
                temp=curr2;
                curr2=curr2->next;
                temp->next=curr1;
                prev->next=temp;
                prev=temp;
            }
        }
        if(curr1==NULL && curr2!=NULL){
            prev->next=curr2;
        }
        return head;
    }
};