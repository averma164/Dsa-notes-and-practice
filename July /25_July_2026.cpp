// # 3536. Maximum Product of Two Digits

// You are given a positive integer n.
// Return the maximum product of any two digits in n.
// Note: You may use the same digit twice if it appears more than once in n.

// # Approach :-

// 1) Initialize an empty vector temp,
// 2) Loop while n > 0
//     - Extract the last digit: num = n % 10
//     - Remove the last digit from n n = n / 10
//     - push num into temp
// 3) Sort temp in ascending order using std::sort
// 4) Identify the two largest digits at the end of temp (at indices k and k-1).
// 5) Return their product.

// # Complexity :-

// - Time Complexity : O(nlogn)
// - Space Complexity : O(n)

// # Program :-

class Solution {
public:
    int maxProduct(int n) {
        vector<int> temp;
        while(n > 0){
            int num = n % 10;
            n = n / 10;
            temp.push_back(num);
        }
        sort(temp.begin(),temp.end());
        int k = temp.size() - 1;
        return temp[k] * temp[k-1];
    }
};
