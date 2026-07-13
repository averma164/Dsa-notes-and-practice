// # 1004. Max Consecutive Ones III

// Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.

// # Approach :-

// We maintain a window [l, r] that contains at most k zeroes.
// 1) Initialize l = 0, r = 0, zeroes = 0, and maxlen = 0.
// 2) Traverse the array using r.
// 3) If nums[r] == 0, increment zeroes.
// 4) If zeroes > k, move l one step to the right. If the removed element is 0, decrement zeroes.
// 5) Update the maximum window size.
// 6) Continue until r reaches the end.

// # Complexity :-

// - Time Complexity: O(n)
// - Space Complexity: O(1)

// # Program :-

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int maxlen = 0, l = 0, r = 0, zeroes = 0;
        while(r < nums.size()){
            if(nums[r] == 0){
                zeroes++;
            }
            if(zeroes > k){
                if(nums[l] == 0) {
                    zeroes--;
                }
                l++;
            }
            if(zeroes <= k){
                int len = r - l + 1;
                maxlen = max(len, maxlen);
            }
            r++;
        }
        return maxlen;
    }
};
