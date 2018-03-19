class Solution {
public:
    int totalNQueens(int n) {
        if (n == 0) {
            return 0;
        }
        else if(n == 1) {
            return 1;
        }
        else {
            init(n);
            return solutionCount(n);
        }
    }
private:
    int solutionCount(int n) {
        int nRes = 0;
        count(0, nRes, n);
        return nRes;
    }
    
    void count(int row, int& res, int n) {
        if (row >= n) {
            ++res;
            return;
        }
        else {
            for (int i = 0 ; i < n; ++i) {
                if (_state[row][i] == 0) {
                    update(row, i, n);
                    count(row + 1, res, n);
                    update(row, i, n, true);
                }
            }
        }
    }
    
    void init(int n) {
        for (int i = 0 ; i < n; ++i) {
            _state.push_back(vector<int>(n, 0));
        }
    }
    
    void update(int row, int col, int n, bool reset = false) {
        for (int i = 1 ; i < n - row; ++i) {
            _state[row + i][col] += reset ? -1 : 1;
            int rightcol = col + i;
            int leftcol = col - i;
            if (rightcol < n)
                _state[row + i][rightcol] += reset ? -1 : 1;
            if (leftcol >= 0)
                _state[row + i][leftcol] += reset ? -1 : 1;
        }
    }
private:
    vector<vector<int>> _state;
};