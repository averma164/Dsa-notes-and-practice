// # 3718. Smallest Missing Multiple of K

// Given an integer array nums and an integer k, return the smallest positive multiple of k that is missing from nums.
// A multiple of k is any positive integer divisible by k.

// # Approach :-

// Using unordered_set:

// 1) Store all elements of nums in an unordered_set.
//    This allows us to check whether an element exists in O(1) average time.

// 2) Start with the first positive multiple of k:
//        multiple = k

// 3) Check whether multiple exists in the set.
//    - If it exists, move to the next multiple by adding k.
//    - Repeat until we find a multiple that does not exist.

// 4) Return that missing multiple.

// # Complexity :-

// - Time Complexity: O(n)
//     Creating the unordered_set takes O(n).
//     Checking multiples takes O(n) in the worst case.

// - Space Complexity: O(n)
//     An unordered_set is used to store the elements of nums.

// # Program :-

class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> st(nums.begin(), nums.end());
        int multiple = k;
        while (st.count(multiple)) {
            multiple += k;
        }
        return multiple;
    }
};
