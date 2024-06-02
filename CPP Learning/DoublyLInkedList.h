#pragma once
#include<iostream>

namespace DoubleLinkedList{

	class Node {

	public:

		int value;
		Node* prev;
		Node* next;

		Node(int value) {
			this->value = value;
			next = nullptr;
			prev = nullptr;
		};

	};

	class DoublyLL {

	private:
		Node* head;
		Node* tail;
		int length;

	public: 
		DoublyLL();
		DoublyLL(int value);
		void Print();
		void Append(int vlaue);
		void DeleteLast();
		void Prepend(int value);
		void DeleteFirst();
		Node* Get(int index);
		bool Set(int index, int value);
		bool Insert(int index, int value);
		bool Delete(int index);

		void PrintHead() {
			std::cout << head->value << std::endl;
		}

		void PrintTail() {
			std::cout << tail->value << std::endl;
		}

		void PrintLength() {
			std::cout << length << std::endl;
		}

	};



};