#include "stacks.h"

Stack::Stack(int value) {
	
	top = new SNode(value);
	length = 1;
}

void Stack::Push(int value) {

	SNode* newNode = new SNode(value);

	if (length == 0)
	{
		top = newNode;
		length = 1;
		return;
	}

	newNode->SetNode(top);
	top = newNode;
	length++;
	return;
}

SNode* Stack::Pop() {

	if (length == 0)
		return nullptr;

	SNode* temp = top;
	top = temp->GetNextNode();
	length--;
	return temp;
}

void Stack::Print() {

	if (length == 0)
		return;

	SNode* temp = top;
	while (temp != nullptr)
	{
		std::cout << temp->GetValue() << std::endl;
		temp = temp->GetNextNode();
	}
	return;
}