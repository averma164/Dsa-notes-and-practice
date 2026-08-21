// 1710. Maximum Units on a Truck

// You are assigned to put some amount of boxes onto one truck. You are given a 2D array boxTypes, where boxTypes[i] = [numberOfBoxesi, numberOfUnitsPerBoxi]:
// - numberOfBoxesi is the number of boxes of type i.
// - numberOfUnitsPerBoxi is the number of units in each box of the type i.
// You are also given an integer truckSize, which is the maximum number of boxes that can be put on the truck. You can choose any boxes to put on the truck as long as the number of boxes does not exceed truckSize.
// Return the maximum total number of units that can be put on the truck.

// # Approach :-

// 1) Use a Greedy strategy by prioritizing boxes with the highest number of units per box.
// 2) Sort the 2D vector `boxTypes` in descending order based on the units per box (index 1).
// 3) Initialize `totalUnits = 0` to accumulate the result.
// 4) Iterate through each box type:
//      - Calculate the number of boxes to take: min(box[0], truckSize).
//      - Add (boxesToTake * box[1]) to `totalUnits`.
//      - Decrement `truckSize` by `boxesToTake`.
//      - If `truckSize == 0`, break early as the truck is fully loaded.
// 5) Return `totalUnits`.

// # Complexity :-

// - Time Complexity: O(n log n)
//      Sorting the `boxTypes` array of size n takes O(n log n) time.
//      The subsequent linear scan takes O(n) time.
// - Space Complexity: O(1)
//      Sorting is performed in-place using O(1) auxiliary space (excluding recursion stack space of sort).

// # Program :-

class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] > b[1];
        });

        int totalUnits = 0;

        for (auto& box : boxTypes) {
            int boxesToTake = min(box[0], truckSize);
            totalUnits += boxesToTake * box[1];
            truckSize -= boxesToTake;

            if (truckSize == 0) break;
        }

        return totalUnits;
    }
};
