#include"HashTable.h"

void HashTable::PrintTable() {

	for (size_t i = 0; i < SIZE; i++)
	{
		if (dataMap[i]== nullptr)
			continue;
		
		HNode* temp = dataMap[i];
		std::cout << i << ": ";
		while (temp != nullptr)
		{
			std::cout << "{" << temp->key << "," << temp->value <<"},";
			temp = temp->next;
		}

		std::cout << std::endl;
	}
}

int HashTable::Hash(std::string str) {
	
	int hash{ 0 };
	for (int  i = 0; i < str.length(); i++)
	{
		int asciValue = int(str[i]);
		hash = (hash + asciValue * 23) % SIZE;
	}

	return hash;
}
  
void HashTable::Set(std::string skey, int value) {

	int key = Hash(skey);
	HNode* newNode = new HNode(skey, value);

	if (dataMap[key] == nullptr)
	{
		dataMap[key] = newNode;
	}
	else {
		HNode* temp = dataMap[key];
		while (temp->next != nullptr) {
			temp = temp->next;
		}
		temp->next = newNode;
	}
}

HNode* HashTable::Get(std::string skey) {

	int key = Hash(skey);

	HNode* temp = dataMap[key];
	while (temp->key.compare(skey) != 0) {
		temp = temp->next;
	}

	return temp;
}

std::vector<std::string> HashTable::Keys() {

	std::vector<std::string> result;
	
	for (auto i : dataMap) {
		if (i != nullptr)
		{
			HNode* temp = i;
			while (temp!= nullptr)
			{
				result.push_back(temp->key);
				temp = temp->next;
			}
		}
	}

	return result;
}