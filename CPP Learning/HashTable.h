#pragma once
#include<iostream>
#include<vector>

class HNode;

class HashTable {

private:
	static const int SIZE{ 7 };
	HNode* dataMap[SIZE];

	int Hash(std::string key);

public:
	void PrintTable();
	void Set(std::string key, int value);
	HNode* Get(std::string key);
	std::vector<std::string> Keys();

};

class HNode {
	
public:
	std::string key;
	int value;
	HNode* next;

	HNode(std::string key, int value) {
		this->key = key;
		this->value = value;
		next = nullptr;
	}
};