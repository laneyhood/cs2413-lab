#include <stdbool.h>
#include <stddef.h>

/*
Question 2: Symmetric Tree

Given the root of a binary tree, check whether it is symmetric
around its center.

A tree is symmetric if the left subtree is a mirror reflection
of the right subtree.

Examples:

Example 1:
Input:
        1
       / \
      2   2
     / \ / \
    3  4 4  3
Output: true

Example 2:
Input:
        1
       / \
      2   2
       \   \
       3    3
Output: false

Function to complete:
    bool isSymmetric(struct TreeNode* root);

Note:
- An empty tree is considered symmetric.
- You should compare the left subtree and right subtree
  as mirror images.
*/

/*
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool isMirror(struct TreeNode* left, struct TreeNode* right)
{
  // If both are null, you have reached the end, and they are mirrors
  if(left == NULL && right == NULL) return true;

  // If one or the other are null (but not both), then they cannot be mirrors (one branch has greater depth than the other)
  if(left == NULL || right == NULL) return false;

  // Check whether current values are equal--if not, return false
  if(left->val != right->val) return false;

  // Otherwise, do recursive calls
  bool outer_check = isMirror(left->left, right->right);
  bool inner_check = isMirror(left->right, right->left);

  // If both outer and inner branches are mirrors of each other, return true
  if(outer_check && inner_check) return true;

  return false;
}

bool isSymmetric(struct TreeNode* root) {
    // TODO: implement
    if(root == NULL)
    {
      return true;
    }
    
    return isMirror(root->left, root->right);
}