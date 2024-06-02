#include"LinkedList.h"

using namespace NLinkedList;

LinkedList::LinkedList() {
	length = 0;
	head = nullptr;
	tail = nullptr;
}

LinkedList::LinkedList(int value) {
	head = new Node(value);
	tail = head;
	length++;
};

void LinkedList::Print() {

	std::cout << std::endl << "*** Printing Linked List ***" << std::endl;

	Node* temp = head;
	while (temp != nullptr)
	{
		std::cout << temp->GetValue() << std::endl;
		temp = temp->GetNextNode();
	}
};

void LinkedList::Append(int value) {

	Node* temp = new Node(value);

	if (length == 0)
	{
		head = temp;
		tail = head;
	}
	else {

		tail->SetNextNode(temp);
		tail = temp;
	}

	length++;
};

void LinkedList::DeleteLast() {

	if (length ==0)
		return;

	Node* temp = head;
	while (temp->GetNextNode()->GetNextNode() != nullptr) // tail - 1
	{
		temp = temp->GetNextNode();
	}

	Node* toDelete = tail; //tail
	tail = temp;
	tail->SetNextNode(nullptr);
	delete(toDelete);
	length--;

	if (length == 0)
		head = tail = nullptr;
}

void LinkedList::DeleteFirst() {

	if (length == 0)
		return;

	Node* temp = head;
	if (length == 1)
	{
		head = tail = nullptr;
	}

	head = temp->GetNextNode();
	delete(temp);

	length--;
}

Node* LinkedList::Get(int index) {

	if (index >= length || index < 0) {
		return nullptr;
	}
	else if (index == 0) {
		return head;
	}
	else {
		
		Node* temp = head;
		for (size_t i = 0; i < index; i++)
		{
			temp = temp->GetNextNode();
		}

		return temp;
	}
}

bool LinkedList::Set(int index, int value) {
	
	Node* temp = Get(index);
	if (temp != nullptr)
	{
		temp->SetValue(value);
		return true;
	}
	return false;
}

bool LinkedList::Insert(int index, int value) {

	if (index<0 || index > length)
	{
		false;
	}
	else if (index == 0) {
		PrePend(value);
		return true;
	}
	else if (index == length)
	{
		Append(value);
		return true;
	}
	else{
		Node* newNode = new Node(value);
		Node* temp = Get(index - 1);
		newNode->SetNextNode(temp->GetNextNode());
		temp->SetNextNode(newNode);
		return true;
	}
}

void LinkedList::PrePend(int value) {
	
	Node* temp = new Node(value);
	if (length== 0)
	{
		head = temp;
		tail = head;
	}
	else {
		temp->SetNextNode(head);
		head = temp;
	}

	length++;
}

void LinkedList::Delete(int index) {

	if (index < 0 || index >= length)
	{
		return;
	}

	if (index == 0)
	{
		DeleteFirst();
	}
	else if (index == length - 1) {

		DeleteLast();
	}
	else {
		Node* temp = head;
		for (size_t i = 0; i < index - 1; i++) // Element before Index
		{
			temp = head->GetNextNode();
		}

		Node* indexNode = temp->GetNextNode();
		temp->SetNextNode(indexNode->GetNextNode());
		delete(indexNode);
		length--;
	}
}

void LinkedList::Reverse() {

	if (length == 0)
		return;
	
	Node* temp = head;
	head = tail;
	tail = temp;

	Node* before = nullptr;
	Node* after = tail->GetNextNode();
	
	while (after != nullptr) {
		temp->SetNextNode(before);
		before = temp;
		temp = after;
		after = temp->GetNextNode();
	}
	temp->SetNextNode(before);

}

LinkedList::~LinkedList() {

	Node* temp = head;
	while (head != nullptr)
	{
		head = head->GetNextNode();
		delete(temp);
		temp = head;
	}
};