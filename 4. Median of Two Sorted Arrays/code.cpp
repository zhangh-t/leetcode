#include <vector>
using namespace std;
#define min(x,y) (x) < (y) ? (x) : (y)

class Solution {
public:
    int findKth(vector<int>& nums1, vector<int>& nums2, int nK)
	{
		int m = nums1.size();
		int n = nums2.size();
		if(m > n)
		{
			return findKth(nums2, nums1, nK);
		}
		
		if(m == 0)
		{
			return nums2[nK - 1];
		}
		
		if(nK > n + m)
		{
			return -1;
		}
		
		if(nK == 1)
		{
			return min(nums1[0], nums2[0]);
		}
		
		int nHalfK = nK / 2;
		nHalfK = min(nHalfK, m);
		int nAnotherHalf = nK - nHalfK;
		if(nums1[nHalfK - 1] < nums2[nAnotherHalf - 1])
		{
			vector<int> newNums1;
			auto iter = nums1.begin();
			for(int i= 0 ; i < nHalfK; ++i)
			{
				++iter;
			}
			
			newNums1.insert(newNums1.end(), iter, nums1.end());
			return findKth(newNums1, nums2, nK - nHalfK);
		}
		
		else if(nums1[nHalfK - 1] > nums2[nAnotherHalf - 1])
		{
			vector<int> newNums2;
			auto iter = nums2.begin();
			for(int i= 0 ; i < nAnotherHalf; ++i)
			{
				++iter;
			}
			
			newNums2.insert(newNums2.end(), iter, nums2.end());
			return findKth(newNums2, nums1, nK - nAnotherHalf);
		}
		
		else
		{
			return nums1[nHalfK - 1];
		}
	}
	
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
	{
		int nTotal = nums1.size() + nums2.size();
		if (nTotal & 0x01)
		{
			//odd
			return findKth(nums1, nums2, nTotal / 2 + 1);
		}
		else
		{
			//even
			return (findKth(nums1, nums2, nTotal / 2) + findKth(nums1, nums2, nTotal / 2 + 1)) * 0.5;
		}
    }
};