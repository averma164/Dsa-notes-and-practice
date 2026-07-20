// # 1260. Shift 2D Grid

// Given a 2D grid of size m x n and an integer k. You need to shift the grid k times.
// In one shift operation:
// Element at grid[i][j] moves to grid[i][j + 1].
// Element at grid[i][n - 1] moves to grid[i + 1][0].
// Element at grid[m - 1][n - 1] moves to grid[0][0].
// Return the 2D grid after applying shift operation k times.

// # Algorithm :-

// 1) Find m and n.
// 2) Compute k %= (m*n) because shifting more than the number of elements repeats.
// 3) Create a new answer grid of size m × n.
// 4) For every cell (i, j):
//     - Convert to 1D index.
//     - Compute shifted index.
//     - Convert back to 2D.
//     - Place the value.

// # Complexity :-
// We visit every element once.
// - Time Complexity : O(m × n)
// - Space Complexity : O(m × n)

// # Program :-

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int total = m * n;
        vector<vector<int>> ans(m, vector<int>(n));
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                int oldIdx = i * n + j;
                int newIdx = (oldIdx + k) % total;
                int newRow = newIdx / n;
                int newCol = newIdx % n;
                ans[newRow][newCol] = grid[i][j];
            }
        }
        return ans;
    }
};
