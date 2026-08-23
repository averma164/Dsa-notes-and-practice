// 4031. Find All Numbers Disappeared in an Array II

// You are given an integer array nums and two integers lower and upper.
// A missing integer is an integer in the inclusive range [lower, upper] that does not appear in nums.
// Return a 2D integer array where each element is of the form [start, end], representing a contiguous range of missing integers. 
// Return the ranges in increasing order. If there are no missing integers, return an empty array.
// Note: Consecutive missing integers should be grouped into a single range.

// # Approach :-

// 1) Insert all elements of nums into an unordered_set `st` to allow O(1) average lookup time.
// 2) Initialize a dynamic 2D array `ans` to store the missing ranges and `start = -1` to track the beginning of an active missing range.
// 3) Iterate through every number `i` from `lower` to `upper`:
//      - If `i` is not in `st`:
//          - If `start == -1`, mark `start = i` as the start of a new missing interval.
//      - If `i` is in `st`:
//          - If `start != -1`, close the current missing interval by appending `[start, i - 1]` to `ans` and resetting `start = -1`.
// 4) After the loop, if `start != -1`, append the final missing interval `[start, upper]` to `ans`.
// 5) Return `ans`.

// # Complexity :-

// - Time Complexity: O(n + (upper - lower + 1))
//      O(n) time to populate the unordered_set from nums.
//      O(upper - lower + 1) time to iterate through the range [lower, upper] with O(1) average hash set lookups.
// - Space Complexity: O(n)
//      Auxiliary space used by the unordered_set `st` to store up to n unique elements from nums.

// # Program :-

vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
      unordered_set<int> st(nums.begin(), nums.end());
      vector<vector<int>> ans;
      int start = -1;
      for(int i = lower; i <= upper; i++){
          if(st.find(i) == st.end()){
              if(start == -1){
                  start = i;
              }
          }else{
              if(start != -1){
                  ans.push_back({start, i-1});
                  start = -1;
              }
          }
      }
      if(start != -1){
          ans.push_back({start, upper});
      }
      return ans;
}
