class Solution {
public:
    bool store(vector<vector<char>>& board, int r, int col, char ch) {
        for (int j = 0; j < 9; j++) { //Row check
            if (board[r][j] == ch)
                return false;
        }

        for (int i = 0; i < 9; i++) { // Col check
            if (board[i][col] == ch)
                return false;
        }

        // 3 x 3 = gird/box check
        int S_row = (r / 3) * 3;
        int S_col = (col / 3) * 3;

        for (int i = S_row; i < S_row + 3; i++) {
            for (int j = S_col; j < S_col + 3; j++) {
                if (board[i][j] == ch)
                    return false;
            }
        }

        return true;
    }
    bool ssh(vector<vector<char>>& board, int r, int col) {

        if (r == 9)
            return true;

        int nxt_r = r;
        int nxt_col = col + 1;

        if (nxt_col == 9) {
            nxt_r++;
            nxt_col = 0;
        }

        if (board[r][col] != '.') {
            return ssh(board, nxt_r, nxt_col);
        }

        for (char ch = '1'; ch <= '9'; ch++) {

            if (store(board, r, col, ch)) {

                board[r][col] = ch;

                if (ssh(board, nxt_r, nxt_col))
                    return true;

                board[r][col] = '.';
            }
        }

        return false;
    }

    void solveSudoku(vector<vector<char>>& board) { ssh(board, 0, 0); }
};