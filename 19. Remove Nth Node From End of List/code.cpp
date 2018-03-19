/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
int count = 0;
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL) return NULL;
        //stl
        /*
        list<ListNode*> list;
        while(head != NULL)
        {
        	list.push_back(head);
        	head = head->next;
        }
        int nCurIndex = 1;
        auto lastIter = list.rend();
        --lastIter;
        for (auto riter = list.rbegin(); riter != list.rend(); ++riter)
        {
        	 if(nCurIndex == n)
        	 {
        	 	 if(riter != lastIter)
        	 	 {
        	 	 	(*++riter)->next = (*riter)->next;
        	 	   delete *riter;
        	 	 }
        	 	 else
        	 	 {
        	 	 	  head = head->next;
        	 	 }
 				 return head;
        	 }
        }     
         
        */
        //pointer
        if(head == NULL) return NULL;
        head->next = removeNthFromEnd(head->next, n);
        ++count;
        return count == n ? head->next : head;
    }
};