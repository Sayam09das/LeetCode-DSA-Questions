class Solution {
public:
    bool queen_safe(vector<string>& chessboard, int r, int col, int n) {
        // Horizontal check
        for (int j = 0; j < n; j++) {
            if (chessboard[r][j] == 'Q') {
                return false;
            }
        }
        // vertical check
        for (int i = 0; i < n; i++) {
            if (chessboard[i][col] == 'Q') {
                return false;
            }
        }

        //left diagonal check
        for (int i = r, j = col; i >= 0 && j >= 0; i--, j--) {
            if (chessboard[i][j] == 'Q') {
                return false;
            }
        }
        // right diagonal check
        for (int i = r, j = col; i >= 0 && j < n; i--, j++) {
            if (chessboard[i][j] == 'Q') {
                return false;
            }
        }

        return true;
    }
    void n_queen(vector<string>& chessboard, int r, int col, int n,
                 vector<vector<string>>& ans) {
        if (r == n) {
            ans.push_back(chessboard);
            return;
        }

        for (int j = 0; j < n; j++) {
            if (queen_safe(chessboard, r, j, n)) {
                chessboard[r][j] = 'Q';
                n_queen(chessboard, r + 1, 0, n, ans);
                chessboard[r][j] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> chessboard(n, string(n, '.'));
        vector<vector<string>> ans;
        n_queen(chessboard, 0, 0, n, ans);
        return ans;
    }
};