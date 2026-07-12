// # 1331. Rank Transform of an Array

// Given an array of integers arr, replace each element with its rank.
// The rank represents the position of the element in the sorted array.
// Rules:
// - Rank starts from 1.
// - Equal elements receive the same rank.
// - Larger elements receive larger ranks.

// # Approach :-

// 1) Create a copy of the original array.
// 2) Sort the copied array.
// 3) Traverse the sorted array and assign ranks only to unique elements
//    using a hash map.
// 4) Traverse the original array and replace each element with its
//    corresponding rank from the hash map.
// 5) Return the transformed array.

// # Complexity :-

// - Time Complexity : O(n log n)
//   (Sorting takes O(n log n), while assigning ranks and building the
//    answer each take O(n).)
// - Space Complexity : O(n)
//   (For the copied array, hash map, and answer array.)

// # Program :-

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> copy = arr;
        sort(copy.begin(), copy.end());

        unordered_map<int, int> rank;
        int currRank = 1;

        for (int num : copy) {
            if (rank.find(num) == rank.end()) {
                rank[num] = currRank++;
            }
        }

        vector<int> ans;
        for (int num : arr) {
            ans.push_back(rank[num]);
        }

        return ans;
    }
};
