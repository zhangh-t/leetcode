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
    	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        ListNode* pRet = NULL;
        ListNode* pCur = NULL;
        ListNode* pSmaller = NULL;
        while(l1 != NULL && l2 != NULL)
        {
        	  pSmaller = l1->val < l2->val ? l1 : l2;
        	  if(pRet == NULL)
        	  {
        	  	 pRet = pSmaller;
        	  	 pCur = pRet;
        	  }
        	  else
        	  {
        	  	 pCur->next = pSmaller;
        	  	 pCur = pCur->next;
        	  }
        	  l1->val < l2->val ? l1 = l1->next: l2 = l2->next;
        }
        ListNode* pRest = l1 == NULL ? l2 : l1;
        while(pRest != NULL)
        {
        	 pCur->next = pRest;
        	 pRest = pRest->next;
        	 pCur = pCur->next;
        }
        return pRet;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
     	 //D&C
     	 ListNode** pListNodeArray = new ListNode*[nSize];
     	 for(int i = 0 ; i < nSize; ++i)
     	 {
     	 	   pListNodeArray[i] = lists[i];
     	 }
     	 return mergeKLists(pListNodeArray, nSize);
    }
    
    ListNode* mergeKLists(ListNode** pBegin, int k)
    {
        if(k == 0) return NULL;
        else if(k == 1) return *pBegin;
        else if(k == 2) {return mergeTwoLists(*pBegin,*(pBegin + 1));}
        else 
        {
            int nMid = k * 0.5;
            return mergeTwoLists(mergeKLists(pBegin, nMid), mergeKLists(pBegin + nMid, k - nMid));
        }
    }
};