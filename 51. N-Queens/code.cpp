class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        if (n < 1) {
            return res;
        }
        else if (n == 1){
            res.push_back(vector<string>(1, "Q"));
        }
        else
        {
            init(n);
            res.push_back(vector<string>(n));
            solve(0, n, res);
            res.pop_back();
        }
        return res;
    }
private:
    void solve(int row, int n, vector<vector<string>>& res) {
        if (row >= n) {
            res.push_back(res.back());
            return;
        }
        for (int i = 0 ; i < n ; ++i) {
            if (_state[row][i] == 0) { 
                fillRes(row, i, n, res);
                update(row, i, n);
                solve(row + 1, n, res);
                update(row, i, n, true);
            }
        }
    }
private:
    void init(int n) {
        for (int i = 0 ; i < n; ++i) {
            _state.push_back(vector<int>(n, 0));
        }
    }
    void update(int row, int col, int n, bool reset = false) {
        for (int i  = 1; i < n - row; ++i) {
            _state[i + row][col] += reset ? -1 : 1;
            if (col + i < n) {
                _state[i + row][col + i] += reset ? -1 : 1;
            }
            if (col - i >= 0) {
                _state[i + row][col - i] += reset ? -1 : 1;
            }   
        }
    }

    void fillRes(int row, int index, int n, vector<vector<string>>& res) {
        string rowstring(n, '.');
        rowstring[index] = 'Q';
        res.back()[row] = std::move(rowstring);
    }
private:
    vector<vector<int>> _state;
};