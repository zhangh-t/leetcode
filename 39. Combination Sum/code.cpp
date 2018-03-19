class Solution {
	 typedef std::set<int>::iterator setIter;
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        std::set<int> setCandidates(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> tmp;
        subSum(setCandidates.begin(), setCandidates.end(), target, tmp, res);
        return res;
    }
    
private:
    bool subSum(setIter cur, setIter end, int target, vector<int>& vec, vector<vector<int>>& res)
    {
        if(target == 0) return true;
        if(target < 0) return false;
        else
        {
            for(; cur != end; ++cur)
            {
                vec.push_back(*cur);
                if(subSum(cur, end, target - *cur, vec, res))
                {
                    res.push_back(vec);
                }
                vec.erase(--vec.end());
            }
            return false;
        }
    }
};


//2
class Solution {
	 typedef std::set<int>::iterator setIter;
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        std::set<int> setCandidates(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> tmp;
        subSum(setCandidates.begin(), setCandidates.end(), target, tmp, res, 0);
        return res;
    }
    
private:
    int subSum(setIter cur, setIter end, int target, vector<int>& vec, vector<vector<int>>& res, int depth)
    {
        if(target == 0) return -1;
        if(target < 0) return depth - 1;
        else
        {
            for(; cur != end; ++cur)
            {
                vec.push_back(*cur);
                int ret = subSum(cur, end, target - *cur, vec, res, depth + 1);
                if(ret == -1)
                {
                    res.push_back(vec);
                    vec.erase(--vec.end());
                }
                else
                {
                    vec.erase(--vec.end());
                    if(depth != ret) return ret;
                }
                
            }
            return depth - 1;
        }
    }
};