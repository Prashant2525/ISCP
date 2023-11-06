/*
Given two binary trees, write a function to check if they are equal or not.

Two binary trees are considered equal if they are structurally identical and the nodes have the same value.

Return  0 / 1  ( 0 for false, 1 for true ) for this problem
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
int Solution::isSameTree(TreeNode* A, TreeNode* B) 
{
    if(A == NULL and B == NULL)
    {
        return 1;
    }
    else if(A == NULL || B == NULL)
    {
        return 0;
    }
    else if(A->val == B->val && isSameTree(A->left, B->left) && isSameTree(A->right, B->right))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
