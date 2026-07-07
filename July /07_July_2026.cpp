// # 3754. Concatenate Non-Zero Digits and Multiply by Sum I

// You are given an integer n.
// Form a new integer x by concatenating all the non-zero digits of n in their original order. If there are no non-zero digits, x = 0.
// Let sum be the sum of digits in x.
// Return an integer representing the value of x * sum.

// # Approach :-

// 1) Convert the integer n into a string so each digit can be processed easily.
// 2)Traverse every digit:
//     - Ignore '0'.
//     - Add the non-zero digit to a new string num.
//     - Add its numeric value to sum.
// 3) If all digits were 0, return 0 to avoid calling stoll() on an empty string.
// 4) Convert the string num back to a long long using stoll().
// 5) Return the product of sum and the formed number

// # Complexity :-

// - Time Complexity: O(d), where d is the number of digits in n.
// - Space Complexity: O(d) for storing the string of non-zero digits.

// # Program :-

class Solution {
public:
    long long sumAndMultiply(int n) {
        long long sum = 0;
        string num = "";
        string word = to_string(n);
        for (char letter : word) {
            if (letter != '0') {
                num += letter;
                sum += letter - '0';
            }
        }
        if (num.empty()){
            return 0;
        }
        return sum * stoll(num);
    }
};
