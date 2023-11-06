#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} Node;

// Function to create a new node
Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node in BST
Node *insertNode(Node *root, int data)
{
    if (root == NULL)
    {
        return createNode(data);
    }
    else if (data <= root->data)
    {
        root->left = insertNode(root->left, data);
    }
    else
    {
        root->right = insertNode(root->right, data);
    }
    return root;
}

// Function to search for a node in BST
Node *searchNode(Node *root, int data)
{
    if (root == NULL || root->data == data)
    {
        return root;
    }
    else if (data < root->data)
    {
        return searchNode(root->left, data);
    }
    else
    {
        return searchNode(root->right, data);
    }
}

// Function to find the minimum element in BST
Node *findMin(Node *root)
{
    if (root == NULL)
    {
        return NULL;
    }
    else if (root->left == NULL)
    {
        return root;
    }
    else
    {
        return findMin(root->left);
    }
}

// Function to delete a node from BST
Node *deleteNode(Node *root, int data)
{
    if (root == NULL)
    {
        return root;
    }
    else if (data < root->data)
    {
        root->left = deleteNode(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = deleteNode(root->right, data);
    }
    else
    {
        // Case 1: No child or 1 child
        if (root->left == NULL)
        {
            Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root->left;
            free(root);
            return temp;
        }
        // Case 2: 2 children
        Node *temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Function to traverse the tree in inorder
void inorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main()
{
    Node *root = NULL;
    int data;
    char choice;

    do
    {
        printf("Enter data to insert: ");
        scanf("%d", &data);
        root = insertNode(root, data);

        printf("Do you want to insert another node? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    printf("Inorder traversal: ");
    inorder(root);
    printf("\n");

    printf("Enter data to delete: ");
    scanf("%d", &data);
    root = deleteNode(root, data);

    printf("Inorder traversal after deletion: ");
    inorder(root);
    printf("\n");

    return 0;
}


