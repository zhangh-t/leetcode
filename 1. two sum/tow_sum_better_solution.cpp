#include <vector.h>
#include <hash_map>
using namespace std;
 
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
	{
		vector<int> vecRet;
		hash_map<int, int> hash;
		int i = 0;
		for(auto iter = nums.being(); iter != nums.end(); ++iter)
		{
			int nOther = target - *iter;
			auto myTarget = hash.find(nOther);
			if(auto t != hash.end())
			{
				vecRet.push_back(i);
				vecRet.push_back(t->second);
				break;
			}
			else
			{
				hash[*iter] = ++i;
			}
		}
		return vecRet;
    }
};