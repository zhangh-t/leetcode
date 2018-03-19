class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        //d&c
        vector<int> res;
        int length = nums.size();
        if(length == 0) return res;
        else
        {
        	  int first = binarySearch(nums, 0 , length - 1);
        	  if(first == -1) return res;
        	  else
        	  {
        	  	 res.push_back(binarySearch(nums, 0, first, 1));
        	  	 res.push_back(binarySearch(nums, first + 1, length - 1, 2));
        	  }
        	  return res;
        }
    }
private:
	  int binarySearch(vector<int>& nums, int l, int r, int target, int mode = 0)
	  {
	  	 int ret = -1;
	  	 int mid = 0;
	  	 while(l < r)
	  	 {
	  	 	   mid = (l + r) / 2;
	  	 	   if(nums[mid] == target)class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        //d&c
        vector<int> res({-1, -1});
        int length = nums.size();
        if(length == 0) return res;
        else
        {
        	  int first = binarySearch(nums, 0 , length - 1, target, 0);
        	  if(first == -1) return res;
        	  else
        	  {
        	  	 res[0] = binarySearch(nums, 0, first, target, 1);
        	  	 res[1] = binarySearch(nums, first, length - 1, target, 2);
        	  }
        	  return res;
        }
    }
private:
	  int binarySearch(vector<int>& nums, int l, int r, int target, int mode)
	  {
	  	 int ret = -1;
	  	 int mid = 0;
	  	 while(l <= r)
	  	 {
	  	 	   mid = (l + r) / 2;
	  	 	   if(nums[mid] == target)
	  	 	   {
	  	 	   	  ret = mid;
	  	 	   	  if(mode == 0) break;
	  	 	   	  else if(mode == 1)
	  	 	   	  {
	  	 	   		//find lowwer bound
	  	 	   		r = mid - 1;
	  	 	   	  }
	  	 	   	  else if(mode == 2)
	  	 	   	  {
	  	 	   		//find upper bound
	  	 	   	    l = mid + 1;
	  	 	   	  }
	  	 	   }
	  	 	   else
	  	 	   {
	  	 	   	 if(nums[mid] > target) r = mid - 1;
	  	 	   	 else l = mid + 1;
	  	 	   }
	  	 }
	  	 return ret;
	  }
};
	  	 	   {
	  	 	   	  ret = mid;
	  	 	   		if(mode == 0) break;
	  	 	   		else if(mode == 1)
	  	 	   		{
	  	 	   			 //find lowwer bound
	  	 	   			 r = mid;
	  	 	   		}
	  	 	   		else if(mode == 2)
	  	 	   		{
	  	 	   			//find upper bound
	  	 	   			l = mid;
	  	 	   		}
	  	 	   }
	  	 	   else
	  	 	   {
	  	 	   	 if(nums[mid] > target) r = mid - 1;
	  	 	   	 else l = mid + 1;
	  	 	   }
	  	 }
	  	 return ret
	  }
};