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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL ) return NULL;
        else if(head->next == NULL) return head;
        else
        {
        	 ListNode* pCur = head;
        	 ListNode* pTmp = NULL;
        	 ListNode* pPrev = NULL;
        	 head = head->next;
        	 while(pCur != NULL)
        	 {
        	 	 ListNode* pNext = pCur->next;
        	 	 if(pNext == NULL) break;
        	 	 if(pPrev != NULL) pPrev->next = pNext;
        	 	 pTmp = pNext->next;
        	 	 pCur->next = pTmp;
        	 	 pNext->next = pCur;
        	 	 pPrev = pCur;
        	 	 pCur = pTmp;
        	 	 
        	 }
        	 return head;
        }
    }
};