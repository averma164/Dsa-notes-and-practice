# 3. Longest Substring Without Repeating Characters

Given a string s, find the length of the longest substring without duplicate characters.

# Approach :-

Use a sliding window with two pointers (l and r).
1) Initialize an empty hash map.
2) Traverse the string using the right pointer.
4) If the current character exists in the current window, update the left pointer.
5) Store the current index of the character.
6) Update the maximum window size.
7) Return the maximum length.

# Complexity :-

- Time Complexity: O(n)
- Space Complexity: O(min(n, 256))

# Program :-

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int l = 0, r = 0;
        int maxlen = 0;
        int n = s.size();
        while(r<n){
            if (mp.find(s[r]) != mp.end() && mp[s[r]] >= l) {
                l = mp[s[r]] + 1;
            }
            mp[s[r]] = r;
            maxlen = max(maxlen, r - l + 1);
            r++;
        }
        return maxlen;
    }
};
