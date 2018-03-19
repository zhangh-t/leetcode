class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty()){return res;}
        m_digitMap[0] = "";
        m_digitMap[1] = "";
        m_digitMap[2] = "abc";
        m_digitMap[3] = "def";
        m_digitMap[4] = "ghi";
        m_digitMap[5] = "jkl";
        m_digitMap[6] = "mno";
        m_digitMap[7] = "pqrs";
        m_digitMap[8] = "tuv";
        m_digitMap[9] = "wxyz";
        string str = "";
        dfs(0, digits.length(), digits, str);     
        return res;
    }
private:
	  void dfs(int nCur, int nEnd, string& digits, string& ans)
	  {
	  	 if(nCur == nEnd)
	  	 {
	  	    res.push_back(ans);	
	  	    return;
	  	 }
	  	 string& s = m_digitMap[digits[nCur] - '0'];
	  	 for(int i = 0 ; i < s.length(); ++i)
	  	 {
	  	     string str = ans + s[i];
	  	     dfs(nCur + 1, nEnd, digits, str);
	  	 }
	  }
private:
	  map<int, string> m_digitMap;
      vector<string> res;
};