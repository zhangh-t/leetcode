struct comp
{
    bool operator()(long long n1, long long n2)
    {
        int high1 = (n1 & 0xffffffff00000000) >> 32;
        int high2 = (n2 & 0xffffffff00000000) >> 32;
        if(high1 < high2)
        {
            return true;
        }
        else if(high1 == high2)
        {
            int low1 = (n1 & 0x00000000ffffffff);
            int low2 = (n2 & 0x00000000ffffffff);
            if(low1 < low2) return true;
            else return false;
        }
        else
        {
            return false;
        }
    }
};

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        if (strs.empty()) return res;
        else if(strs.size() == 1) {res.push_back(vector<string>(1, strs[0])); return res;}
        else
        {
            map<long long, int, comp> hashMap;
            int nCurIndex = 0;
            for(auto iter = strs.begin(); iter != strs.end(); ++iter)
            {
                long long hashVal = hash(*iter);
                auto mapIter = hashMap.find(hashVal);
                if(mapIter == hashMap.end())
                {
                    vector<string> vec;
                    vec.push_back(*iter);
                    hashMap[hashVal] = nCurIndex++;
                    res.push_back(vec);
                }
                else
                {
                    res[mapIter->second].push_back(*iter);
                }
            }
            return res;
        }
    }
private:
    long long hash(const string& str)
    {
        int high = 0, low = 0;
        for(auto iter = str.begin(); iter != str.end(); ++iter)
        {
            int val = (*iter) - 'a' + 1;
            high |= 1 << val;
            low += val;
        }
        return (long long)high << 32 | low;
    }
};