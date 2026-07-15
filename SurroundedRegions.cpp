class Solution {
public:
    void solve(vector<vector<char>>& board) 
    {
         if(board.empty())
        {
            return;
        }
        
        int row=board.size();
        int col=board[0].size();
        for(int c = 0; c < col; c++)
        {
            dfs(board, 0, c, row, col);         // top row
            dfs(board, row-1, c, row, col);    // bottom row
        }

        for(int r = 0; r < row; r++)
        {
            dfs(board, r, 0, row, col);         // left column
            dfs(board, r, col-1, row, col);    // right column
        }

        final_check(row, col, board);

    }

    void dfs(vector<vector<char>>& board, int r, int c, int row, int col)
    {
        if(r < 0 || r >= row || c < 0 || c >= col || board[r][c] != 'O')
        {
            return;
        }

        board[r][c] = 'S';

        dfs(board, r+1,c, row, col);
        dfs(board, r-1,c, row, col);
        dfs(board, r,c+1, row, col);
        dfs(board, r,c-1, row, col);
    }

    void final_check(int row, int col, vector<vector<char>>& board)
    {
        for(int i=0; i<row; i++)
        {
            for(int j=0; j<col; j++)
            {
                if(board[i][j]=='S') board[i][j]='O';
                else if(board[i][j]=='O') board[i][j]='X';
            }
        }
        
    }

};