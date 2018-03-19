class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string strCommonPrefix = strs[0];
        auto iter = strs.begin();
        ++iter;
        for(;iter < strs.end(); ++iter)
        {
        	strCommonPrefix = commonPrefix((char*)(iter->c_str()), (void*)(strCommonPrefix.c_str()));
        }
        return strCommonPrefix;
    }
    
private:
	  string commonPrefix(char* s1, char* s2);
	  {
	     string sRet;
	     while(*s1 != 0 && *s2 !=0)
	     {
	     	  if(*s1 == *s2)
	     	  {
	     	  	sRet += *s1;
	     	  	++s1;
	     	  	++s2;
	     	  }
	     	  else
	     	  {
	     	  	break;
	     	  }
	     }
	     return sRet;
	  }
};