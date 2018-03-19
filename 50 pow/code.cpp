class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0) return 1.0;
        else if(n > 0)
        {
            int half = n >> 1;
            double dRet = myPow(x, half);
            dRet *= dRet;
            return n % 2 ? dRet * x : dRet;
        }
        else
        {
            if(n==INT_MIN)  
                return 1.0 / (pow(x,INT_MAX)*x);
            else
                return 1.0 / myPow(x, -n);
        }
    }
};


//2. 
class Solution {
public:
    double myPow(double x, int n) {
    if(n==0)  
            return 1.0;  
    if(n<0)
      if(n == INT_MIN)
        return 1.0 / (pow(x , INT_MAX) * x);
      else
        return 1.0 / pow(x,-n);  
    double ans = 1.0 ;  
    for(; n>0; x *= x, n>>=1)  
    {  
        if(n&1>0)  
            ans *= x;  
    }  
    return ans;  
    }
    }
};