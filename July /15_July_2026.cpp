// # 744. Find Smallest Letter Greater Than Target

// You are given an array of characters letters that is sorted in non-decreasing order, and a character target. There are at least two different characters in letters.
// Return the smallest character in letters that is lexicographically greater than target. If such a character does not exist, return the first character in letters.

// # Approach :-

// 1) Check if target >= letters[n-1].
//     - If yes, return letters[0].
// 2) Initialize:
//     - i = 0
//     - j = n - 1
// 3) While i <= j:
//     - Compute mid.
//     - If letters[mid] <= target, search the right half.
//     - Otherwise, search the left half.
// 4) Return letters[i].

// # Complexity :-

// - Time Complexity : O(log n) (Binary Search)
// - Space Complexity : O(1)

// # Program :-

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int i = 0;
        int j = letters.size() - 1;
        if (target >= letters[j]) {
            return letters[0];
        }
        while (i <= j) {
            int mid = i + (j - i) / 2;
            if (letters[mid] <= target) {
                i = mid + 1;
            } else {
                j = mid - 1;
            }
        }
        return letters[i];
    }
};
