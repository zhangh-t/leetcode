class Solution {
public:
    int divide(int dividend, int divisor) {
        bool neg1 = dividend < 0;
        bool neg2 = divisor < 0;
        long long pos1 = neg1 ? -(long long)dividend : dividend;
        long long pos2 = neg2 ? -(long long)divisor : divisor;
        if(pos2 > pos1) return 0;
        int ret = 0;
        if(pos2 == 0) {return INT_MAX;}
        else if(pos2 == 1)
        {
            long long res = pos1 * (neg1 ^ neg2 ? -1 : 1);
            if(res > INT_MAX || res < INT_MIN) return INT_MAX;
            else ret = res;
        }
        else
        {
            while(pos1 >= pos2)
            {
                long long tmp = pos2;
                int muti = 1;
                while(pos1 >= (tmp <<= 1))
                {
                    muti <<= 1;
                }
                if(muti != 1) tmp >>= 1;
                pos1 -= tmp;
                ret += muti;
            }
            ret *= (neg1 ^ neg2 ? -1 : 1);
        }
        return ret;
    }
};