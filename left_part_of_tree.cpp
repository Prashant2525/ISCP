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


vector<int> leftView(Node *root)
{
    stack<int>s;
    
    if(root == NULL)
    {
        return 0;
    }
    while(!leftView(root->left))
    {
        s.push(root->left->data);
    }
}