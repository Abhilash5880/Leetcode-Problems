class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        // 🔹 Store seen numbers for:
        // rows[i]   → numbers seen in row i
        // cols[j]   → numbers seen in col j
        // boxes[k]  → numbers seen in box k
        vector<unordered_set<char>> rows(9);
        vector<unordered_set<char>> cols(9);
        vector<unordered_set<char>> boxes(9);

        // 🔹 Traverse entire board
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {

                char curr = board[i][j];

                // 🔹 Ignore empty cells
                if (curr == '.') continue;

                // 🔹 Compute 3x3 box ID
                int boxID = (i / 3) * 3 + (j / 3);

                // 🔹 If number already exists → invalid Sudoku
                if (rows[i].count(curr) ||
                    cols[j].count(curr) ||
                    boxes[boxID].count(curr)) {

                    return false;
                }

                // 🔹 Otherwise store number
                rows[i].insert(curr);
                cols[j].insert(curr);
                boxes[boxID].insert(curr);
            }
        }

        // 🔹 No conflicts found
        return true;
    }
};