class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ret;
        if(s.empty() || words.empty()) return ret;
        else
        {
            multiset<int> wordshashs;
            int nWordCount = 0;
            for(auto iter = words.begin() ; iter != words.end(); ++iter)
            {
                wordshashs.insert(hash(*iter));
                ++nWordCount;
            }
            int wordlength = words[0].length();
            int i = 0;
            int slength = s.length();
            int j = 0;
            bool bFound;
            multiset<int> setcopy;
            int substringlength = nWordCount * wordlength;
            string substring;
            while (i <= slength - substringlength)
            {
                j = i;
                bFound = true;
                setcopy = wordshashs;
                auto iter = setcopy.begin();
                while( j < i + substringlength)
                {
                    substring = s.substr(j, wordlength);
                    iter = setcopy.find(hash(substring));
                    if(iter == setcopy.end())
                    {
                        ++i;
                        bFound = false;
                        break;
                    }
                    setcopy.erase(iter);
                    j += wordlength;
                }
                if(bFound)
                {
                    ret.push_back(i);
                    ++i;
                }
            }
            return ret;
        }	    
    }
private:
    int hash(string& s)
    {
        int length = s.length();
        int nRet = 0;
        for(int i = 0 ; i < length; ++i)
        {
            int nhash = s[i] - 'a';
            nRet *= 100;
            nRet += nhash;
        }
        return nRet;
    }
};