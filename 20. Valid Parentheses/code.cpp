class Solution {
public:
    bool isValid(string s) {
        if(s.length() % 2) return false;
    	map<char, char> mapPattern;
    	mapPattern['('] = ')';
    	mapPattern['['] = ']';
    	mapPattern['{'] = '}';
        stack<char> bracketStack;
        for(auto iter = s.begin(); iter != s.end(); ++iter)
        {
        	 if(mapPattern.find(*iter) != mapPattern.end())
        	 {
        	 	  bracketStack.push(*iter);
        	 }
        	 else if(!bracketStack.empty())
        	 {
        	 	 char last = bracketStack.top();
        	 	 bracketStack.pop();
        	 	 if(mapPattern[last] != *iter)
        	 	 {
        	 	 	 return false;
        	 	 }
        	 }
        	 else
        	 {
        	     return false;
        	 }
        }
        return bracketStack.empty();
    }
};