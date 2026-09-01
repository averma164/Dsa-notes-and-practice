// # 1823. Find the Winner of the Circular Game 
 
// There are n friends sitting in a circle and numbered from 1 to n.
// Starting from the 1st friend, every kth friend is eliminated.
// The counting continues from the friend immediately clockwise of the
// friend who was just eliminated.
// Return the number of the last remaining friend.
 
// # Approach :-
// We simulate the circular game using a vector.
// The helper function keeps track of the current index and recursively
// removes the kth friend until only one friend remains.
 
// 1) Initialize the vector with friends numbered from 1 to n.
// 2) Start the index from 0, representing the 1st friend.
// 3) Calculate the index of the friend to remove using:
//         idx = (idx + k - 1) % person.size()
// 4) Remove the friend at the calculated index.
// 5) Continue the recursion from the same index because after deletion,
//    the next friend moves into the current index.
// 6) When only one friend remains, return that friend.
// 7) Return the winner.
 
// # Complexity Analysis :- 
 
// 1) Time Complexity: O(n²)
// 2) Space Complexity: O(n)
 
// # Program :-
 
class Solution {
public:
    int helper(vector<int>& person, int k, int idx){
        if(person.size() == 1){
            return person[0];
        }
        idx = ((idx + k - 1) % person.size());
        person.erase(person.begin() + idx);
        return helper(person,k, idx);
    }
    int findTheWinner(int n, int k) {
        int idx = 0;
        vector<int> person;
        for(int i=1; i<=n;i++){
            person.push_back(i);
        }
        return helper(person,k,idx);
    }
};
