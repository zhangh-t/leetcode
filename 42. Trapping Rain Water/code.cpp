class Solution {
public:
    int trap(vector<int>& height) {
        int nCurIndex = -1;
        int res = 0;
        int nLast = -1;
        for(auto iter = height.begin(); iter != height.end(); ++iter)
        {
            ++nCurIndex;
            //skip front zeros
            if(nLast == -1 && *iter == 0) {continue;}
            else
            {
                 if(nLast == -1) {nLast = nCurIndex;}
                 else
                 {
                     if(*iter <= height[nCurIndex - 1]) continue;
                     else
                     {
                         int startPos = nLast;
                         int threshold;
                         if(height[startPos] > *iter)
                         {
                             threshold = *iter;
                         }
                         else
                         {
                             threshold = height[startPos];
                             nLast = nCurIndex;
                         }
                         int reversePos = nCurIndex - 1;
                         for(; reversePos > startPos; --reversePos)
                         {
                             if(height[reversePos] >= threshold) break;
                             res += threshold - height[reversePos];
                             height[reversePos] = threshold;
                         }
                         
                     }
                 }
            }
        }
        return res;
    }
};


//another
class Solution {
public:
    int trap(int A[], int n) {
        int left=0; int right=n-1;
        int res=0;
        int maxleft=0, maxright=0;
        while(left<=right){
            if(A[left]<=A[right]){
                if(A[left]>=maxleft) maxleft=A[left];
                else res+=maxleft-A[left];
                left++;
            }
            else{
                if(A[right]>=maxright) maxright= A[right];
                else res+=maxright-A[right];
                right--;
            }
        }
        return res;
    }
};