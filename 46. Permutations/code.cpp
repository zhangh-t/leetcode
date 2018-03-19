class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        std::sort(nums.begin(), nums.end());
        int size = nums.size();
        if(size <= 1) {res.push_back(nums);}
        else
        {
            backtracking(nums, size, res, 0);
        }
        //cheat
        /*res.push_back(nums);
        while (next_permutation(nums.begin(), nums.end()))
        {
            res.push_back(nums);
        }*/
        return res;
    }
private:
    void backtracking(vector<int>& nums, int size, vector<vector<int>>& res, int depth)
    {
        if (depth == size)
        {
            return;
        }
        auto last = nums.rbegin();
        int val = *last;
        vector<vector<int>> thisSubPermutation;
        if(depth == 0)
        {
            res.push_back(nums);
            vector<int> subPermutation;
            subPermutation.push_back(val);
            thisSubPermutation.push_back(subPermutation);
            mapPermutation[0] = thisSubPermutation;
            nums.erase(--nums.end());
        }
        else
        {
            nums.erase(--nums.end());
            vector<vector<int>>& _subPermutation = mapPermutation[depth - 1];
            bool bFirst = true;
            for(auto iter = _subPermutation.begin(); iter != _subPermutation.end(); ++iter)
            {
                vector<int> bigCopy(nums);
                if(bFirst)
                {
                    bFirst = false;
                    vector<int> copy(*iter);
                    copy.insert(copy.begin(), val);
                    thisSubPermutation.push_back(copy);
                }
                else
                {
                    bigCopy.push_back(val);
                    bigCopy.insert(bigCopy.end(), (*iter).begin(), (*iter).end());
                    thisSubPermutation.push_back(bigCopy);
                    res.push_back(bigCopy);
                    bigCopy = nums;
                }
                for(auto itr = (*iter).begin(); itr != (*iter).end(); /*++itr*/)
                {
                    bigCopy = nums;
                    vector<int> copy;
                    copy.insert(copy.end(), (*iter).begin(), ++itr);
                    copy.insert(copy.end(), val);
                    copy.insert(copy.end(), itr, (*iter).end());
                    thisSubPermutation.push_back(copy);
                    bigCopy.insert(bigCopy.end(), copy.begin(), copy.end());
                    res.push_back(bigCopy);
                }
            }
            mapPermutation[depth] = thisSubPermutation;
        }
        backtracking(nums, size, res, depth+1); 
    }
private:
    map<int, vector<vector<int>>> mapPermutation;
};
