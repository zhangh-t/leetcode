// O(2N)
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
       set<int> tmp;
       for(auto iter = nums.begin(); iter != nums.end(); ++iter)
       {
           if(*iter > 0)
           {
              tmp.insert(*iter);
           }
       }
       if(tmp.empty()) {return 1;}
       int res = 0;
       for(auto iter = tmp.begin(); iter != tmp.end(); ++iter)
       {
           if(*iter - res != 1)
           {
               break;
           }
           else
           {
               res = *iter;
           }
       }
       return ++res;
    }
};

//O(n)
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
       
    }
};