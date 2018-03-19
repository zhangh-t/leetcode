class Solution {
public:
    int myAtoi(string str) {
        str = std::move(removeSpace(str));
        int nLength = str.length();
        if (nLength == 0)
        {
            return 0;
        }
        else
        {
            char cSign = str[0];
            bool bNeg = cSign == '-';
            bool bHasSign = (cSign == '+' || cSign == '-');
            int i = bHasSign ? 1 : 0;
            int nJudgeFlag = bHasSign ? 11 : 10;
            int nRet = 0;
            int nCurVal = 0;
            do
            {
                if (str[i] >= '0' && str[i] <= '9')
                {
                    nCurVal = str[i] - '0';
                    if (i >= nJudgeFlag - 1)
                    {
                        long long tmp = (long long)nRet * 10 + nCurVal;
                        if (bNeg ? (-tmp < (long long)INT_MIN) : (tmp >(long long)INT_MAX))
                        {
                            return bNeg ? INT_MIN : INT_MAX;
                        }
                    }
                    nRet *= 10;
                    nRet += nCurVal;
                    ++i;
                }
                else
                {
                    break;
                }
            } while (i < nLength);
            return nRet * (bNeg ? -1 : 1);
        }
    }
protected:
    string removeSpace(string& input)
    {
        string strRet;
        int nLegnth = input.length();
        bool bBegin = false;
        for (int i = 0; i < nLegnth; ++i)
        {
            char c = input[i];
            if (c != ' ')
            {
                bBegin = true;
                strRet += c;
            }
            else if (bBegin)
            {
                break;
            }
        }
        return strRet;
    }
};