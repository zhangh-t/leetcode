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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
	{
       ListNode* pRet = new ListNode(0);
	   int nCarry = 0;
	   while(l1 != NULL || l2 != NULL)
	   {
		   int nX = l1 == NULL ? l1->val : 0;
		   int nY = l2 == NULL ? l2->val : 0;
		   int nSum = nX + nY + nCarry;
		   pRet->val += nSum % 10;
		   pRet->next = new ListNode(nSum % 10);
		   nCarry = nSum / 10;
		   pRet = pRet->next;
		   if(p != NULL) p = p->next;
		   if(q != NULL) q = q->next;
	   }
	   return pRet->next;
    }
};