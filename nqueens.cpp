class Solution {
    vector<vector<string>> ans;

    void dfs(
        int row,
        int n,
        vector<string>& board,
        unordered_set<int>& cols,
        unordered_set<int>& diag1,
        unordered_set<int>& diag2
    )
    {
        // Base Case
        if(row == n)
        {
            ans.push_back(board);
            return;
        }

        for(int col = 0; col < n; col++)
        {
            // Column already occupied
            if(cols.count(col))
            {
                continue;
            }

            // "\" diagonal occupied
            if(diag1.count(row - col))
            {
                continue;
            }

            // "/" diagonal occupied
            if(diag2.count(row + col))
            {
                continue;
            }

            // Place Queen
            board[row][col] = 'Q';

            cols.insert(col);
            diag1.insert(row - col);
            diag2.insert(row + col);

            // Recurse for next row
            dfs(
                row + 1,
                n,
                board,
                cols,
                diag1,
                diag2
            );

            // Backtrack
            board[row][col] = '.';

            cols.erase(col);
            diag1.erase(row - col);
            diag2.erase(row + col);
        }
    }

public:
    vector<vector<string>> solveNQueens(int n)
    {
        // Edge Case
        if(n == 0)
        {
            return {};
        }

        // Empty chess board
        vector<string> board(
            n,
            string(n, '.')
        );

        unordered_set<int> cols;
        unordered_set<int> diag1;
        unordered_set<int> diag2;

        dfs(
            0,
            n,
            board,
            cols,
            diag1,
            diag2
        );

        return ans;
    }
};