// # 322. Coin Change

// You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.
// Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.
// You may assume that you have an infinite number of each kind of coin.

// # Approach :-

// Let dp[i] = minimum number of coins needed to make amount i.
// 1) Initialize all values to a large number (amount + 1).
// 2) dp[0] = 0 because 0 coins are needed for amount 0.
// 3) For every amount from 1 to amount, try every coin:
//     - If the coin can be used (coin <= i), update:
//     - dp[i] = min(dp[i], dp[i - coin] + 1)
// 4) If dp[amount] is still amount + 1, return -1.

// # Complexity :-

// - Time Complexity : O(amount × number_of_coins)
// - Space Complexity : O(amount)

// # Program :-

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount+1);
        dp[0] = 0;
        for(int i=1; i<=amount; i++){
            for(int coin : coins){
                if(coin <= i){
                    dp[i] = min(dp[i], dp[i-coin] + 1);
                }
            }
        }
        return (dp[amount] == amount + 1) ? -1 : dp[amount];
    }
};
