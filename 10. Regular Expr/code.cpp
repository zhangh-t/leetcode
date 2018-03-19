class Solution {
public:
    bool isMatch(string s, string p) {
        return isMatch((char*)s.c_str(), (char*)p.c_str()); 
    }
private:
	  bool isMatch(char* s, char* p)
	  {
	  	 if(*p == 0) return *s == 0; 	//the end of the pattern ought to be the end of the string
	  	 else if(*(p+1) == '*')
	  	 {
	  	 	  return isMatch(s, p+2) || (*s != 0 && (*s == *p || *p == '.') && isMatch(++s, p));
	  	 }
	  	 else 
	  	 {
	  	 	  return (*s != 0) && ((*p == *s) || (*p == '.')) && isMatch(++s, ++p);
	  	 }
	  }
};