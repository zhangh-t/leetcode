class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
    	int length = nums.size();
    	if(length == 0) return 0;
        sort(nums.begin(), nums.end());
        int i = 0;
        int j = length - 1;
        int count = 0;
        while(i < length)
        {
        	 if(nums[i] == val)
        	 {
        	 	  while(nums[i] == val && i <= j)
        	 	  {
        	 	  	 if(nums[j] == val)
        	 	  	 {
        	 	  	 	  count += j - i + 1;
        	 	  	 	  break;
        	 	  	 }
        	 	  	 swap(nums[i], nums[j]);
        	 	  	 ++i;
        	 	  	 --j;
        	 	  	 ++count;
        	 	  }
        	 	  break;
        	 }
        	 else
        	 {
        	 	++i;
        	 }
        }
        return length - count;
    }
};