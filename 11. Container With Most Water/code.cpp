class Solution {
public:
    int maxArea(vector<int>& height) {
      int nSize = height.size();
      int nMaxArea = INT_MIN;
      int head = 0, tail = nSize - 1;
      while(head < tail)
      {
      	int nArea = min(height[head],height[tail]) * (tail - head);
      	if(nArea > nMaxArea)
      	{
      		nMaxArea = nArea;
      		//move shorter side
      		if(height[head] < height[tail])
      		{
      			int i = head + 1;
      			for(; height[i] < height[head] && i < nSize; ++i);
      			head = i;
      		}
      		else
      		{
      			int i = tail - 1;
      			for(; height[i] < height[tail] && i > 0; --i);
      			tail = i;
      		}
      	}
      	else
      	{
      	    height[head] < height[tail] ? ++head : --tail;
      	}
      } 
      return nMaxArea;
    }
};