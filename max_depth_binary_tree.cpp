/*
Given a binary tree, find its maximum depth.

The maximum depth of a binary tree is the number of nodes along the longest path from the root node down to the farthest leaf node.
*/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

int Solution::maxDepth(TreeNode *A)
{

    if (A == NULL)
    {
        return 0;
    }

    int left_depth = maxDepth(A->left);
    int right_depth = maxDepth(A->right);

    if (left_depth > right_depth)
    {
        return (left_depth + 1);
    }
    else
    {
        return (right_depth + 1);
    }
}
