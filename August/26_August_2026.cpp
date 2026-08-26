// 2904. Shortest and Lexicographically Smallest Beautiful String

// You are given a binary string s and a positive integer k.
// A substring of s is beautiful if the number of 1's in it is exactly k.
// Let len be the length of the shortest beautiful substring.
// Return the lexicographically smallest beautiful substring of string s with length equal to len. If s doesn't contain a beautiful substring, return an empty string.
// A string a is lexicographically larger than a string b (of the same length) if in the first position where a and b differ, a has a character strictly larger than the corresponding character in b.
// For example, "abcd" is lexicographically larger than "abcc" because the first position they differ is at the fourth character, and d is greater than c.

// # Approach :-

// 1) Use a sliding window approach with two pointers `l` (left) and `r` (right) to maintain a window containing exactly `k` ones.
// 2) Expand the window by iterating `r` from 0 to n - 1 and increment `ones` whenever `s[r] == '1'`.
// 3) When `ones == k`, shrink unnecessary leading zeros from the left using `while (l <= r && ones == k && s[l] == '0') l++` to minimize substring length.
// 4) Once the window is minimal for the current `r`:
//      - Extract `curr = s.substr(l, r - l + 1)`.
//      - If `curr.size() < minLen`, update `minLen` and `ans = curr`.
//      - If `curr.size() == minLen` and `curr < ans` lexicographically, update `ans = curr`.
//      - Shrink the window by decrementing `ones` (since `s[l]` is guaranteed to be `'1'`) and incrementing `l` to look for other valid substrings.
// 5) Return `ans`.

// # Complexity :-

// - Time Complexity: O(n^2)
//      The two pointers `l` and `r` each traverse the string of length n at most once (O(n) amortized steps).
//      In the worst case, string extraction via `substr` and lexicographical string comparisons take O(n) time per valid window, leading to an overall O(n^2) time complexity.
// - Space Complexity: O(n)
//      Auxiliary space used for storing candidate substring `curr` and the final answer `ans`.

// # Program :-

class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        int l = 0, ones = 0;
        int minLen = INT_MAX;
        string ans = "";
        for (int r = 0; r < n; r++) {
            if (s[r] == '1') {
                ones++;
            }
            while (l <= r && ones == k && s[l] == '0') {
                l++;
            }
            if (ones == k) {
                string curr = s.substr(l, r - l + 1);
                if (curr.size() < minLen || (curr.size() == minLen && curr < ans)) {
                    minLen = curr.size();
                    ans = curr;
                }
                if (s[l] == '1') {
                    ones--;
                }
                l++;
            }
        }
        return ans;
    }
};
