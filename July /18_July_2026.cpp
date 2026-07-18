// # 1979. Find Greatest Common Divisor of Array

// Given an integer array nums, return the greatest common divisor of the smallest number and largest number in nums.
// The greatest common divisor of two numbers is the largest positive integer that evenly divides both numbers.

// # Approach :-

// Using the built-in gcd() function.
// 1) Find the minimum element using min_element().
// 2) Find the maximum element using max_element().
// 3) Return gcd(minimum, maximum).

// # Complexity :-

// - Time Complexity: O(n)
//     - Finding the minimum and maximum elements takes O(n).
//     - Computing the GCD takes O(log(min(mn, mx))).
//     - Overall: O(n).
// - Space Complexity: O(1)
//     - Only a few extra variables are used.

// # Program :-

class Solution {
public:
    int findGCD(vector<int>& nums) {
        int mn = *min_element(nums.begin(), nums.end());
        int mx = *max_element(nums.begin(), nums.end());
        return gcd(mn, mx);
    }
};
