class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> res;

        int top = 0, bottom = m - 1;
        int left = 0, right = n - 1;

        while (top <= bottom && left <= right) {

            // 🔹 1. Traverse top row (left → right)
            for (int j = left; j <= right; j++) {
                res.push_back(matrix[top][j]);
            }
            top++;

            // 🔹 2. Traverse right column (top → bottom)
            for (int i = top; i <= bottom; i++) {
                res.push_back(matrix[i][right]);
            }
            right--;

            // 🔹 3. Traverse bottom row (right → left)
            if (top <= bottom) {
                for (int j = right; j >= left; j--) {
                    res.push_back(matrix[bottom][j]);
                }
                bottom--;
            }

            // 🔹 4. Traverse left column (bottom → top)
            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    res.push_back(matrix[i][left]);
                }
                left++;
            }
        }

        return res;
    }
};