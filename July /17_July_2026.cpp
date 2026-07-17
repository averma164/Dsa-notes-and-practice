// # 287. Find the Duplicate Number

// Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.
// There is only one repeated number in nums, return this repeated number.

// # Approach :-

// Use two pointers (left and right) to compare adjacent elements.
// 1) Sort the given array.
// 2) Initialize two pointers:
//     - left = 0
//     - right = 1
// 3) Traverse the array while right < nums.size().
// 4) If nums[left] == nums[right], return the duplicate.
// 5) Otherwise, increment both pointers.
// 6) If no duplicate is found, return -1.

// # Complexity :-

// - Time Complexity :
//     - Sorting: O(n log n)
//     - Traversal: O(n)
//     - Overall: O(n log n)
// - Space Complexity :
//     - O(1) (excluding the space used internally by the sorting algorithm)

// # Program :-

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int left = 0;
        int right = 1;
        while (right < nums.size()) {
            if (nums[left] == nums[right]){
                return nums[left];
            }
            left++;
            right++;
        }
        return -1;
    }
};
