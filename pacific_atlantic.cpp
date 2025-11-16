#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    int R, C;

    // DFS function: Marks all cells reachable from (r, c)
    void dfs(const vector<vector<int>>& heights, int r, int c, vector<vector<bool>>& reachable) {
        // Mark the current cell as reachable
        reachable[r][c] = true;

        // Define movement directions (Down, Up, Right, Left)
        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, 1, -1};

        for (int i = 0; i < 4; ++i) {
            int nr = r + dr[i]; // Next row
            int nc = c + dc[i]; // Next column

            // 1. Check bounds
            if (nr < 0 || nr >= R || nc < 0 || nc >= C) {
                continue;
            }

            // 2. Check if already visited/reachable
            if (reachable[nr][nc]) {
                continue;
            }

            // 3. Check reverse flow condition:
            // Water flows from higher/equal to lower/equal. 
            // Inward flow (from ocean to land): Next cell must be >= current cell.
            if (heights[nr][nc] >= heights[r][c]) {
                dfs(heights, nr, nc, reachable);
            }
        }
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        if (heights.empty() || heights[0].empty()) {
            return {};
        }

        R = heights.size();
        C = heights[0].size();

        // Two visited arrays to track reachability from each ocean
        vector<vector<bool>> pacific_reachable(R, vector<bool>(C, false));
        vector<vector<bool>> atlantic_reachable(R, vector<bool>(C, false));
        vector<vector<int>> result;

        // --- Step 1: DFS from Pacific Border ---
        for (int i = 0; i < R; ++i) {
            dfs(heights, i, 0, pacific_reachable); // Left border
        }
        for (int j = 0; j < C; ++j) {
            dfs(heights, 0, j, pacific_reachable); // Top border
        }

        // --- Step 2: DFS from Atlantic Border ---
        for (int i = 0; i < R; ++i) {
            dfs(heights, i, C - 1, atlantic_reachable); // Right border
        }
        for (int j = 0; j < C; ++j) {
            dfs(heights, R - 1, j, atlantic_reachable); // Bottom border
        }

        // --- Step 3: Find Intersection ---
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                // If a cell is reachable by BOTH oceans, it's a solution
                if (pacific_reachable[i][j] && atlantic_reachable[i][j]) {
                    result.push_back({i, j});
                }
            }
        }

        return result;
    }
};