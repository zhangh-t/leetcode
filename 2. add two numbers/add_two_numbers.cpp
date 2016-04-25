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
    int listCount(ListNode* node)
	{
		int nRet = 0;
		ListNode* pTmp = node;
		while(pTmp != NULL)
		{
			++nRet;
			pTmp = pTmp->next;
		}
		return nRet;
	}
	
	void addZeroToList(ListNode* list, int nCount)
	{
		if(list == NULL)
		{ 
			ListNode* pCur = NULL;
			for(int i = 0; i < nCount; ++i)
			{
				ListNode* pListNode = new ListNode(0);
				if(pCur == NULL)
				{
					pCur = pListNode;
				}
				else
				{
					pCur->next = pListNode;
				}
			}
			list = pCur;
		}
		else
		{
			ListNode* pLast = list;
			while(pLast->next != NULL)
			{
				pLast = pLast->next;
			}
			for(int i = 0 ; i < nCount; ++i)
			{
			    pLast->next = new ListNode(0);
			    pLast = pLast->next;
			}
		}
	}
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
	{
        int nDiff = listCount(l1) - listCount(l2);
		if (nDiff < 0)
		{
			addZeroToList(l1, -nDiff);
		}
		if(nDiff > 0)
		{
			addZeroToList(l2, nDiff);
		}
		int nCarry = 0;
		ListNode* pl1Cur = l1;
		ListNode* pl2Cur = l2;
		ListNode* pRet = NULL;
		ListNode* pCur = NULL;
		while(pl1Cur != NULL)
		{
			int nValue = (pl1Cur->val + pl2Cur->val + nCarry) % 10;
			ListNode* pCurNode = new ListNode(nValue);
			nCarry = (pl1Cur->val + pl2Cur->val + nCarry) / 10;
			if (pRet == NULL)
			{
				pRet = pCurNode;
			}
			else
			{
				pCur->next = pCurNode;
			}
			pCur = pCurNode;
			pl1Cur = pl1Cur->next;
			pl2Cur = pl2Cur->next;
		}
		if(nCarry != 0)
		{
		    pCur->next = new ListNode(nCarry);
		}
		return pRet;
    }
};