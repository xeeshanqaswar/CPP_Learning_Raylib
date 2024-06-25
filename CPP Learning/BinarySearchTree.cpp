#include"Tree.h"
#include<queue>
#include<stack>

BinarySearchTree::BinarySearchTree() {
	root = nullptr;
}

bool BinarySearchTree::Insert(int value) {

	TNode* newNode = new TNode(value);
	if (root == nullptr)
	{
		root = newNode;
		return true;
	}

	TNode* temp = root;

	while (true) {

		if (temp->value == value)
		{
			return false;
		}

		if (value > temp->value)
		{
			if (temp->right != nullptr)
			{
				temp = temp->right;
			}
			else {
				temp->right = newNode;
				return true;
			}
		}
		else
		{
			if (temp->left != nullptr) {
				temp = temp->left;
			}
			else {
				temp->left = newNode;
				return true;
			}
		}
	}

};

bool BinarySearchTree::Contians(int value) {

	if (root == nullptr)
	{
		return false;
	}

	TNode* temp = root;
	while (temp)
	{
		if (value > temp->value)
		{
			temp = temp->right;
		}
		else if (value < temp->value) 
		{
			temp = temp->left;
		}
		else 
		{
			return true;
		}
	}

	return false;
}

void BinarySearchTree::BreathFirstSearch() {
	
	std::queue<TNode*> myQueue;
	myQueue.push(root);

	while (myQueue.size() > 0)
	{
		TNode* currentNode = myQueue.front();
		myQueue.pop();
		std::cout << currentNode->value << " ";
		
		if (currentNode->left != nullptr)
		{
			myQueue.push(currentNode->left);
		} 

		if (currentNode->right != nullptr)
		{
			myQueue.push(currentNode->right);
		}
	}
}

void BinarySearchTree::DFSPreOrder() {
	DFSPreOrder(root);
}

void BinarySearchTree::DFSPreOrder( TNode* root) {

	std::cout << root->value << std::endl;

	if (root->left != nullptr)
		DFSPreOrder(root->left);

	if (root->right != nullptr)
		DFSPreOrder(root->right);
}

void BinarySearchTree::DFSPostOrder() {
	DFSPostOrder(root);
}

void BinarySearchTree::DFSPostOrder(TNode* root) {
	
	if (root->left != nullptr)
	{
		DFSPostOrder(root->left);
	}

	if (root->right != nullptr)
	{
		DFSPostOrder(root->right);
	}

	std::cout << root->value <<" ";
}

void BinarySearchTree::DFSInOrder() {
	DFSInOrder(root);
}

void BinarySearchTree::DFSInOrder(TNode* root) {

	if (root->left != nullptr)
	{
		DFSInOrder(root->left);
	}
	
	std::cout << root->value << " ";

	if (root->right != nullptr)
	{
		DFSInOrder(root->right);
	}
}