// # 2264. Largest 3-Same-Digit Number in String

// You are given a string num representing a large integer. An integer is good if it meets the following conditions:
// It is a substring of num with length 3.
// It consists of only one unique digit.
// Return the maximum good integer as a string or an empty string "" if no such integer exists.

// # Approach :-

// 1) Initialize maxi = '0'.
// 2) Iterate through the string from index 2.
// 3) If three consecutive digits are equal:
//    - Update maxi with the larger digit.
// 4) If maxi is still '0' and "000" doesn't exist, return "".
// 5) Otherwise, return a string containing maxi repeated three times.

// # Complexity :-

// - Time Complexity: O(n) (single pass, plus find("000") which is also O(n))
// - Space Complexity: O(1)

// # Program :-

class Solution {
public:
    string largestGoodInteger(string num) {
        char maxi = '0';
        for(int i=2;i<num.size();i++){
            if(num[i]==num[i-1] && num[i]==num[i-2]){
                maxi = max(maxi, num[i]);
            }
        }
        if(maxi=='0' && num.find("000")==string::npos){
            return "";
        }
        string ans="";
        for(int i=0;i<3;i++){
            ans += maxi;
        }
        return ans;
    }
};
