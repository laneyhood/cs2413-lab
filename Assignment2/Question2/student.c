/*
 * Assignment 2 / Question 2 / student.c
 * ------------------------------------------------------------
 * Check if a BST is an AVL tree
 *
 * Implement:
 *   bool isAVL(struct TreeNode* root);
 *
 * AVL (for this assignment) means:
 * 1) strict BST property (no duplicates)
 * 2) height-balanced: abs(height(left) - height(right)) <= 1 at every node
 *
 * Rules:
 * - Do NOT allocate new nodes.
 * - Do NOT modify the tree.
 * - Do NOT print anything.
 *
 * Build/Run (from Assignment2 folder):
 *   make run2
 */

#include <stdbool.h>
#include <stddef.h>
#include <limits.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int height(struct TreeNode* root, long min, long max)
{
    // Base case: leaf nodes have height 0
    if(root == NULL)
    {
        // 1 + max(-1, -1) = height 0
        return -1;
    }

    // Return -999 if BST violation
    if(root->val <= min || root->val >= max)
    {
        return -999;
    }

    // Recursion
    int left, right;
    left = height(root->left, min, (long) root->val);
    if(left == -999) return -999;
    right = height(root->right, (long) root->val, max);
    if(right == -999) return -999;

    // Check for unbalance
    if(abs(left - right) > 1)
    {
        return -999;
    }
    
    int max_height = left > right ? left : right;

    return 1 + max_height;

    //return -1;
}

bool isAVL(struct TreeNode* root) {
    // TODO: implement
    // Hint: One common O(n) approach:
    // - Use a recursive helper that returns the subtree height,
    //   and returns -1 if subtree is invalid (BST violation or unbalanced).

    // If root is null, tree is empty and is therefore balanced
    if(root == NULL)
    {
        return true;
    }

    // Calculate heights of left and right subtrees
    int left_height = height(root->left, LONG_MIN, (long) root->val);
    int right_height = height(root->right, (long) root->val, LONG_MAX);

    // Check if height function returns large negative for BST violation or unbalanced tree
    if(left_height < -1 || right_height < -1)
    {
        return false;
    }
    // If entire tree is unbalanced, return false
    else if(abs(left_height - right_height) > 1)
    {
        return false;
    }
    // Otherwise, tree is an AVL
    else
    {
        return true;
    }

    (void)root;
    return false;
}
