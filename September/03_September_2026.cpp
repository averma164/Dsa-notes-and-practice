// # 541. Reverse String II
//
// Given a string s and an integer k, reverse the first k characters
// for every 2k characters counting from the start of the string.
//
// If fewer than k characters are left, reverse all of them.
// If there are at least k but fewer than 2k characters left,
// reverse only the first k characters and leave the remaining
// characters unchanged.
//
// # Approach :-
//
// We process the string in blocks of 2k characters.
//
// 1) Start from index 0.
// 2) Move i by 2k each time because only the first k characters
//    of every 2k block need to be reversed.
// 3) Set left = i.
// 4) Set right = min(i + k - 1, s.length() - 1).
// 5) Reverse the characters between left and right using two pointers.
// 6) If fewer than k characters are left, right automatically becomes
//    the last index of the string, so all remaining characters are reversed.
// 7) Return the modified string.
//
// # Complexity Analysis :-
//
// 1) Time Complexity: O(n)
// 2) Space Complexity: O(1)
//
// # Program :-

class Solution {
public:
    string reverseStr(string s, int k) {
        for(int i = 0; i < s.length(); i += 2 * k){
            int left = i;
            int right = min(i + k - 1, (int)s.length() - 1);

            while(left < right){
                swap(s[left], s[right]);
                left++;
                right--;
            }
        }

        return s;
    }
};
