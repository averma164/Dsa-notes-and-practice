// # 1464. Maximum Product of Two Elements in an Array

// Given the array of integers nums, you will choose two different indices i and j of that array. Return the maximum value of (nums[i]-1)*(nums[j]-1).

// # Algorithm :-

// (Sorting Approach)
// 1) Sort the array in ascending order.
// 2) After sorting:
//     - The largest element is nums[n-1].
//     - The second largest element is nums[n-2].
// 3)Compute:
//     - (nums[n−1]−1)×(nums[n−2]−1)
// 4) Return the result

// # Complexity :-
// - Time Complexity: O(n log n) (due to sorting)
// - Space Complexity: O(1) (ignoring the space used internally by the sorting algorithm)

// # Program :-

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size() -1;
        return (nums[n-1] - 1)*(nums[n]-1);
    }
};
