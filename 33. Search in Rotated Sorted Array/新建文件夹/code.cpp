class Solution {
public:
    int search(vector<int>& nums, int target) {
         int l = 0, r = nums.size() - 1, mid = -1;
         while(l <= r)
         {
             mid = (l + r) / 2;
             if(nums[mid] == target) return mid;
             else
             {
                 if(nums[mid] < nums[r])
                 {
                     if(nums[mid] < target && target <= nums[r]) l = mid + 1;
                     else r = mid - 1;
                 }
                 else
                 {
                     if(target > nums[r] && nums[mid] >= target) r = mid - 1;
                     else l = mid + 1;
                 }
             }
         }
         return -1;
    }
};