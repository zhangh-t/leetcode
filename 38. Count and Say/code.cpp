class Solution {
public:
    string countAndSay(int n) {
        if(n == 1)
        {
        	  return string("1");
        }
        else
        {
        	 string strRet;
        	 string strLastRes = std::move(countAndSay(n - 1));
        	 char cur = '';
        	 int nCount = 0;
        	 for(auto iter = strLastRes.begin(); iter != strLastRes.end(); ++iter)
        	 {
        	 	  if(nCount == 0)
        	 	  {
        	 	  	 ++nCount;
        	 	  	 cur = *iter;
        	 	  	 continue;
        	 	  }
        	 	  else
        	 	  {
        	 	  	 if(*iter != cur)
        	 	  	 {
        	 	  	 	  strRet += nCount + '0' + cur;
        	 	  	 	  cur = *iter;
        	 	  	 	  nCount = 1;
        	 	  	 }
        	 	  	 else
        	 	  	 {
        	 	  	 	 ++nCount;
        	 	  	 }
        	 	  }
        	 }
        }
    }
};