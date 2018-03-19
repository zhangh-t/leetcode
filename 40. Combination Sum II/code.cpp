//心情不好
class Solution {
	 typedef std::vector<int>::iterator vecIter;
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        std::sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> tmp;
        set<int> used;
        for(auto iter = candidates.begin(); iter != candidates.end(); ++iter)
        {
            if(used.find(*iter) != used.end()) continue;
            else {used.insert(*iter);}
            vector<int> tmp;
            tmp.push_back(*iter);
            if(subSum(iter, candidates.end(), target - *iter, tmp, res)) res.push_back(tmp);
            
        }
        return res;
    }
    
private:
    bool subSum(vecIter cur, vecIter end, int target, vector<int>& vec, vector<vector<int>>& res)
    {
        if(target == 0) return true;
        if(target < 0) return false;
        else
        {
        	auto loopIter = cur;
        	++loopIter;
        	set<int> used;
            for(; loopIter != end; ++loopIter)
            {
                if(used.find(*loopIter) != used.end()) continue;
                else {used.insert(*loopIter);}
                vec.push_back(*loopIter);
                if(subSum(loopIter, end, target - *loopIter, vec, res))
                {
                    res.push_back(vec);
                }
                vec.erase(--vec.end());
            }
            return false;
        }
    }
};
