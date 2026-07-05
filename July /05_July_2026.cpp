// # 463. Island Perimeter

// You are given row x col grid representing a map where grid[i][j] = 1 represents land and grid[i][j] = 0 represents water.
// Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells).
// The island doesn't have "lakes", meaning the water inside isn't connected to the water around the island. One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100.
// Determine the perimeter of the island.

// # Approach :-
  
// 1. Traverse every cell in the grid.
// 2. If the current cell is land (`1`):
//    - Add `4` to the perimeter.
//    - If the upper cell is land, subtract `2`.
//    - If the left cell is land, subtract `2`.
// 3. Return the final perimeter.

// # Complexity :-
  
// - Time Complexity : O(rows × cols)
// - Space Complexity : O(1)

// # Program :-

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int perimeter = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) {
                    perimeter += 4;
                    if (i > 0 && grid[i - 1][j] == 1){
                        perimeter -= 2;
                    }
                    if (j > 0 && grid[i][j - 1] == 1){
                        perimeter -= 2;
                    } 
                }
            }
        }
        return perimeter;
    }
};
