/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
cclass Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode** pp=&head;
        ListNode* ghead=*pp;//ghead is the group head
        while(1){
            int len=k;
            while(len){
                if(ghead==NULL) return head;
                ghead=ghead->next;
                len--;
            }
            ListNode* curr=*pp,*pnext=NULL;
            while(curr->next!=ghead){
                pnext=curr->next;
                curr->next=pnext->next;
                pnext->next=*pp;
                (*pp)=pnext;
            }
            pp=&(curr->next);
        }
        return head;
    }
};