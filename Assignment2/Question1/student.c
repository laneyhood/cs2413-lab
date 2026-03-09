/*
 * Assignment 2 / Question 1 / student.c
 * ------------------------------------------------------------
 * Search in a Binary Search Tree (BST)
 *
 * Implement:
 *   struct TreeNode* bstSearch(struct TreeNode* root, int target);
 *
 * Rules:
 * - Return a pointer to the node with value == target, else NULL.
 * - Do NOT allocate new nodes.
 * - Do NOT modify the tree.
 * - Do NOT print anything.
 *
 * Build/Run (from Assignment2 folder):
 *   make run1
 */

#include <stddef.h>  // NULL

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* bstSearch(struct TreeNode* root, int target) {
    // TODO: implement
    // Hint: Use the BST property to decide whether to go left or right.

    // Edge cases

    // Base case: return null if root is null, return root if target has been found
    if(root == NULL || root->val == target)
    {
        return root;
    }
    // else if(root->left == NULL && root->right == NULL)
    // {
    //     // If you have reached a leaf node without finding target, return NULL
    //     return NULL;
    // }
    // Recursively search left subtree
    else if(target < root->val)
    {
        return bstSearch(root->left, target);
    }
    // Recursively search right subtree
    else
    {
        return bstSearch(root->right, target);
    }

    (void)root;
    (void)target;
    return NULL;
}
