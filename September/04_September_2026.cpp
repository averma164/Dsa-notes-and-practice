// # 3903. Smallest Stable Index I
//
// You are given an integer array nums and an integer k.
// For each index i, the instability score is:
//     max(nums[0..i]) - min(nums[i..n-1])
// An index i is stable if its instability score is less than
// or equal to k.
// Return the smallest stable index. If no stable index exists,
// return -1.
//
// # Approach :-
//
// We check every index i one by one.
//
// 1) Start from index 0.
// 2) For each index i, find the maximum element from index 0 to i.
// 3) Find the minimum element from index i to n-1.
// 4) Calculate the instability score:
//         maxLeft - minRight
// 5) If the score is less than or equal to k, return i immediately
//    because we need the smallest stable index.
// 6) If no index satisfies the condition, return -1.
//
// # Complexity Analysis :-
//
// 1) Time Complexity: O(n²)
// 2) Space Complexity: O(1)
//
// # Program :-

class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        for(int i = 0; i < n; i++){
            int maxLeft = INT_MIN;
            int minRight = INT_MAX;
            for(int j = 0; j <= i; j++){
                maxLeft = max(maxLeft, nums[j]);
            }
            for(int j = i; j < n; j++){
                minRight = min(minRight, nums[j]);
            }
            if(maxLeft - minRight <= k){
                return i;
            }
        }
        return -1;
    }
};
