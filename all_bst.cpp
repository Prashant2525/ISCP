#include <iostream>
#include <cstdlib>
using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
};
typedef struct node node;

node *create_node(int data)
{
    node *newnode = new node;
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;

    return newnode;
}

node *insert_node(node *root, int data)
{
    if (root == NULL)
    {
        return create_node(data);
    }
    else if (data <= root->data)
    {
        root->left = insert_node(root->left, data);
    }
    else
    {
        root->right = insert_node(root->right, data); // Corrected this line
    }

    return root;
}

void inorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

int max_depth(node* root)
{
    if(root == NULL)
    {
        return 0;
    }
    int left_depth = max_depth(root->left);
    int right_depth = max_depth(root->right);

    if(left_depth > right_depth)
    {
        return (left_depth + 1);
    }
    else
    {
        return (right_depth + 1);
    }
}

int min_depth(node* root)
{
    if(root == NULL)
    {
        return 0;
    }
    int left_depth = min_depth(root->left);
    int right_depth = min_depth(root->right);

    if(left_depth == 0) return right_depth + 1;
    if(right_depth == 0) return left_depth + 1;

    return min(left_depth, right_depth) + 1;
}

bool path_sum(node* root, int sum)
{
    if(root == NULL)
    {
        return 0;
    }
    bool ans = 0;

    int subsum = sum - root->data;

    if(subsum == 0 && root->left == NULL && root->right == NULL)
    {
        return 1;
    }

    if(root->left)
    {
        ans = ans || path_sum(root->left, subsum);
    }
    if(root->right)
    {
        ans = ans || path_sum(root->right, subsum);
    }

    return ans;
}

int main()
{
    node *root = NULL;
    int data;
    int ch;

    while (1)
    {
        cout << "\nEnter choice:" << endl;
        cout << "1. Add data\n2. Max Depth\n3. Min Depth\n4. Display \n5. Path Sum \n10. Exit" << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "Enter any data: ";
            cin >> data;
            root = insert_node(root, data);
            break;
        case 2:
            cout << "Maximum Depth: " << max_depth(root) << endl;
            break;
        case 3:
            cout << "Minimum Depth: " << min_depth(root) << endl;
            break;
        case 4:
            cout << "Inorder Traversal:" << endl;
            inorder(root);
            cout << endl;
            break;
        case 5:
            int sum;
            cout<<"Enter sum you want: ";
            cin>>sum;
            cout<<path_sum(root, sum);
        case 10:
            exit(0);
            break;
        default:
            cout << "Invalid Input" << endl;
            break;
        }
    }

    // Clean up: You should free the allocated memory for the nodes here to avoid memory leaks.
    // This can be done by writing a separate function or destructor for tree cleanup.
    // For a quick cleanup, you can do a post-order traversal and delete nodes.
    // However, be cautious when applying this approach in a larger codebase, as it may not be efficient.
    // For a complete cleanup, it's better to implement proper memory management.
    // For example, you can create a function to free all the nodes and call it before exiting the program.
    // Here's an example of a simple cleanup function:
    /*
    void cleanup_tree(node* root) {
        if (root == nullptr) return;
        cleanup_tree(root->left);
        cleanup_tree(root->right);
        delete root;
    }
    cleanup_tree(root);
    */

    return 0;
}
