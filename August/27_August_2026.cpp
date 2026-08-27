// 200. Number of Islands

// Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.
// An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

// # Approach :-

// 1) Use Depth First Search (DFS) to traverse and mark connected components of land ('1').
// 2) Initialize a visited matrix `vis` of size m x n with all values set to `false`.
// 3) Iterate through every cell `(i, j)` in the grid:
//      - If `grid[i][j] == '1'` and the cell has not been visited (`!vis[i][j]`):
//          - Trigger a DFS traversal starting from `(i, j)` to mark all reachable adjacent land cells as visited.
//          - Increment the `islands` count by 1.
// 4) Inside the DFS helper:
//      - Check base cases: if coordinates are out of bounds, already visited, or water (`grid[i][j] != '1'`), return immediately.
//      - Mark the current cell `vis[i][j] = true`.
//      - Recursively visit all 4 orthogonal directions: top `(i-1, j)`, right `(i, j+1)`, left `(i, j-1)`, and bottom `(i+1, j)`.
// 5) Return `islands`.

// # Complexity :-

// - Time Complexity: O(m * n)
//      Each cell in the grid is visited a constant number of times during the nested loops and DFS traversals.
// - Space Complexity: O(m * n)
//      O(m * n) auxiliary space for the `vis` matrix and up to O(m * n) space on the recursion call stack in the worst-case scenario (grid full of land).

// # Program :-

class Solution {
public:
    void dfs(int i, int j, vector<vector<bool>>& vis, vector<vector<char>>& grid, int n, int m) {
        if (i < 0 || j < 0 || i >= n || j >= m || vis[i][j] || grid[i][j] != '1') {
            return;
        }

        vis[i][j] = true;
        dfs(i - 1, j, vis, grid, n, m); // top
        dfs(i, j + 1, vis, grid, n, m); // right
        dfs(i, j - 1, vis, grid, n, m); // left
        dfs(i + 1, j, vis, grid, n, m); // bottom
    }

    int numIslands(vector<vector<char>>& grid) {
        int islands = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1' && !vis[i][j]) {
                    dfs(i, j, vis, grid, n, m);
                    islands++;
                }
            }
        }

        return islands;
    }
};
