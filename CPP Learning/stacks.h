#pragma once
#include<iostream>

class SNode;

class Stack {

	int length;
	SNode* top;
public:
	Stack();
	Stack(int value);
	void Push(int value);
	SNode* Pop();
	void Print();
	void PrintLength() {
		std::cout << length << std::endl;
	}
	~Stack();

};

class SNode {

	int value;
	SNode* next;
public:
	SNode(int value	) {
		this->value = value;
		next = nullptr;
	}

	void SetNode(SNode* n) {
		next = n;
	}

	int GetValue() {
		return this->value;
	}

	SNode* GetNextNode() {
		return next;
	}

};