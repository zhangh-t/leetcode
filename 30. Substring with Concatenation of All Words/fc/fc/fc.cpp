// fc.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
#include <set>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ret;
        if(s.empty() || words.empty()) return ret;
        else
        {
            multiset<int> wordshashs;
            int nWordCount = 0;
            for(auto iter = words.begin() ; iter != words.end(); ++iter)
            {
                wordshashs.insert(hash(*iter));
                ++nWordCount;
            }
            int wordlength = words[0].length();
            int i = 0;
            int slength = s.length();
            int j = 0;
            bool bFound;
            multiset<int> setcopy;
            int substringlength = nWordCount * wordlength;
            while (i <= slength - substringlength)
            {
                j = i;
                bFound = true;
                setcopy = wordshashs;
                auto iter = setcopy.begin();
                while( j < i + substringlength)
                {
                    iter = setcopy.find(hash(s.substr(j, wordlength)));
                    if(iter == setcopy.end())
                    {
                        ++i;
                        bFound = false;
                        break;
                    }
                    setcopy.erase(iter);
                    j += wordlength;
                }
                if(bFound)
                {
                    ret.push_back(i);
                    ++i;
                }
            }
            return ret;
        }	    
    }
private:
    int hash(string& s)
    {
        int length = s.length();
        int nRet = 0;
        for(int i = 0 ; i < length; ++i)
        {
            int nhash = s[i] - 'a';
            nRet *= 100;
            nRet += nhash;
        }
        return nRet;
    }
};

int _tmain(int argc, _TCHAR* argv[])
{
    vector<string> aaba;
    aaba.push_back("fooo");
    aaba.push_back("barr");
    aaba.push_back("wing");
    aaba.push_back("ding");
    aaba.push_back("wing");
    vector<int> aaa = Solution().findSubstring(string("lingmindraboofooowingdingbarrwingmonkeypoundcake"), aaba);
	return 0;
}

