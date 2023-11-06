//Symmetric Tree (Mirror Image of itself)

//----------------------------------------Approach 1----------------------------------------

// C++ program to check if a given Binary Tree is symmetric
// or not
#include <bits/stdc++.h>
using namespace std;

// A Binary Tree Node
struct Node {
	int key;
	struct Node *left, *right;
};

// Utility function to create new Node
Node* newNode(int key)
{
	Node* temp = new Node;
	temp->key = key;
	temp->left = temp->right = NULL;
	return (temp);
}

// Returns true if trees with roots as root1 and root2 are
// mirror
bool isMirror(struct Node* root1, struct Node* root2)
{
	// If both trees are empty, then they are mirror images
	if (root1 == NULL && root2 == NULL)
		return true;

	// For two trees to be mirror images, the following
	// three conditions must be true
	// 1.) Their root node's key must be same
	// 2.) left subtree of left tree and right subtree of
	// right tree have to be mirror images
	// 3.) right subtree of left tree and left subtree of
	// right tree have to be mirror images
	if (root1 && root2 && root1->key == root2->key)
		return isMirror(root1->left, root2->right)
			&& isMirror(root1->right, root2->left);

	// if none of above conditions is true then root1
	// and root2 are not mirror images
	return false;
}

// Returns true if a tree is symmetric i.e. mirror image of itself
bool isSymmetric(struct Node* root)
{
	// Check if tree is mirror of itself
	return isMirror(root, root);
}

// Driver code
int main()
{
	// Let us construct the Tree shown in the above figure
	Node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(2);
	root->left->left = newNode(3);
	root->left->right = newNode(4);
	root->right->left = newNode(4);
	root->right->right = newNode(3);

	if (isSymmetric(root))
		cout << "Symmetric";
	else
		cout << "Not symmetric";
	return 0;
}


//----------------------------------------Approach 2----------------------------------------

// C++ program to check if a given Binary Tree is symmetric
// or not
#include <bits/stdc++.h>
using namespace std;

// A Binary Tree Node
struct Node {
	int key;
	struct Node *left, *right;
};

// Utility function to create new Node
Node* newNode(int key)
{
	Node* temp = new Node;
	temp->key = key;
	temp->left = temp->right = NULL;
	return (temp);
}

// Returns true if a tree is symmetric i.e. mirror image of
// itself
bool isSymmetric(Node* root){
	// If the root is null, then the binary tree is
	// symmetric.
	if (root == NULL) {
		return true;
	}

	// Create a stack to store the left and right subtrees
	// of the root.
	stack<Node*> stack;
	stack.push(root->left);
	stack.push(root->right);

	// Continue the loop until the stack is empty.
	while (!stack.empty()) {
		// Pop the left and right subtrees from the stack.
		Node* node1 = stack.top();
		stack.pop();
		Node* node2 = stack.top();
		stack.pop();

		// If both nodes are null, continue the loop.
		if (node1 == NULL && node2 == NULL) {
			continue;
		}

		// If one of the nodes is null, the binary tree is
		// not symmetric.
		if (node1 == NULL || node2 == NULL) {
			return false;
		}

		// If the values of the nodes are not equal, the
		// binary tree is not symmetric.
		if (node1->key != node2->key) {
			return false;
		}

		// Push the left and right subtrees of the left and
		// right nodes onto the stack in the opposite order.
		stack.push(node1->left);
		stack.push(node2->right);
		stack.push(node1->right);
		stack.push(node2->left);
	}

	// If the loop completes, the binary tree is symmetric.
	return true;
}

// Driver code
int main()
{
	// Let us construct the Tree shown in the above figure
	Node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(2);
	root->left->left = newNode(3);
	root->left->right = newNode(4);
	root->right->left = newNode(4);
	root->right->right = newNode(3);

	if (isSymmetric(root))
		cout << "Symmetric";
	else
		cout << "Not symmetric";
	return 0;
}

// This code is contributed by sramshyam

//----------------------------------------Approach 3----------------------------------------

// C++ code to implement the iterative approach using a
// queue
#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	struct Node* left;
	struct Node* right;
	Node(int val)
	{
		data = val;
		left = NULL;
		right = NULL;
	}
};

bool isSymmetric(struct Node* root)
{
	if (root == NULL) {
		return true;
	}

	queue<Node*> q;
	q.push(root);
	q.push(root);

	while (!q.empty()) {
		Node* leftNode = q.front();
		q.pop();
		Node* rightNode = q.front();
		q.pop();

		// If both leftNode and rightNode are NULL, continue
		// to the next iteration
		if (leftNode == NULL && rightNode == NULL) {
			continue;
		}

		// If either leftNode or rightNode is NULL or their
		// data is not equal, return false
		if (leftNode == NULL || rightNode == NULL
			|| leftNode->data != rightNode->data) {
			return false;
		}

		// Pushing the left and right nodes of the current
		// node into the queue
		q.push(leftNode->left);
		q.push(rightNode->right);
		q.push(leftNode->right);
		q.push(rightNode->left);
	}
	return true;
}
// Driver Code
int main()
{
	// Creating a binary tree
	struct Node* root = new Node(5);
	root->left = new Node(1);
	root->right = new Node(1);
	root->left->left = new Node(2);
	root->right->right = new Node(2);

	// Checking if the binary tree is symmetric or not
	if (isSymmetric(root)) {
		cout << "The binary tree is symmetric\n";
	}
	else {
		cout << "The binary tree is not symmetric\n";
	}

	return 0;
}
// This Code is contributed by Veerendra_Singh_Rajpoot
