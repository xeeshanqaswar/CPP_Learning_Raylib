#include "DoublyLInkedList.h"

using namespace DoubleLinkedList;

DoublyLL::DoublyLL() {
	head = nullptr;
	tail = nullptr;
	length = 0;
}

DoublyLL::DoublyLL(int value) {
	head = new Node(value);
	tail = head;
	length = 1;
}

void DoublyLL::Print() {

	if (length == 0)
		return;

	Node* temp = head;

	std::cout << std::endl << "Printing Doubly LL " << std::endl;

	while (temp!= nullptr)
	{
		std::cout << temp->value << std::endl;
		temp = temp->next;
	}
}

void DoublyLL::Append(int value) {

	Node* newNode = new Node(value);

	if (length == 0)
	{
		head = newNode;
		tail = newNode;
		length++;
		return;
	}

	tail->next = newNode;
	newNode->prev = tail;
	tail = newNode;
	length++;
}

void DoublyLL::Prepend(int value) {

	Node* newNode = new Node(value);

	if (length == 0){
		head = newNode;
		tail = newNode;
	}
	else {
		head->prev = newNode;
		newNode->next = head;
		head = newNode;
	}

	length++;
}

void DoublyLL::DeleteFirst() {
	if (length == 0)
	{
		return;
	}
	else if (length == 1)
	{
		delete(head);
		head = tail = nullptr;
		length = 0;
		return;
	}
	else{

		Node* temp = head->next;
		delete(head);
		temp->prev = nullptr;
		head = temp;
		length--;
	}
}

Node* DoublyLL::Get(int index) {

	if (index < 0 || index>= length)
	{
		return nullptr;
	}
	else {
		
		Node* temp ;

		if (index < length/2)
		{
			temp = head;

			for (size_t i = 0; i < index; i++)
			{
				temp = temp->next;
			}
		}
		else {
			temp = tail;
			for (size_t i = length-1; i > index; i--)
			{
				temp = temp->prev;
			}
		}

		return temp;
	}
}

bool DoublyLL::Set(int index, int value) {

	if (index < 0 || index > length)
	{
		return false;
	}
	
	Node* temp = Get(index);
	temp->value = value;
	return true;

}

bool DoublyLL::Insert(int index, int value) {

	Node* newNode = new Node(value);

	if (index <0 || index > length)
	{
		return false;
	}
	else if (index == length) {
		Append(value);
		return true;
	}
	else {

		Node* point = Get(index);
		newNode->next = point;
		newNode->prev = point->prev;
		point->prev->next = newNode;
		point->prev = newNode;
		length++;
	}

}

bool DoublyLL::Delete(int index) {
	if (index < 0 || index >= length)
	{
		return false;
	}

	Node* temp = Get(index);
	temp->prev->next = temp->next;
	temp->next->prev = temp->prev;
	delete(temp);
	length--;
	return true;
}

void DoublyLL::DeleteLast() {

	if (length = 0)
	{
		return;
	}

	if (length == 1)
	{
		head = tail = nullptr;
		tail = 0;
		length = 0;
		return;
	}

	Node* tailPrevious = tail->prev;
	tailPrevious->next = nullptr;
	tail->prev = nullptr;
	
	delete(tail);

	tail = tailPrevious;
	length--;
}


