#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

#include "LinkedList.h"
#include"DoublyLInkedList.h"
#include"stacks.h"
#include"Tree.h"
#include"HashTable.h"
#include"Graph.h"


using namespace DoubleLinkedList;
using namespace NLinkedList;
using namespace std::literals;

void LinkedListFunc() {
	LinkedList* linkedList = new LinkedList();
	linkedList->Append(10);
	linkedList->Append(20);
	linkedList->Append(30);
	linkedList->Append(50);
	linkedList->Print();

	linkedList->Reverse();
	linkedList->Print();
}

void DoublyLLFunc() {
	DoublyLL* doubly = new DoublyLL();

	doubly->Append(6);
	doubly->Append(7);
	doubly->Append(8);
	doubly->Append(9);
	doubly->Print();

	doubly->Delete(2);
	doubly->Print();
}

void StackFunc() {
	Stack* stack = new Stack(10);
	stack->Push(9);
	stack->Push(8);
	stack->Push(7);
	stack->Push(6);
	stack->Push(5);
	stack->Push(4);

	stack->Print();
}

void BinarySTFunc() {
	BinarySearchTree* tree = new BinarySearchTree();
	tree->Insert(10);
	tree->Insert(5);
	tree->Insert(12);
	tree->Insert(3);

	std::cout << std::boolalpha;
	std::cout << tree->Contians(30) << std::endl;
}

void HashTableFunc() {
	HashTable* hashTable = new HashTable();
	hashTable->Set("Zeeshan", 28);
	hashTable->Set("Naeem", 30);
	std::vector<std::string> keyList = hashTable->Keys();
	std::for_each(keyList.begin(), keyList.end(), [](std::string x) {std::cout << x << std::endl; });

	hashTable->PrintTable();
}

void GraphFunc() {
	Graph* g = new Graph();
	g->AddVertex("V");
	g->AddVertex("A");

	g->AddEdge("V", "A");

	g->PrintGraph();

	g->RemoveVertex("A");
	g->PrintGraph();
}

int main() {

	//LinkedListFunc();
	//DoublyLLFunc();
	//StackFunc();
	//BinarySTFunc();
	//HashTableFunc();
	//GraphFunc();
	


	return 0;
}