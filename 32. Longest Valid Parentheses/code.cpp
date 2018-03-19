class Solution {
public:
    int longestValidParentheses(string s) {
        int ret = 0;
        int length = s.length();
        if(length < 2) {return ret;}
        else
        {
        	 stack<int> leftstack;
        	 int l = 0;
        	 int top = -1;
        	 for(int i = 0 ; i < length; ++i)
        	 {
        	 	  if(s[i] == '(')
        	 	  {
        	 	  	 leftstack.push(i);
        	 	  }
        	 	  else
        	 	  {
        	 	     if(!leftstack.empty())
        	 	     {
        	 	         leftstack.pop();
        	 	         if(leftstack.empty())
        	 	         {
        	 	             ret = max(ret, i - l + 1);
        	 	         }
        	 	         else
        	 	         {
        	 	             ret = max(ret, i - leftstack.top());
        	 	         }
        	 	     }
        	 	     else
        	 	     {
        	 	         l = i + 1;
        	 	     }
        	 	  }
        	 }
        	 return ret;
        }
    }
};