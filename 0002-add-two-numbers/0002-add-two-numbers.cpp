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
    ListNode* create_node(){
            ListNode* neww=new ListNode();
            return neww;
        }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        bool start=false;
        int carry=0;
        ListNode* node=new ListNode();
        ListNode* head=new ListNode();
        ListNode* neww=NULL;
        ListNode* nextt=NULL;
        while(l1!=NULL || l2!=NULL){
            int x,y;
            if(l1==NULL && l2!=NULL) {x=0;y=l2->val;}
            if(l1!=NULL && l2==NULL) {x=l1->val;y=0;}
            else if(l1!=NULL && l2!=NULL){x=l1->val;y=l2->val;}
            node->val=(x+y+carry)%10;
            carry=(x+y+carry)/10;
            if(start==false){ start=true; head=node;}
            

            if(carry ==1 || (l1!=NULL && l1->next!=NULL) || (l2!=NULL && l2->next!=NULL)){
            neww=create_node();
            node->next=neww;
            node=node->next;}
            if(l1==NULL && l2==NULL && carry==1) node->val=carry;
            if(l1!=NULL)l1=l1->next;
            if(l2!=NULL)l2=l2->next;
        }
        if(node->val==0) node->val=carry;
        return head;
    }
};