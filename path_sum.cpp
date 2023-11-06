/*
Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.
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
int Solution::hasPathSum(TreeNode *A, int B)
{
    if (A == NULL)
        return 0;

    bool ans = 0;

    int subSum = B - A->val;

    if (subSum == 0 && A->left == NULL && A->right == NULL)
        return 1;

    if (A->left)
        ans = ans || hasPathSum(A->left, subSum);
    if (A->right)
        ans = ans || hasPathSum(A->right, subSum);

    return ans;
}
