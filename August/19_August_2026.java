// # 139. Word Break

// Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.

// # Approach :-
// We use Dynamic Programming with an optimization based on the maximum word length in the dictionary:

// 1) Store all words from wordDict into a HashSet for O(1) average lookup time.
// 2) Find the maximum length of any word in wordDict (maxLen) to avoid checking substrings longer than the longest dictionary word.
// 3) Create a boolean array dp of size n + 1, where dp[i] represents whether the prefix s[0...i-1] can be segmented.
// 4) Initialize dp[0] = true (an empty string is always valid).
// 5) Iterate i from 1 to n:
//    - Iterate j backwards from i - 1 down to max(0, i - maxLen).
//    - If dp[j] is true and the substring s[j...i-1] exists in the HashSet, set dp[i] = true and break early.
// 6) Return dp[n], which indicates whether the entire string s can be segmented.

// # Complexity Analysis :-

// 1) Time Complexity: O(n * min(n, maxLen)^2)
//    - The outer loop runs n times.
//    - The inner loop runs at most maxLen times.
//    - Generating substrings and hashing takes O(maxLen) time.
// 2) Space Complexity: O(n + k)
//    - dp array takes O(n) space.
//    - HashSet takes O(k) space, where k is the total number of characters across all words in wordDict.

// # Program :-

class Solution {
    public boolean wordBreak(String s, List<String> wordDict) {
        Set<String> wordset = new HashSet<>(wordDict);
        int maxLen = 0;
        for (String word : wordDict) {
            maxLen = Math.max(maxLen, word.length());
        }
        int n = s.length();
        boolean[] dp = new boolean[n + 1];
        dp[0] = true;
        for (int i = 1; i <= n; i++) {
            for (int j = i - 1; j >= Math.max(0, i - maxLen); j--) {
                if (dp[j] && wordset.contains(s.substring(j, i))) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
}
