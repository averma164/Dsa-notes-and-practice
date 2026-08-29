// # 396. Rotate Function

// You are given an integer array nums of length n.
// Assume arrk to be an array obtained by rotating nums by k positions clock-wise. We define the rotation function F on nums as follow:
// F(k) = 0 * arrk[0] + 1 * arrk[1] + ... + (n - 1) * arrk[n - 1].
// Return the maximum value of F(0), F(1), ..., F(n-1).
// The test cases are generated so that the answer fits in a 32-bit integer.

// # Approach :-

// 1) Observe the mathematical relationship between consecutive rotations:
//      - F(0) = 0 * nums[0] + 1 * nums[1] + ... + (n - 1) * nums[n - 1]
//      - F(1) = 0 * nums[n - 1] + 1 * nums[0] + 2 * nums[1] + ... + (n - 1) * nums[n - 2]
//      - Subtracting F(0) from F(1) reveals the recurrence relation:
//        F(k) = F(k - 1) + sum(nums) - n * nums[n - k]
// 2) Compute the sum of all elements `sum` and the initial value `F(0)` in a single pass.
// 3) Initialize `ans = F` to track the maximum value across all rotations.
// 4) Loop `k` from 1 to n - 1:
//      - Update `F` in O(1) time using the recurrence relation: `F = F + sum - n * nums[n - k]`.
//      - Update `ans = max(ans, F)`.
// 5) Return `ans` cast to an integer.

// # Complexity :-

// - Time Complexity: O(n)
//      One pass to compute the total sum and initial F(0), and a second pass of n - 1 iterations where each transition takes O(1) time.
// - Space Complexity: O(1)
//      Only a few scalar variables (`sum`, `F`, `ans`) are used, requiring constant auxiliary space.

// # Program :-

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        long long sum = 0;
        long long F = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            F += 1LL * i * nums[i];
        }
        long long ans = F;
        for (int k = 1; k < n; k++) {
            F = F + sum - 1LL * n * nums[n - k];
            ans = max(ans, F);
        }
        return (int)ans;
    }
};
