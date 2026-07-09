# 114. Flatten Binary Tree to Linked List

Given the root of a binary tree, flatten the tree into a "linked list":
The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer is always null.
The "linked list" should be in the same order as a pre-order traversal of the binary tree.

# Approach:-

1) If the current node is NULL, return.
2) Recursively flatten the right subtree.
3) Recursively flatten the left subtree.
4) Set the current node's left pointer to NULL.
5) Connect the current node's right pointer to nextRight (the previously processed node).
6) Update nextRight to point to the current node.
7) After the recursion finishes, the tree is flattened into a right-skewed linked list following preorder (Root → Left → Right).

# Complexity :-

- Time Complexity: O(n) — each node is visited exactly once.
- Space Complexity: O(h) due to the recursion stack, where h is the height of the tree.
    - Balanced tree: O(log n)
    - Skewed tree: O(n)

# Program :-

class Solution {
public:
    TreeNode* nextRight = NULL;
    void flatten(TreeNode* root) {
        if(root ==  NULL) return;
        flatten(root->right);
        flatten(root->left);
        root->left = NULL;
        root->right = nextRight;
        nextRight = root;
    }
};
