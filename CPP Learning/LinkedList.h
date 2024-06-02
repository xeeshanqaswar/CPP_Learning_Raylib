#pragma once
#include<iostream>

namespace NLinkedList{

	class Node;

	class LinkedList {

	private:
		Node* head;
		Node* tail;
		int length;

	public:
		LinkedList();
		LinkedList(int value);
		void Print();
		void Append(int value);
		void DeleteLast();
		void DeleteFirst();
		Node* Get(int index);
		bool Set(int index, int value);
		void PrePend(int value);
		bool Insert(int index, int value);
		void Delete(int index);
		void Reverse();
		int GetLength() {
			return length;
		}
		~LinkedList();
	};

	class Node {

		int value;
		Node* next;

	public:

		Node(int value) {
			this->value = value;
			next = nullptr;
		};

		Node* GetNextNode() {
			return next;
		};

		void SetNextNode(Node* node) {
			next = node;
		};

		int GetValue() {
			return value;
		};

		void SetValue(int value) {
			this->value = value;
		}

	};
};