#pragma once
#include<iostream>
#include<unordered_map>
#include<unordered_set>

class Graph {

	std::unordered_map<std::string, std::unordered_set<std::string>> adjList;

public:
	void PrintGraph();
	bool AddVertex(std::string v);
	bool AddEdge(std::string a, std::string b);
	bool RemoveEdge(std::string a, std::string b);
	bool RemoveVertex(std::string a);
};
