// sudoku.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <stack>
using namespace std;

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

int _tmain(int argc, _TCHAR* argv[])
{
    vector<vector<char>> board;
    char a[9] = {'.', '.', '9', '7', '4', '8', '.', '.', '.'};
    vector<char> row(&a[0], &a[9]);
    board.push_back(row);
    char b[9] = {'7', '.', '.', '.', '.', '.', '.', '.', '.'};
    vector<char> row2(&b[0], &b[9]);
    board.push_back(row2);
    char c[9] = {'.', '2', '.', '1', '.', '9', '.', '.', '.'};
    vector<char> row3(&c[0], &c[9]);
    board.push_back(row3);
    char d[9] = {'.', '.', '7', '.', '.', '.', '2', '4', '.'};
    vector<char> row4(&d[0], &d[9]);
    board.push_back(row4);
    char e[9] = {'.', '6', '4', '.', '1', '.', '5', '9', '.'};
    vector<char> row5(&e[0], &e[9]);
    board.push_back(row5);
    char f[9] = {'.', '9', '8', '.', '.', '.', '3', '.', '.'};
    vector<char> row6(&f[0], &f[9]);
    board.push_back(row6);
    char g[9] = {'.', '.', '.', '8', '.', '3', '.', '2', '.'};
    vector<char> row7(&g[0], &g[9]);
    board.push_back(row7);
    char h[9] = {'.', '.', '.', '.', '.', '.', '.', '.', '6'};
    vector<char> row8(&h[0], &h[9]);
    board.push_back(row8);
    char i[9] = {'.', '.', '.', '2', '7', '5', '9', '.', '.'};
    vector<char> row9(&i[0], &i[9]);
    board.push_back(row9);
    Solution().solveSudoku(board);
	return 0;
}

