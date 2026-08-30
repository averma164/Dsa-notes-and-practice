// # 2091. Removing Minimum and Maximum From Array

// You are given a 0-indexed array of distinct integers nums.
// There is an element in nums that has the lowest value and an element that has the highest value. We call them the minimum and maximum respectively. Your goal is to remove both these elements from the array.
// A deletion is defined as either removing an element from the front of the array or removing an element from the back of the array.
// Return the minimum number of deletions it would take to remove both the minimum and maximum element from the array.

// # Approach :-

// 1) Find the indices of the minimum element (`mi`) and the maximum element (`ma`) in the array `nums`.
// 2) Ensure `mi <= ma` by swapping them if `mi > ma`, so that `mi` is always the left index and `ma` is the right index.
// 3) There are three possible deletion strategies to remove both elements:
//      - Remove both from the front: Requires `ma + 1` deletions (since removing up to the further index removes both).
//      - Remove both from the back: Requires `n - mi` deletions (since removing from the end up to the earlier index removes both).
//      - Remove from both sides: Remove the minimum from the front (`mi + 1` deletions) and the maximum from the back (`n - ma` deletions), giving `(mi + 1) + (n - ma)`.
// 4) Return the minimum of these three values: `min({front, back, both})`.

// # Complexity :-

// - Time Complexity: O(n)
//      A single pass over the array of size n to identify the minimum and maximum elements and their indices.
// - Space Complexity: O(1)
//      Only a few scalar variables are used, requiring constant auxiliary space.

// # Program :-

class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int minimum = INT_MAX;
        int maximum = INT_MIN;
        int mi = 0;
        int ma = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] < minimum) {
                minimum = nums[i];
                mi = i; 
            }
            if (nums[i] > maximum) {
                maximum = nums[i];
                ma = i;
            }
        }
        if (mi > ma) { 
            int temp = mi;
            mi = ma;
            ma = temp; 
        }
        int front = ma + 1;
        int back = n - mi;
        int both = (mi + 1) + (n - ma);
        return min({front, back, both});
    }
};
