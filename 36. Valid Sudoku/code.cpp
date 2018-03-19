class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
    	  int rowval = 0;
    	  int cell = 0;
    	  int p = 0x01;
    	  int colval[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    	  int subrect[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    	  int r, c;
        for(int i = 0 ; i < 9 ; ++i)
        {
            rowval = 0;
        	for(int j = 0 ; j < 9; ++j)
        	{
        		  if(board[i][j] == '.') continue;
        		  else
        		  {
        		  	 cell = board[i][j] - '1';
        		  }
        		  int val = p << cell;
        		  r = i / 3, c = j / 3;
        		  if(rowval & val || colval[j] & val || subrect[r][c] & val)
        		  	return false;
        		  else
        		  {
        		  	  rowval |= val;
        		  	  colval[j] |= val;
        		 	  subrect[r][c] |= val;
        		  }
        	}
        }
        return true;
    }
};