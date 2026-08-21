// 3069. Distribute Elements Into Two Arrays I

// You are given a 1-indexed array of distinct integers nums of length n.
// You need to distribute all the elements of nums between two arrays arr1 and arr2 using n operations. 
// In the first operation, append nums[1] to arr1. In the second operation, append nums[2] to arr2. Afterwards, in the ith operation:
// If the last element of arr1 is greater than the last element of arr2, append nums[i] to arr1. Otherwise, append nums[i] to arr2.
// The array result is formed by concatenating the arrays arr1 and arr2. For example, if arr1 == [1,2,3] and arr2 == [4,5,6], then result = [1,2,3,4,5,6].
// Return the array result.

// # Approach :-

// 1) Initialize two dynamic arrays (arr1 and arr2).
// 2) Place the first element nums[0] into arr1 and the second element nums[1] into arr2.
// 3) Iterate through the remaining elements of nums from index 2 to n - 1:
//      - Compare the current tail elements: arr1.back() and arr2.back().
//      - If arr1.back() > arr2.back(), append nums[i] to arr1.
//      - Else, append nums[i] to arr2.
// 4) Append all elements of arr2 to the end of arr1.
// 5) Return arr1.

// # Complexity :-

// - Time Complexity: O(n)
//      Single pass from index 2 to n - 1 to distribute the elements.
//      Another pass to append elements of arr2 into arr1.
// - Space Complexity: O(n)
//      Auxiliary space used by arr1 and arr2 to store the partitioned elements.

// # Program :-

class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> arr1;
        vector<int> arr2;

        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);

        for (int i = 2; i < nums.size(); i++) {
            if (arr1.back() > arr2.back()) {
                arr1.push_back(nums[i]);
            } else {
                arr2.push_back(nums[i]);
            }
        }

        for (int i = 0; i < arr2.size(); i++) {
            arr1.push_back(arr2[i]);
        }

        return arr1;
    }
};
