#pragma once
#include <vector>
#include <list>

// A class to represent a graph. A graph is a array of adjacency lists.
// Size of vector will be nodeNumber (number of vertices in graph)
class Graph
{
public:
	Graph(const int nodeNumber);
	~Graph();
	void addEdge(int src, int dest);
	void printGraph() const; 	// A utility function to print the adjacenncy list representation of graph
	const std::list<int>* getNodeList() const;
	const int getNodeCount() const;
private:
	int numberOfNodes;
	std::list<int> *adj;
};
