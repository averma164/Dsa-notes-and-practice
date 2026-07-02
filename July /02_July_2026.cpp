// 1685. Sum of Absolute Differences in a Sorted Array

// You are given an integer array nums sorted in non-decreasing order.
// Build and return an integer array result with the same length as nums such that result[i] is equal to the summation of absolute differences between nums[i] and all the other elements in the array.
// In other words, result[i] is equal to sum(|nums[i]-nums[j]|) where 0 <= j < nums.length and j != i (0-indexed).

// # Approach :-

// Using prefix sums:
// Left contribution = nums[i] * i - leftSum
// Right contribution = rightSum - nums[i] * (n - i - 1)
// 1) Compute the sum of all elements (totalSum).
// 2) Initialize leftSum = 0.
// 3) Traverse the array from left to right:
//     - Calculate rightSum = totalSum - leftSum - nums[i].
//     - Compute the left contribution:
//     - left = nums[i] * i - leftSum
//     - Compute the right contribution:
//     - right = rightSum - nums[i] * (n - i - 1)
//     - Store left + right in the answer array.
//     - Update leftSum += nums[i].
// 4) Return the answer array.

// # Complexity :-

// - Time Complexity: O(n)
//     One pass to compute the total sum.
//     One pass to compute the answer for each element.
// - Space Complexity: O(1) 
//     auxiliary space (excluding the output array). 
//     The only extra variables used are totalSum, leftSum, rightSum, left, and right.

// # Program :-

class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0;

        for (int num : nums) {
            totalSum += num;
        }

        int leftSum = 0;
        vector<int> ans(n);

        for (int i = 0; i < n; i++) {
            int rightSum = totalSum - leftSum - nums[i];

            int left = nums[i] * i - leftSum;
            int right = rightSum - nums[i] * (n - i - 1);

            ans[i] = left + right;
            leftSum += nums[i];
        }

        return ans;
    }
};
