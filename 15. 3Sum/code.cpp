class Solution {
	typedef vector<int>::iterator vecIter;
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
    	vector<vector<int>> vecRet;
    	if(nums.empty()) {return vecRet;}
        std::sort(nums.begin(), nums.end());
        m_begin = nums.begin();
        m_end = nums.end();
        auto iter = m_begin;
        int nLast = INT_MIN;
        for(; iter != m_end; ++iter)
        {
            if(*iter != nLast)
            {
                if(treeSum(iter, vecRet))
                {
                    nLast = *iter;
                }
            }
        }
        return vecRet;
    }
private:
	  bool treeSum(vecIter& iter, vector<vector<int>>& sum)
	  {
	     bool bRet = false;
	  	 int nTarget = *iter;
	  	 auto vecIterLeft = iter;
	  	 auto vecIterRight = m_end;
	  	 ++vecIterLeft;
	  	 --vecIterRight;
	  	 int nCurrent = INT_MIN;
	  	 while(vecIterLeft < vecIterRight)
	  	 {
	  	 	  vector<int> vec;
	  	 	  int nSum = *vecIterLeft + *vecIterRight;
	  	 	  if(nSum == -nTarget && *vecIterLeft != nCurrent)
	  	 	  {
	  	 	     vec.push_back(*iter);
	  	 	  	 vec.push_back(*vecIterLeft);
	  	 	  	 vec.push_back(*vecIterRight);
	  	 	  	 sum.push_back(vec);
	  	 	  	 nCurrent = *vecIterLeft;
	  	 	  	 ++vecIterLeft; --vecIterRight;
	  	 	  	 bRet = true;
	  	 	  }
	  	 	  else
	  	 	  {
	  	 	  	if(nSum < -nTarget)
	  	 	  	{
	  	 	  	    ++vecIterLeft;
	  	 	  	}
	  	 	  	else
	  	 	  	{
	  	 	  	   --vecIterRight;	
	  	 	  	}
	  	 	  }
	  	 }
	  	 return bRet;
	  }
private:
	  vecIter m_begin;
	  vecIter m_end;
};


//array type
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
    	vector<vector<int>> vecRet;
    	if(nums.empty()) {return vecRet;}
        std::sort(nums.begin(), nums.end());
        int nSize = nums.size();
        for(int i = 0 ; i < nSize; ++i)
        {
         if(i > 0 && nums[i] == nums[i-1]) continue;
         int nTarget = nums[i];
	  	 int l = i + 1, r = nSize - 1;
	  	 int nCur = INT_MIN;
	  	 while(l < r)
	  	 {
	  	 	  int nSum = nums[l] + nums[r];
	  	 	  if(nSum == -nTarget && nums[l] != nCur)
	  	 	  {
	  	 	  	 vecRet.push_back(vector<int>({nums[i], nums[l], nums[r]}));
	  	 	  	 nCur = nums[l];
	  	 	  	 ++l, --r;
	  	 	  }
	  	 	  else
	  	 	  {
	  	 	  	if(nSum < -nTarget)
	  	 	  	{
	  	 	  	    ++l;
	  	 	  	}
	  	 	  	else
	  	 	  	{
	  	 	  	    --r;
	  	 	  	}
	  	 	  }
	  	 }
        }
        return vecRet;
    }
};