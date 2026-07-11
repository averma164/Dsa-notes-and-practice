// # 1423. Maximum Points You Can Obtain from Cards

// There are several cards arranged in a row, and each card has an associated number of points. The points are given in the integer array cardPoints.
// In one step, you can take one card from the beginning or from the end of the row. You have to take exactly k cards.
// Your score is the sum of the points of the cards you have taken.
// Given the integer array cardPoints and the integer k, return the maximum score you can obtain.

// # Approach :-

// Since we can only pick cards from the beginning or the end of the array, every valid selection consists of:
// - taking i cards from the left, and
// - taking k - i cards from the right.
// 1) Compute the sum of the first k cards (lsum).
// 2) Initialize maxSum with this value.
// 3) Start from the last element of the array.
// 4) Repeat k times:
//     - Remove one card from the left sum.
//     - Add one card from the right sum.
//     - Update the maximum score.
// 5) Return the maximum score.

// # Complexity :-

// - Time Complexity : O(k)
// - Space Complexity : O(1)

// # Program :-

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int lsum = 0;
        int rsum = 0;
        int maxSum = 0;
        for(int i=0; i<k; i++){
            lsum = lsum + cardPoints[i];
        }
        maxSum = lsum;
        int ridx = cardPoints.size() - 1;
        for(int i=k-1; i>=0; i--){
            lsum = lsum - cardPoints[i];
            rsum = rsum + cardPoints[ridx];
            ridx--;
            maxSum = max(maxSum, lsum+rsum);
        }
        return maxSum;
    }
};
