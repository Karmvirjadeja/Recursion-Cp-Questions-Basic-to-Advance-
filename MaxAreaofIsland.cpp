class Solution {
public:
    bool isValidate(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()) {
            return false;
        }
        return true;
    }


    void dfs(int& area, vector<vector<int>>& grid, int i, int j, int rows, int cols) {
        if (!isValidate(grid, i, j) || grid[i][j] == 0) {
            return;
        }


        grid[i][j] = 0; // mark the cell as visited
        area++;
       
        // explore the neighboring cells in all four directions
        dfs(area, grid, i + 1, j, rows, cols);
        dfs(area, grid, i - 1, j, rows, cols);
        dfs(area, grid, i, j + 1, rows, cols);
        dfs(area, grid, i, j - 1, rows, cols);
    }


    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        int rows = grid.size();
        int cols = grid[0].size();


        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) {
                    int area = 0;
                    dfs(area, grid, i, j, rows, cols);
                    maxArea = max(maxArea, area);
                }
            }
        }
        return maxArea;
    }
};
