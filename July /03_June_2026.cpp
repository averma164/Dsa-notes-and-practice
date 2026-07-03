// # 977. Squares of a Sorted Array

// Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.

// # Approach :-

// 1) Create an answer array ans of size n.
// 2) Initialize two pointers:
//     - l = 0 (left end)
//     - r = n - 1 (right end)
// 3) Traverse the answer array from the last index to the first.
//     - Compare abs(nums[l]) and abs(nums[r]).
//     - If abs(nums[l]) >= abs(nums[r]):
//     - Store nums[l] * nums[l] in ans[i].
//     - Increment l.
//     - Otherwise:
//     - Store nums[r] * nums[r] in ans[i].
//     - Decrement r.
// 4) Repeat until the answer array is completely filled.
// 5) Return ans.

// # Complexity :-

// - Time Complexity : O(n) – each element is processed exactly once.
// - Space Complexity : O(n) – an additional array is used to store the sorted squared values.

// # Program :-

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = ssize(nums);
        vector<int> ans(n);

        int l = 0, r = n - 1;
        for (int i = n - 1; i >= 0; i--) {
            if (abs(nums[l]) >= abs(nums[r])) {
                ans[i] = nums[l] * nums[l];
                l++;
            } else {
                ans[i] = nums[r] * nums[r];
                r--;
            }
        }
        return ans;
    }
};
