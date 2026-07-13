class Solution {
    int maxArea = 0;
public:
    int dfs(vector<vector<int>>& grid, int r, int c)
    {
        int row = grid.size();
        int col = grid[0].size();

        if(r<0|| r>= row || c<0 || c>=col || grid[r][c] !=1) return 0;
        grid[r][c]=0; //packing invalid and 0 squares together

        return 1+dfs(grid,r+1,c)
        +dfs(grid,r-1,c)
        +dfs(grid,r,c+1)
        +dfs(grid,r,c-1);

    }
        
    int maxAreaOfIsland(vector<vector<int>>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size();
        int area=0;
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if (grid[i][j] == 1) {
                    area=dfs(grid , i , j);
                    maxArea=max(area, maxArea);
                }
            }
        }

        return maxArea;
    }
};

