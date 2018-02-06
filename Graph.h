/****************************
* @Author: Berkay Elbir
**************************/

#pragma once
#include <vector>
#include <list>

// A class to represent a graph. A graph is a array of adjacency lists.
// Size of list will be nodeNumber (number of vertices in graph)
class Graph
{
public:
	Graph(const int nodeNumber);
	~Graph();
	Graph(Graph& other);
	Graph(Graph&& other);
	Graph& operator=(Graph& other);
	Graph& operator=(Graph&& other);
	void addEdge(int src, int dest);
	void printGraph() const; 	// A utility function to print the adjacency list representation of graph
	const std::list<int>* getNodeList() const;
	const int getNodeCount() const;
private:
	void copyListFrom(Graph& other);
private:
	int numberOfNodes;
	std::list<int>* adj;
};
