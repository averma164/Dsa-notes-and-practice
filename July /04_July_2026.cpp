// # 62. Unique Paths

// There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). 
// The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.
// Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.
// The test cases are generated so that the answer will be less than or equal to 2 * 109.

// # Approach :- Dynamic Programming (Space Optimized)

// Update each column using:
// dp[j] = dp[j] + dp[j - 1];
// where:
// dp[j] (before update) = paths from the top.
// dp[j - 1] = paths from the left.
// 1) Initialize a 1D DP array of size n with all values equal to 1.
// 2) Iterate through rows from 1 to m - 1.
// 3) For each row, update columns from 1 to n - 1:
//     - dp[j] = dp[j] + dp[j - 1];
// 4) Return dp[n - 1].

// # Complexity :-

// - TimeComplexity : O(m × n)
// - Space Complexity : O(n)

// # Program :-

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n, 1);
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[j] = dp[j] + dp[j - 1];
            }
        }
        return dp[n - 1];
    }
};
