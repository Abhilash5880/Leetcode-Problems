class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        // 🔹 Step 1: Transpose the matrix (swap across main diagonal)
        // Only traverse upper triangle to avoid double swapping
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // 🔹 Step 2: Reverse each row (mirror horizontally)
        for (int i = 0; i < n; i++) {
            // swap elements from both ends moving towards center
            for (int j = 0; j < n / 2; j++) {
                swap(matrix[i][j], matrix[i][n - 1 - j]);
            }
        }
    }
};