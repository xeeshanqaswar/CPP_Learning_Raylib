#pragma once
#include<iostream>

class TNode;

class BinarySearchTree {


public:
	TNode* root;

	BinarySearchTree();
	bool Insert(int value);
	bool Contians(int value);
};

class TNode {

public:
	int value;
	TNode* left;
	TNode* right;

	TNode(int value) {
		this->value = value;
		left = nullptr;
		right = nullptr;
	}
};