#include"Tree.h"

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