class Solution {
public:
    int reverse(int x) {
        int nInteMax = std::numeric_limits<int>().max();
        int nIntMin = std::numeric_limits<int>().lowest();
        if(x > nInteMax  || x < nIntMin)
        {
            return 0;
        }
        long long tmp = x;
    	bool bNeg = tmp < 0;
    	tmp = bNeg ? -tmp : tmp;
        long long nRet = 0;
        while(tmp != 0)
        {
        	nRet *= 10;
        	nRet += tmp % 10;
        	tmp /= 10;
        }
        if(nRet > nInteMax || nRet < nIntMin)
        {
            return 0;
        }
        return bNeg ? (nRet * -1) : nRet;
    }
};