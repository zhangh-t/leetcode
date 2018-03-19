class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) 
    {
        sort(nums.begin(), nums.end());
        int nSize = nums.size();
        if(nSize == 0) return 0;
        int nMinDiff = INT_MAX;
        int nRet = nums[0];
        int nSum = 0;
        int nDiff = 0;
        int nAbsDiff = 0;
        bool bFlag = true; //true pos, false neg;
        for(int i = 0 ; i < nSize; ++i)
        {
        	  if(i > 0 && nums[i] == nums[i -1]) continue;
        	  int l = i + 1, r = nSize - 1;
        	  bool bFind = false;
        	  while(l < r)
        	  {
        	  	  nSum = nums[i] + nums[l] + nums[r];
        	  	  nDiff = nSum - target;
        	  	  bFlag = nDiff > 0;
        	  	  nAbsDiff = abs(nDiff);
        	  	  if(nAbsDiff < nMinDiff)
        	  	  {
        	  	  	 nRet = nSum;
        	  	  	 nMinDiff = nAbsDiff;		
        	  	  	 bFind = true; 
        	  	  }
        	  	  else
        	  	 {
        	  	 	 if(bFind) break; 	
        	  	 }
        	  	  bFlag ? --r : ++l;
        	  }	
        }
        return nRet;
    }
};