class Solution {
public:
    bool isPalindrome(int x) {
    	  if(x < 0) return false;
        int nPalindrome = 0;
        int nXCopy = x;
        while(x > 0)
        {
        	 nPalindrome *= 10;
        	 nPalindrome += x % 10;
        	 x /= 10;
        }
        return nXCopy - nPalindrome == 0;
    }
};