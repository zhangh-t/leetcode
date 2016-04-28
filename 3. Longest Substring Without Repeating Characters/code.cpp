#include <string>
#include <map>

using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) 
	{
        const char* content = s.c_str();
		int nRet = -1;
		int nCurLength = 0;
		vector<int> vecFlag;
		if(content != NULL)
		{
			while(*content != 0)
			{
			    auto iter = std::find(vecFlag.begin(), vecFlag.end(), *content) ;
				if(iter == vecFlag.end())
				{
					++nCurLength;
				}
				else
				{
				    vector<int> newVec ;
				    newVec.insert(newVec.end(), ++iter, vecFlag.end());
				    vecFlag.swap(newVec);
                    if(nCurLength > nRet)
                    {
                        nRet = nCurLength;
                    }
				}
				vecFlag.push_back(*content);
				nCurLength = vecFlag.size();
				++content;
			}
			if(nCurLength > nRet)
			{
				nRet = nCurLength;
			}
		}
		return nRet;
    }
};