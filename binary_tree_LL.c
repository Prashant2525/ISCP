#include <stdio.h>
#include <stdlib.h>

struct linked_list
{
  int data;
  struct linked_list *left, *right;
};

typedef struct linked_list node;
node *create();
void inorder(node *root);
void preorder(node *root);
void postorder(node *root);

void main()
{
  node *root;
  root = create();
  printf("Traversal of the inserted binary tree \n");
  printf("Inorder traversal \n");
  inorder(root);
  printf("\nPreorder traversal \n");
  preorder(root);
  printf("\nPostorder traversal \n");
  postorder(root);
}

node *create()
{
  node *temp;
  int item, choice;
  temp = (node *)malloc(sizeof(node));
  printf("\nPress 0 to exit");
  printf("\nPress 1 for new node\n");
  printf("\nEnter your choice : ");
  scanf("%d", &choice);
  if (choice == 0)
  {
    return 0;
  }
  else if (choice == 1)
  {
    printf("Enter the data:");
    scanf("%d", &item);
    temp->data = item;
    printf("Enter the left child of %d", item);
    temp->left = create();
    printf("Enter the right child of %d", item);
    temp->right = create();
     
  }
}

void inorder(node *root)
{
  if (root == NULL)
    return;
  inorder(root->left);
  printf("%d ", root->data);
  inorder(root->right);
}

void preorder(node *root)
{
  if (root == NULL)
    return;
  printf("%d ", root->data);
  preorder(root->left);
  preorder(root->right);
}

void postorder(node *root)
{
  if (root == NULL)
    return;
  postorder(root->left);
  postorder(root->right);
  printf("%d ", root->data);
}
