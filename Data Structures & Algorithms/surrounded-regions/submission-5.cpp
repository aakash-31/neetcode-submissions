#include <vector>

class Solution {
public:
    void solve(std::vector<std::vector<char>>& board) {
        if (board.empty() || board[0].empty()) return;

        int m = board.size();
        int n = board[0].size();

        // 1. Run DFS for border 'O' cells (Left & Right boundaries)
        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O') dfs(board, i, 0);
            if (board[i][n - 1] == 'O') dfs(board, i, n - 1);
        }

        // 2. Run DFS for border 'O' cells (Top & Bottom boundaries)
        for (int j = 0; j < n; j++) {
            if (board[0][j] == 'O') dfs(board, 0, j);
            if (board[m - 1][j] == 'O') dfs(board, m - 1, j);
        }

        // 3. Post-process the board
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X'; // Capture surrounded regions
                } else if (board[i][j] == 't') {
                    board[i][j] = 'O'; // Restore border-connected regions
                }
            }
        }
    }

private:
    void dfs(std::vector<std::vector<char>>& board, int r, int c) {
        int m = board.size();
        int n = board[0].size();

        if (r < 0 || r >= m || c < 0 || c >= n || board[r][c] != 'O') {
            return;
        }

        board[r][c] = 't'; // Mark as temporary visited state

        dfs(board, r + 1, c);
        dfs(board, r - 1, c);
        dfs(board, r, c + 1);
        dfs(board, r, c - 1);
    }
};