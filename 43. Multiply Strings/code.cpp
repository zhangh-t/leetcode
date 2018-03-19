class Solution {
public:
    string multiply(string num1, string num2) {
        removeZero(num1);
        removeZero(num2);
        if(num1.empty() || num2.empty()) return "0";
        else
        {
            string res;
            int lpos, spos;
            bool bref = false;

            if(num1.length() > num2.length())
            {
                lpos = num1.length() - 1;
                spos = num2.length() - 1;
            }
            else
            {
                lpos = num2.length() - 1;
                spos = num1.length() - 1;
                bref = true;
            }
            string& longger = !bref ? num1 : num2;
            string& shorter = !bref ? num2 : num1;
            vector<int> reverseResult(512, 0);
            int nCur = 0;
            for(; lpos >= 0 ; --lpos, ++nCur)
            {
                int offset = 0;
                int tmpPos = spos;
                for(; tmpPos >= 0; --tmpPos, ++offset)
                {
                    int multires = (shorter[tmpPos] - '0') * (longger[lpos] - '0');
                    reverseResult[nCur + offset] +=  multires % 10;
                    reverseResult[nCur + offset + 1] += multires / 10;
                    int flg = 0;
                    while(reverseResult[nCur + offset + flg] >= 10)
                    {
                        int val = reverseResult[nCur + offset + flg];
                        reverseResult[nCur + offset + flg] = val % 10;
                        reverseResult[nCur + offset + ++flg] += val / 10;
                    }
                }
            }
            bool b =false;
            for(int i = 511; i >= 0; --i)
            {
                if(!b && reverseResult[i] == 0) continue;
                else b = true;
                res.push_back(reverseResult[i] + '0');
            }
            return res;
        }
    }
private:
    void removeZero(string& s)
    {
        for(auto iter = s.begin(); iter != s.end(); )
        {
            if(*iter == '0') iter = s.erase(iter);
            else break;
        }
    }
};