class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        if(nums.size() < 4) {return res;}
        sort(nums.begin(), nums.end());     
        vector<int> vecDfs;
        KSum(4, nums, res, vecDfs, target, 0, nums.size() - 1);
        return res;
    }

private:
    bool KSum(int k, vector<int>& nums, vector<vector<int>>& ret, vector<int>& vecDfs, int nTarget, int l, int r)
    {
        if(r + 1 - l < k) return false; 	//element count less than k
        int nlValue, nrValue;
        int nk = k - 1;
        int ndfsTarget = -1;
        int nref = nums[l++];
        int nSum;
        ndfsTarget = nTarget - nref;
        int nl = l, nr = r;
        do
        {
            while(l < r)
            {
                nlValue = nums[l];
                nrValue = nums[r];
                if(nk * nlValue > ndfsTarget) break;  
                else if(nk * nrValue < ndfsTarget) break;
                else 
                {
                    if(nk == 2)
                    {
                        nSum = nlValue + nrValue;
                        if(nSum == ndfsTarget)
                        {
                            vecDfs.push_back(nlValue);
                            vecDfs.push_back(nrValue);
                            vecDfs.push_back(nref);
                            return true;
                        }
                        else
                        {
                            nSum < ndfsTarget ? ++l : --r;
                        }
                    }
                    else
                    {
                        while (KSum(nk, nums, ret, vecDfs, ndfsTarget, l, r))
                        {
                            if(!vecDfs.empty()) {vecDfs.push_back(nref); ++l, --r;}
                            if(vecDfs.size() == k) {ret.push_back(vecDfs); vecDfs.clear();}
                            if(nk * nlValue < ndfsTarget) ++l;  
                            else if(nk * nrValue > ndfsTarget) --r;
                        }
                        ++l;
                    }
                } 
            }
            if (nk != 2)
            {
                nref = nums[nl];
                while(nref == nums[nl - 1])
                {
                    nref = nums[++nl];
                }
                ++nl;
                l = nl;
                r = nr;
                ndfsTarget = nTarget - nref;
            }
        }while(nl < nr && nk != 2);
        return true;
    }
};