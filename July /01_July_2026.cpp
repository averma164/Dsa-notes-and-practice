// 119. Pascal's Triangle II

// Given an integer rowIndex, return the rowIndexth (0-indexed) row of the Pascal's triangle.

// Approach :-
// Instead of generating the entire Pascal's Triangle, we directly compute each element using the relation:

// C(n,r)= C(n,r-1) * (n - r - 1) / r 

// 1) Initialize the answer vector with the first element 1.
// 2) Set the current coefficient to 1.
// 3) Iterate from 1 to rowIndex.
// 4) Compute the next coefficient using:
//         coeff = coeff * (rowIndex - i + 1) / i
// 5) Append the computed coefficient to the answer vector.
// 6) Return the generated row.

// Complexity Analysis :-

// 1) Time Complexity: O(rowIndex)
// 2) Space Complexity: O(rowIndex)

// # Program :-

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        long long ans = 1;
        vector<int> rows;
        rows.push_back(1);
        for(int i = 1; i <= rowIndex; i++) {
            ans = ans * (rowIndex - i + 1);
            ans = ans / i;
            rows.push_back(ans);
        }
        return rows;
    }
};