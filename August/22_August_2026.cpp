// # 3432. Count Partitions with Even Sum Difference / Check Divisibility

// You are given an integer n.
// A number is divisible by the sum and product of its digits if n is divisible by the sum of its digits plus the product of its digits (total = sum + product).
// Return true if n is divisible by this total value, otherwise return false.

// # Approach :-

// 1) Store the original value of n in a temporary variable x to extract digits.
// 2) Initialize `sum = 0` to store the sum of digits and `prod = 1` to store the product of digits.
// 3) Use a while loop to extract digits from x one by one:
//      - Extract the last digit using `dig = x % 10`.
//      - Add `dig` to `sum`.
//      - Multiply `prod` by `dig`.
//      - Remove the last digit from x using `x = x / 10`.
// 4) Calculate `total = sum + prod`.
// 5) Return true if `n % total == 0`, otherwise return false.

// # Complexity :-

// - Time Complexity: O(log(n))
//      The loop runs once for each digit in the integer n, which is proportional to the number of digits log10(n).
// - Space Complexity: O(1)
//      Only a few integer variables (x, sum, prod, dig, total) are used, requiring constant auxiliary space.

// # Program :-

class Solution {
public:
    bool checkDivisibility(int n) {
        int x = n;
        int sum = 0;
        int prod = 1;
        while (x > 0) {
            int dig = x % 10;
            sum = sum + dig;
            prod = prod * dig;
            x = x / 10;
        }
        int total = sum + prod;
        return (n % total == 0);
    }
};
