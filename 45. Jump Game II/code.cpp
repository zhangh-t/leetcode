// O(n)
class Solution {
public:
    int jump(vector<int>& nums) {
        int size = nums.size();
        if(size == 1) return 0;
        else
        {
             int stp = 0;
             int reach = 0;
             int last = 0;
             for(int i = 0; i <= reach && i < size; ++i)
             {
                 if(i > last)
                 {
                     ++stp;
                     last = reach;
                 }
                 reach = max(reach, nums[i] + i);
             }
             return stp;
        }
    }
};

//
class Solution {
public:
    int jump(vector<int>& nums) {
        int size = nums.size();
        if(size == 1) return 0;
        else
        {
           int reach =0;
           int step = 0;
           int last = 0;
           for(int i = 0 ; i <= reach && i < size; ++i)
           {
           	  if()
           	  	
           	  reach = max(reach, nums[i] + i);
           }
        }
    }
};