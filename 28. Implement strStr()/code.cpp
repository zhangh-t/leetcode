class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.empty()) return 0;
        else if(haystack.empty()) return -1;
        else
        {
            int ret = -1;
            int haystacklength = haystack.length();
        	int needlelength = needle.length();
        	int i = 0;
        	int hsptr = -1;
        	int ndptr = -1;
        	while(haystacklength - i >= needlelength)
        	{
        	  if(haystack[i] == needle[0])
        	  {
        	  	 hsptr = i;
        	  	 ++hsptr;
        	  	 ndptr = 1;
        	     while(ndptr < needlelength)
        	     {
        	    	  if(haystack[hsptr] != needle[ndptr]) break;
        	       	  ++hsptr;++ndptr;
        	     }		
        	     if(ndptr > needlelength - 1) return i;
        	   }
        	   ++i;
        	}

           return ret;	  
        }
    }
};