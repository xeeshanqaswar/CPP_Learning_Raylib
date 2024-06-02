#include"Graph.h"

bool Graph::AddVertex(std::string vertex) {
	if (adjList.count(vertex) == 0)
	{
		adjList[vertex];
		return true;
	}

	return false;
}

bool Graph::AddEdge(std::string a, std::string b) {

	if (adjList.count(a) != 0 && adjList.count(b) != 0)
	{
		adjList.at(a).insert(b);
		adjList.at(b).insert(a);
		return true;
	}
	return false;
}

bool Graph::RemoveEdge(std::string a, std::string b) {
	if (adjList.count(a) != 0 && adjList.count(b) != 0)
	{
		adjList.at(a).erase(b);
		adjList.at(b).erase(a);
		return true;
	}

	return false;
}

bool Graph::RemoveVertex(std::string a) {
	if (adjList.count(a) != 0)
	{
		for (auto b : adjList.at(a)) {
			adjList.at(b).erase(a);
		}

		adjList.erase(a);
		return true;
	}

	return false;
}

void Graph::PrintGraph() {

	for (auto k : adjList) {
		std::cout << k.first << " [ ";
		for (auto v : k.second) {
			std::cout << v << ", ";
		}
		std::cout << " ]" << std::endl;
	}
}