/*
Given a string A consisting only of '(' and ')'.

You need to find whether parantheses in A is balanced or not ,if it is balanced then return 1 else return 0.
*/

#include <stack>
using namespace std;

int Solution::solve(string A)
{
    stack<char> st;

    for (char c : A)
    {
        if (c == '(')
        {
            st.push(c);
        }
        else if (c == ')')
        {
            if (st.empty() || st.top() != '(')
            {
                return 0;
            }
            st.pop();
        }
    }

    return st.empty() ? 1 : 0;
}

int isBST(struct node* root)
{
    static struct node* prev = NULL;

    if(root != NULL)
    {
        if(!isBST(root->left))
        {
            return 0;
        }
        if(prev != NULL && root->data <= prev->data)
        {
            return 0;
        }
        prev = root;
        return isBST(root->right);
    }
    else
    {
        return 1;
    }
}