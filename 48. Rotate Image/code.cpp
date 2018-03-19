class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
    	  int size = matrix.size();
    	  if(size <= 1) {return;}
    	  else
    	  {
    	  	 int circleCount = (size + 1)/ 2;
    	  	 int i = 0;
    	  	 while(i < circleCount)
    	  	 {
    	  	 	 int uplimit = size - i - 1;
    	  	 	 for(int k = 0; k < uplimit; k++)
    	  	 	 {
    	  	 	  	 int tmp = matrix[i][k + i];
    	  	 	  	 matrix[i][k + i] = matrix[uplimit - k][i];
    	  	 	  	 matrix[uplimit - k][i] = matrix[uplimit][uplimit - k];
    	  	 	  	 matrix[uplimit][uplimit - k] = matrix[i + k][uplimit - i];
    	  	 	  	 matrix[i + k][uplimit - i] = tmp;
    	  	 	 }
    	  	 	 ++i;
    	  	 }
    	  }     
    }
};