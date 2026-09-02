// # 575. Distribute Candies
//
// Alice has n candies, where the ith candy is of type candyType[i].
// Alice can eat only n/2 candies and wants to eat the maximum number
// of different types of candies.
//
// Return the maximum number of different candy types she can eat.
//
// # Approach :-
//
// We use a set to store all the unique candy types.
//
// 1) Initialize a set to store different candy types.
// 2) Traverse through the candyType array.
// 3) Insert each candy type into the set.
// 4) The size of the set gives the total number of different types.
// 5) Alice can eat only n/2 candies, so she can have at most n/2
//    different types.
// 6) Therefore, the answer is:
//         min(number of unique types, n/2)
// 7) Return the answer.
//
// # Complexity Analysis :-
//
// 1) Time Complexity: O(n log n)
// 2) Space Complexity: O(n)
//
// # Program :-

class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int n = candyType.size();

        set<int> types;

        for(int i = 0; i < n; i++){
            types.insert(candyType[i]);
        }

        return min((int)types.size(), n / 2);
    }
};
