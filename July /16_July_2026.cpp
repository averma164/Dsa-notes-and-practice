// # 199. Binary Tree Right Side View

// Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

// # Approach :-

// We use Depth-First Search (DFS) with a right-first traversal.
// 1) Create an empty vector ans.
// 2) Define a recursive function helper(node, level):
//     - If node is NULL, return.
//     - If level == ans.size(), append node->val to ans.
//     - Recursively call helper for the right child with level + 1.
//     - Recursively call helper for the left child with level + 1.
// 3) Call helper(root, 0).
// 4) Return ans.

// # Complexity :-

// - Time Complexity : O(n)
//     - where n is the number of nodes.
//     - Each node is visited exactly once.
// - Space Complexity : O(h)
//     - where h is the height of the tree (recursive call stack).
//     - Balanced tree: O(log n)
//     - Skewed tree: O(n)

// # Program :-

class Solution {
public:
    void helper(vector<int>& ans,int level, TreeNode* root){
        if(root == NULL){
            return;
        }
        if(level == ans.size()){
            ans.push_back(root->val);
        }

        helper(ans, level +1, root->right);
        helper(ans, level +1, root->left);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        helper(ans, 0, root);
        return ans;
    }
};
