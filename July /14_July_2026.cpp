// # 392. Is Subsequence

// Given two strings s and t, return true if s is a subsequence of t, or false otherwise.

// # Approach :-

// Use the two-pointer technique.
// 1) Initialize two pointers:
//   - i for string s
//   - j for string t
// 2) Traverse both strings simultaneously.
// 3) If s[i] == t[j], move i to the next character.
// 4) Always move j forward.
// 5) If i reaches the end of s, then all characters of s have been found in order inside t.

// # Complexity :-

// - Time Complexity : O(n) where n is the length of t.
// - Space Complexity : O(1) since only two pointers are used.

// # Program :-

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0, j = 0;
        while (i < s.size() && j < t.size()) {
            if (s[i] == t[j]) {
                i++;
            }
            j++;
        }
        return i == s.size();
    }
};
