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
       ListNode* pRet = NULL;
       ListNode* p = l1;
       ListNode* q = l2;
       int nCarry = 0;
       ListNode* pCur = NULL;
       while (p != NULL || q != NULL)
       {
           int nSum = p->val + q->val + nCarry;
           nCarry = nSum / 10;
           int nValue = nSum % 10;
           if(p->next == NULL || q->next == NULL)
           {
               if(p->next == NULL && q->next != NULL)
               {
                   q->next->val += nCarry;
                   q->val = nValue;
                   pCur = q->next;
                   pRet = l2;
                   break;
               }
               
               else if(p->next != NULL && q->next == NULL)
               {
                   p->next->val += nCarry;
                   p->val = nValue;
                   pCur = p->next;
                   pRet = l1;
                   break;
               }
               
               else
               {
                   p->val = nSum;
                   pCur = p;
                   pRet = l1;
                   break;
               }
               
           }
           else
           {
               p->val = nValue;
               q->val = nValue;
               p = p->next;
               q = q->next;
           }
       }
       while(pCur != NULL)
       {
           int nSum = pCur->val;
           int nValue = nSum % 10;
           int nCarry = nSum / 10;
           pCur->val = nValue;
           if(pCur->next != NULL)
           {
               pCur->next->val += nCarry;
           }
           else
           {
               if(nCarry != 0)
               pCur->next = new ListNode(nCarry);
           }
           pCur = pCur->next;
       }
       return pRet;
    }
};