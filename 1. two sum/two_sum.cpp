#include <vector.h>
#include <map.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
	{
		vector<int> vecRet;
		multimap<int, int> indexMap;
		int i = 0;
		//sort
        for(auto iter = nums.begin() ; iter != nums.end(); ++iter)
		{
			indexMap.insert(std::make_pair(*iter, i));
			++i;
		}
		
		for(auto iter = indexMap.begin(); iter != indexMap.end(); ++iter)
			{
				for(auto secondIter = iter; ++secondIter != indexMap.end();)
				{
					if((*iter).first + (*secondIter).first == target)
					{
						vecRet.push_back((*iter).second);
						vecRet.push_back((*secondIter).second);
						return vecRet;
					}
				}
			}
		return vecRet;
    }
};