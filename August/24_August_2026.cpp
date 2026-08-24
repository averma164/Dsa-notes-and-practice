// # 264. Ugly Number II

// An ugly number is a positive integer whose prime factors are limited to 2, 3, and 5.
// Given an integer n, return the nth ugly number.

// # Approach :-

// 1) Use Dynamic Programming with three pointers (i2, i3, i5) to generate ugly numbers in ascending order.
// 2) Initialize an array `ugly` of size n, with `ugly[0] = 1` as the first ugly number.
// 3) Initialize three pointers `i2 = 0`, `i3 = 0`, and `i5 = 0`, each representing indices of ugly numbers to be multiplied by 2, 3, and 5 respectively.
// 4) Loop from index 1 to n - 1:
//      - Compute candidates: `next2 = ugly[i2] * 2`, `next3 = ugly[i3] * 3`, and `next5 = ugly[i5] * 5`.
//      - The next ugly number is `nextUgly = min({next2, next3, next5})`.
//      - Store `nextUgly` at `ugly[i]`.
//      - Increment the pointer(s) corresponding to the chosen minimum value (independent `if` conditions to eliminate duplicates like 2 * 3 == 3 * 2).
// 5) Return `ugly[n - 1]`.

// # Complexity :-

// - Time Complexity: O(n)
//      A single loop runs n - 1 times, performing constant-time comparisons and pointer updates in each iteration.
// - Space Complexity: O(n)
//      An array `ugly` of size n is used to store the first n ugly numbers.

// # Program :-

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> ugly(n);
        ugly[0] = 1;
        int i2 = 0, i3 = 0, i5 = 0;
        for (int i = 1; i < n; i++) {
            int next2 = ugly[i2] * 2;
            int next3 = ugly[i3] * 3;
            int next5 = ugly[i5] * 5;
            int nextUgly = min(next2, min(next3, next5));
            ugly[i] = nextUgly;
            if (nextUgly == next2) {
                i2++;
            }
            if (nextUgly == next3) {
                i3++;
            }
            if (nextUgly == next5) {
                i5++;
            }
        }
        return ugly[n - 1];
    }
};
