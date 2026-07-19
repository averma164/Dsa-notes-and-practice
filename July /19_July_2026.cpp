// # 124. Binary Tree Maximum Path Sum

// A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. A node can only appear in the sequence at most once.
// Note that the path does not need to pass through the root.
// The path sum of a path is the sum of the node's values in the path.
// Given the root of a binary tree, return the maximum path sum of any non-empty path.

// # Approach :-

// For every node:
// 1) Compute maximum gain from left subtree.
// 2) Compute maximum gain from right subtree.
// 3) Ignore negative gains.
// 4) Update global answer:
//     - left + node + right
// 6) Return
//     - node + max(left,right)

// # Complexity :-

// - Time Complexity : O(n) (each node is visited once)
// - Space Complexity: O(h) for the recursion stack, where h is the height of the tree (O(n) in the worst case, O(log n) for a balanced tree).

// # Program :-

class Solution {
public:
    int ans = INT_MIN;
    int solve(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        int left = max(0,solve(root->left));
        int right = max(0,solve(root->right));
        ans = max(ans, left + right + root->val);
        return root->val + max(left, right);
    }
    int maxPathSum(TreeNode* root) {
        solve(root);
        return ans;
    }
};
