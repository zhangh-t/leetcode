#include "stdafx.h"
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    string convert(string s, int numRows) {

        string sRet;
        int nSrcLength = s.length();
        if (numRows == 1 || nSrcLength <= numRows)
        {
            return s;
        }

        for (int i = 0; i < numRows; ++i)
        {
            int nMode = (i == 0 || i == numRows - 1) ? 0 : i;
            sRet += std::move(getLine(numRows, nSrcLength, s, i, 0, nMode));
        }
        return sRet;
    }
protected:
    // nmode == 0 read one time
    // nmode == 1 read two times
    string getLine(int nNumRows, int nLength, string& s, int nRowIndex, int nFlag, int nMode)
    {
        string sRet;
        if (nMode == 0)
        {
            int i = 0;
            int nOffset = nRowIndex;
            while (nOffset < nLength)
            {
                sRet.push_back(s[nOffset]);
                ++i;
                nOffset = nRowIndex + i * (nNumRows - 1) * 2;
            }
        }
        else
        {
            if (nRowIndex < nLength)
            {
                sRet.push_back(s[nRowIndex]);
                int nNext = nFlag == 0 ? nRowIndex + (nNumRows - nMode - 1) * 2
                    : nRowIndex + nMode * 2;
                sRet += std::move(getLine(nNumRows, nLength, s, nNext, nFlag ^ 1, nMode));
            }
        }
        return sRet;
    }
};

void main()
{
    string s = "ABCDE";

    string ssss = Solution().convert(s, 4);

}