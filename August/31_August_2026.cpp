// # 2058. Find the Minimum and Maximum Number of Nodes Between Critical Points

// A critical point in a linked list is defined as either a local maxima or a local minima.
// - A node is a local maxima if the current node has a value strictly greater than the previous node and the next node.
// - A node is a local minima if the current node has a value strictly smaller than the previous node and the next node.
// Note that a node can only be a local maxima/minima if there exists both a previous node and a next node.
// Given a linked list head, return an array of length 2 containing [minDistance, maxDistance] where minDistance is the minimum distance between any two distinct critical points and maxDistance is the maximum distance between any two distinct critical points. If there are fewer than two critical points, return [-1, -1].

// # Approach :-

// 1) Traverse the linked list starting from the second node while maintaining references to the previous node (`prev`), current node (`curr`), and next node (`curr->next`), along with a 1-based index position tracker (`pos`).
// 2) Check if `curr` is a critical point:
//      - Local Maxima: `curr->val > prev->val` and `curr->val > curr->next->val`
//      - Local Minima: `curr->val < prev->val` and `curr->val < curr->next->val`
// 3) Track the critical points using three variables:
//      - `first`: The index of the very first critical point encountered.
//      - `last`: The index of the most recently encountered critical point.
//      - `minDist`: The running minimum distance between adjacent critical points (`pos - last`).
// 4) If fewer than two critical points are found (`first == -1` or `first == last`), return `[-1, -1]`.
// 5) Otherwise, compute `maxDist = last - first` and return `{minDist, maxDist}`.

// # Complexity :-

// - Time Complexity: O(n)
//      A single traversal over the linked list of length n to detect all critical points.
// - Space Complexity: O(1)
//      Only pointer references and integer tracking variables are used, requiring constant auxiliary space.

// # Program :-

class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans = {-1, -1};
        ListNode* prev = head;
        ListNode* curr = head->next;
        int pos = 1; 
        int first = -1; 
        int last = -1; 
        int minDist = INT_MAX;   

        while (curr->next != nullptr) {
            if ((curr->val > prev->val && curr->val > curr->next->val) || 
                (curr->val < prev->val && curr->val < curr->next->val)) {
                
                if (first == -1) {
                    first = pos;
                } else {
                    minDist = min(minDist, pos - last);
                }
                last = pos;
            }
            prev = curr;
            curr = curr->next;
            pos++;
        }

        if (first == -1 || first == last) {
            return ans;
        }

        int maxDist = last - first;
        return {minDist, maxDist};
    }
};
