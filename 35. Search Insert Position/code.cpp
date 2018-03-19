class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        int mid = -1;
        int ret = -1;
        while(l <= r)
        {
        	 mid = (l + r)/ 2;
        	 if(nums[mid] == target) {ret == mid; break;}
        	 else
        	 {
        	 	 if(nums[mid] < target) l = mid + 1;
        	 	 else if(nums[mid] > target) r = mid - 1;
        	 }
        }
        if(ret == -1)
        {
        	if(nums[mid] < target) {ret = mid + 1;}
        	else{ret = mid;}
        }
        return ret;
    }
};