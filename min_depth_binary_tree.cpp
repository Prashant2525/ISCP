/*
Given a binary tree, find its minimum depth.
The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
NOTE: The path has to end on a leaf node.
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
int Solution::minDepth(TreeNode *A)
{
    if (A == NULL)
    {
        return 0;
    }
    if (A->left == NULL && A->right == NULL)
    {
        return 1;
    }
    int left_depth = INT_MAX, right_depth = INT_MAX;

    if (A->left)
    {
        left_depth = minDepth(A->left);
    }
    if (A->right)
    {
        right_depth = minDepth(A->right);
    }

    return min(left_depth, right_depth) + 1;
}


