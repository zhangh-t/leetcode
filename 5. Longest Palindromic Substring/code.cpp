#include "stdafx.h"
#include <string>
using namespace std;
bool isPalindrome(const char* s, int nBase, int nRange)
{
    return s[nBase - nRange] == s[nBase + nRange];
}

template<typename T>
T min(T v1, T v2)
{
    return v1 < v2 ? v1 : v2;
}

class Solution
{
public:
    string longestPalindrome(string s)
    {
        int nLength = s.length();
        if (nLength == 0)
        {
            return "";
        }
        if (nLength == 1)
        {
            return s;
        }
        if (nLength == 2)
        {
            if (s[0] == s[1])
            {
                return s;
            }
            else
            {
                return "";
            }
        }
        else
        {
            string sRet;
            int nMax = 0;
            for (int i = 0; i < nLength; ++i)
            {
                int nRightBegin = nLength;
                string sTmp = findLongestSubString(s, i, nRightBegin);
                int nRange = min(i, nLength - nRightBegin - 1);
                sTmp = findSubPalindrome(sTmp, s, i, nRightBegin, nRange);
                if (sTmp.length() > nMax)
                {
                    sRet = sTmp;
                    nMax = sTmp.length();
                }
            }
            return sRet;
        }
    }
    // from nBase to End find the longest repeat sub string
    string findLongestSubString(string sSrc, int nBase, int& nEnd)
    {
        char cBase = sSrc[nBase];
        string sRet;
        sRet.push_back(cBase);
        int i = nBase;
        for (; i < nEnd; ++i)
        {
            if (sSrc[i + 1] != cBase)
            {
                break;
            }
            else
            {
                sRet.push_back(cBase);
            }
        }
        nEnd = i;
        return sRet;
    }
    string findSubPalindrome(string& sPatten, string sSrc, int nLeftBegin, int nRightBegin, int nRange)
    {
        for (int i = 1; i <= nRange; ++i)
        {
            if (sSrc[nLeftBegin - i] == sSrc[nRightBegin + i])
            {
                sPatten.insert(sPatten.begin(), sSrc[nLeftBegin - i]);
                sPatten.push_back(sSrc[nRightBegin + i]);
            }
            else{
                break;
            }
        }
        return sPatten;
    }
};