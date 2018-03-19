struct sudokuBoardStatue
{
    short rowStatues[9];
    short colStatues[9];
    short subRectStatues[3][3] ;
    stack<int> rowBlanks[9];
    sudokuBoardStatue()
    {
        memset(rowStatues, 0, 9 * sizeof(short));
        memset(colStatues, 0, 9 * sizeof(short));
        for(int i = 0 ; i < 3; ++i)
        {
            memset(subRectStatues[i], 0, 3 * sizeof(short));
        }
    }

    int firstUnsolvedRow(){
        for(int i = 0 ; i < 9 ; ++i)
        {
            if(rowStatues[i] != 0x01ff)
            {
                return i;
            }
        }	
        return -1;
    }

};

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        initStatue(board);
        solve(board, statue);
    }

private:
    //init the board statues
    void initStatue(vector<vector<char>>& board)
    {
        int r = 0, c = 0, cell = 0;
        int p = 0x01;
        for(int i = 0 ; i < 9 ; ++i)
        {
            for(int j = 0 ; j < 9; ++j)
            {
                r = i / 3, c = j / 3;
                if(board[i][j] == '.')
                {
                    statue.rowBlanks[i].push(j);
                    continue;
                }
                else
                {
                    cell = board[i][j] - '1';
                }
                int val = p << cell;
                statue.rowStatues[i] |= val;
                statue.colStatues[j] |= val;
                statue.subRectStatues[r][c] |= val;
            }
        }
    }

    //backtracking
    bool solve(vector<vector<char>>& board, sudokuBoardStatue& statue)
    {
        int firstRow = statue.firstUnsolvedRow();
        if(firstRow == -1) return true;
        else
        {
            short rowStatue = statue.rowStatues[firstRow];
            // values can be set;
            short valueLeft = rowStatue & 0x01ff;
            // get first blank value;
            int val = 1;
            while(valueLeft != 0x01ff && !statue.rowBlanks[firstRow].empty())
            {
                short one = 0x01;
                val = 1;
                while((valueLeft & one) != 0)
                {
                    one <<= 1;
                    ++val;
                }  	 
                valueLeft |= one;	    	  	  	 
                int blank = statue.rowBlanks[firstRow].top();
                statue.rowBlanks[firstRow].pop();
                // validate
                if(statue.colStatues[blank] & one || statue.subRectStatues[firstRow / 3][blank / 3] & one)
                {
                    statue.rowBlanks[firstRow].push(blank);
                    continue;
                }
                else
                {
                    board[firstRow][blank] = val + '0';
                    statue.colStatues[blank] |= one;
                    statue.subRectStatues[firstRow / 3][blank / 3] |= one;
                    statue.rowStatues[firstRow] |= one;
                    if(!solve(board, statue))
                    {
                        board[firstRow][blank] = '.';
                        statue.rowBlanks[firstRow].push(blank);
                        statue.colStatues[blank] &= ~one;
                        statue.subRectStatues[firstRow / 3][blank / 3] &= ~one;
                        statue.rowStatues[firstRow] &= ~one;
                    }
                }
            }
            // unsolveable
            if(!statue.rowBlanks[firstRow].empty()) return false;
            else
            {
                //next row
                return solve(board, statue);
            }
        }
    }   
private:
    sudokuBoardStatue statue;

};